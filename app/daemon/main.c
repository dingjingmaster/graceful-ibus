/* -*- mode: C; c-basic-offset: 4; indent-tabs-mode: nil; -*- */
/* vim:set et sts=4: */
/* ibus - The Input Bus
 * Copyright (C) 2008-2013 Peng Huang <shawn.p.huang@gmail.com>
 * Copyright (C) 2013-2018 Takao Fujiwara <takao.fujiwara1@gmail.com>
 * Copyright (C) 2008-2018 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
 * USA
 */
#include <pwd.h>
#include <glib.h>
#include <ibus.h>
#include <fcntl.h>
#include <config.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <gio/gio.h>
#include <sys/stat.h>
#include <sys/types.h>

#ifdef HAVE_SYS_PRCTL_H
/* 获取进程相关信息 */
#include <sys/prctl.h>
#endif

#include <glib/gi18n.h>

#include "server.h"
#include "ibusimpl.h"
#include "../common/gi-global.h"
#include "../common/ibus-functions.h"


static void show_version_and_quit (void);
static gboolean execute_cmdline (const gchar* cmdline);


static gboolean         daemonize = FALSE;
static gboolean         single = FALSE;
static gboolean         xim = FALSE;
static gboolean         replace = FALSE;
static gboolean         restart = FALSE;
static gchar*           panel = "default";
static gchar*           config = "default";
static gchar*           desktop = "gnome";
static gchar*           gEmojiExtension = "default";

const char*             gLogPath = "/tmp/" INSTALL_NAME ".log";

static gchar* gPanelExtensionDisableUsers[] =
{
    "gdm",
    "gnome-initial-setup",
    "liveuser"
};

static const GOptionEntry gEntries[] =
{
    { "version", 'V',   G_OPTION_FLAG_NO_ARG, G_OPTION_ARG_CALLBACK, show_version_and_quit, "Show the application's version.", NULL },
    { "daemonize", 'd', 0, G_OPTION_ARG_NONE,   &daemonize, "run ibus as background process.", NULL },
    { "single", 's',    0, G_OPTION_ARG_NONE,   &single,    "do not execute panel and config module.", NULL },
    { "xim", 'x',       0, G_OPTION_ARG_NONE,   &xim,       "execute ibus XIM server.", NULL },
    { "desktop", 'n',   0, G_OPTION_ARG_STRING, &desktop,   "specify the name of desktop session. [default=gnome]", "name" },
    { "panel", 'p',     0, G_OPTION_ARG_STRING, &panel,     "specify the cmdline of panel program. pass 'disable' not to start a panel program.", "cmdline" },
    { "emoji-extension", 'E', 0, G_OPTION_ARG_STRING, &gEmojiExtension, "specify the cmdline of emoji extension program. pass 'disable' not to start an extension program.", "cmdline" },
    { "config", 'c',    0, G_OPTION_ARG_STRING, &config,    "specify the cmdline of config program. pass 'disable' not to start a config program.", "cmdline" },
    { "address", 'a',   0, G_OPTION_ARG_STRING, &gAddress,   "specify the address of ibus daemon.", "address" },
    { "replace", 'r',   0, G_OPTION_ARG_NONE,   &replace,   "if there is an old ibus-daemon is running, it will be replaced.", NULL },
    { "cache", 't',     0, G_OPTION_ARG_STRING, &gCache,   "specify the cache mode. [auto/refresh/none]", NULL },
    { "timeout", 'o',   0, G_OPTION_ARG_INT,    &gDBusTimeout, "gdbus reply timeout in milliseconds. pass -1 to use the default timeout of gdbus.", "timeout [default is 15000]" },
    { "mem-profile", 'm', 0, G_OPTION_ARG_NONE, &gMemPro,   "enable memory profile, send SIGUSR2 to print out the memory profile.", NULL },
    { "restart", 'R',   0, G_OPTION_ARG_NONE,   &restart,    "restart panel and config processes when they die.", NULL },
    { "verbose", 'v',   0, G_OPTION_ARG_NONE,   &gVerbose,   "verbose.", NULL },
    { NULL },
};


