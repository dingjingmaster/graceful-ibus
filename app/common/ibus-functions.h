//
// Created by dingjing on 23-4-20.
//

#ifndef GRACEFUL_IBUS_IBUS_FUNCTIONS_H
#define GRACEFUL_IBUS_IBUS_FUNCTIONS_H

#ifndef HAVE_DAEMON
static void closeall (gint fd)
{
    gint fdlimit = sysconf(_SC_OPEN_MAX);

    while (fd < fdlimit) {
        close(fd++);
    }
}

static gint daemon (gint nochdir, gint noclose)
{
    switch (fork()) {
        case 0:  break;
        case -1: return -1;
        default: _exit(0);
    }

    if (setsid() < 0) {
        return -1;
    }

    switch (fork()) {
        case 0:  break;
        case -1: return -1;
        default: _exit(0);
    }

    if (!nochdir) {
        chdir("/");
    }

    if (!noclose) {
        closeall(0);
        open("/dev/null",O_RDWR);
        dup(0); dup(0);
    }
    return 0;
}
#endif

#ifdef HAVE_SYS_PRCTL_H
static void _sig_usr1_handler (int sig G_GNUC_UNUSED)
{
    g_warning ("The parent process died.");
    bus_server_quit (FALSE);
}
#endif
#endif //GRACEFUL_IBUS_IBUS_FUNCTIONS_H