int main (int argc, char* argv[])
{
    int i;
    const gchar *username = ibus_get_user_name ();

    textdomain (GETTEXT_PACKAGE);
    bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
    bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
    g_log_set_writer_func (log_handler, NULL, NULL);

    GOptionContext *context = g_option_context_new ("- ibus daemon");
    g_option_context_add_main_entries (context, gEntries, "ibus-daemon");

    gArgv = g_strdupv (argv);
    GError *error = NULL;
    if (!g_option_context_parse (context, &argc, &argv, &error)) {
        g_printerr ("Option parsing failed: %s\n", error->message);
        g_error_free (error);
        exit (-1);
    }

    if (gDBusTimeout < -1) {
        g_printerr ("Bad timeout (must be >= -1): %d\n", gDBusTimeout);
        exit (-1);
    }

    if (gMemPro) {
        g_warning ("--mem-profile no longer works with the GLib 2.46 or later");
    }

    /* 检查用户是否使用 su 或 sudo 执行 */
    {
        struct passwd* pwd = getpwuid (getuid ());
        if (pwd == NULL || g_strcmp0 (pwd->pw_name, username) != 0) {
            g_printerr ("Please run ibus-daemon with login user! Do not run ibus-daemon with sudo or su.\n");
            exit (-1);
        }
    }

    /* 使进程变为守护进程 */
    if (daemonize) {
        if (daemon (1, 0) != 0) {
            g_printerr ("Cannot daemonize ibus.\n");
            exit (-1);
        }
    }

    /* create a new process group. this is important to kill all of its children by SIGTERM at a time in bus_ibus_impl_destroy. */
    setpgid (0, 0);

    ibus_init ();

    /* TODO:// 此处替换新的日志处理库 */
//    ibus_set_log_handler (gVerbose);

    /* check if ibus-daemon is running in this session */
    /* TODO:// 此处用glib替换 */
    if (ibus_get_address () != NULL) {
        IBusBus *bus = ibus_bus_new ();

        if (ibus_bus_is_connected (bus)) {
            if (!replace) {
                g_printerr ("current session already has an ibus-daemon.\n");
                exit (-1);
            }
            ibus_bus_exit (bus, FALSE);
            while (ibus_bus_is_connected (bus)) {
                g_main_context_iteration (NULL, TRUE);
            }
        }
        g_object_unref (bus);
    }

    LOG_INFO("ibus-daemon starting...");

    bus_server_init ();
    for (i = 0; i < G_N_ELEMENTS(gPanelExtensionDisableUsers); i++) {
        if (!g_strcmp0 (username, gPanelExtensionDisableUsers[i]) != 0) {
            gEmojiExtension = "disable";
            break;
        }
    }

    if (!single) {
        /* execute config component */
        if (g_strcmp0 (config, "default") == 0) {
            BusComponent *component;
            component = bus_ibus_impl_lookup_component_by_name(BUS_DEFAULT_IBUS, IBUS_SERVICE_CONFIG);
            if (component) {
                bus_component_set_restart (component, restart);
            }
            if (component == NULL || !bus_component_start (component, gVerbose)) {
                g_printerr ("Can not execute default config program\n");
                exit (-1);
            }
        } else if (g_strcmp0 (config, "disable") != 0 && g_strcmp0 (config, "") != 0) {
            if (!execute_cmdline (config))
                exit (-1);
        }

        /* execute panel component */
        if (g_strcmp0 (panel, "default") == 0) {
            BusComponent *component;
            component = bus_ibus_impl_lookup_component_by_name(BUS_DEFAULT_IBUS, IBUS_SERVICE_PANEL);
            if (component) {
                bus_component_set_restart (component, restart);
            }
            if (component == NULL || !bus_component_start (component, gVerbose)) {
                g_printerr ("Can not execute default panel program\n");
                exit (-1);
            }
        } else if (g_strcmp0 (panel, "disable") != 0 && g_strcmp0 (panel, "") != 0) {
            if (!execute_cmdline (panel))
                exit (-1);
        }
    }

#ifdef EMOJI_DICT
    if (g_strcmp0 (emoji_extension, "default") == 0) {
        BusComponent *component;
        component = bus_ibus_impl_lookup_component_by_name (
                BUS_DEFAULT_IBUS, IBUS_SERVICE_PANEL_EXTENSION);
        if (component) {
            bus_component_set_restart (component, restart);
        }
        if (component != NULL &&
            !bus_component_start (component, g_verbose)) {
            g_printerr ("Can not execute default panel program\n");
            exit (-1);
        }
    } else if (g_strcmp0 (emoji_extension, "disable") != 0 &&
               g_strcmp0 (emoji_extension, "") != 0) {
        if (!execute_cmdline (emoji_extension))
            exit (-1);
    }
#endif

    /* execute ibus xim server */
    if (xim) {
        if (!execute_cmdline (LIBEXECDIR "/ibus-x11 --kill-daemon")) {
            exit (-1);
        }
    }

    if (!daemonize) {
        if (getppid () == 1) {
            g_warning ("The parent process died.");
            exit (0);
        }
#ifdef HAVE_SYS_PRCTL_H
       /* Currently ibus-x11 detects XIOError and assume the error as the
        * desktop session is closed and ibus-x11 calls Exit D-Bus method to
        * exit ibus-daemon. But a few desktop sessions cause XError before
        * XIOError and GTK does not allow to bind XError by applications and
        * GTK calls gdk_x_error() with XError.
        *
        * E.g. GdkX11Screen calls XGetSelectionOwner() for "_XSETTINGS_S?"
        * atoms during the logout but the selection owner already becomes
        * NULL and the NULL window causes XError with
        * gdk_x11_window_foreign_new_for_display().
        *
        * Since ibus-x11 exits with XError before XIOError, gnome-shell
        * can detects the exit of ibus-daemon a little earlier and
        * gnome-shell restarts ibus-daemon but gnome-shell dies soon.
        * Then gnome-shell dies but ibus-daemon is alive, it's a problem.
        * Because it causes double ibus-x11 of GDM and a login user
        * and double XSetSelectionOwner() is not allowed for the unique
        * "ibus" atom and the user cannot use XIM but not GtkIMModule.
        *
        * Probably we could fix the ibus process problem if we would fix
        * XError about the X selection owner or stop to restart ibus-daemon
        * in gonme-shell when the session is logging out.
        * Maybe using SessionManager.LogoutRemote() or
        * global.screen.get_display().get_xdisplay()
        * But I assume there are other scenarios to cause the problem.
        *
        * And I decided ibus-daemon always exits with the parent's death here
        * to avoid unexpected ibus restarts during the logout.
        */
        if (prctl (PR_SET_PDEATHSIG, SIGUSR1)) {
            g_printerr ("Cannot bind SIGUSR1 for parent death\n");
        }
        else {
            signal (SIGUSR1, _sig_usr1_handler);
        }
#endif
    }

    bus_server_run ();

    return 0;
}


/**
 * execute_cmdline:
 * @cmdline: An absolute path of the executable and its parameters, e.g.  "/usr/lib/ibus/ibus-x11 --kill-daemon".
 * @returns: TRUE if both parsing cmdline and executing the command succeed.
 *
 * Execute cmdline. Child process's stdin, stdout, and stderr are attached to /dev/null.
 * You don't have to handle SIGCHLD from the child process since glib will do.
 */
static gboolean execute_cmdline (const gchar *cmdline)
{
    g_assert (cmdline);

    gint argc = 0;
    gchar **argv = NULL;
    GError *error = NULL;
    if (!g_shell_parse_argv (cmdline, &argc, &argv, &error)) {
        g_warning ("Can not parse cmdline `%s` exec: %s", cmdline, error->message);
        g_error_free (error);
        return FALSE;
    }

    error = NULL;
    gboolean retval = g_spawn_async (NULL, argv, NULL,
                                     G_SPAWN_STDOUT_TO_DEV_NULL | G_SPAWN_STDERR_TO_DEV_NULL,
                                     NULL, NULL,
                                     NULL, &error);
    g_strfreev (argv);

    if (!retval) {
        g_warning ("Can not execute cmdline `%s`: %s", cmdline, error->message);
        g_error_free (error);
        return FALSE;
    }

    return TRUE;
}

static void show_version_and_quit (void)
{
    g_print ("%s - Version %s\n", g_get_application_name(), VERSION);
    exit (EXIT_SUCCESS);
}
