//
// Created by dingjing on 23-4-21.
//

#ifndef GRACEFUL_IBUS_IBUS_MAIN_H
#define GRACEFUL_IBUS_IBUS_MAIN_H

#if !defined (__IBUS_H_INSIDE__) && !defined (IBUS_COMPILATION)
#error "Only <ibus.h> can be included directly"
#endif
#include <glib.h>

#ifdef IBUS_DISABLE_DEPRECATION_WARNINGS
#define IBUS_DEPRECATED
#else
#define IBUS_DEPRECATED G_DEPRECATED
#endif

#define IBUS_SERVICE_IBUS                       "org.freedesktop.IBus"
#define IBUS_SERVICE_PORTAL                     "org.freedesktop.portal.IBus"
#define IBUS_SERVICE_PANEL                      "org.freedesktop.IBus.Panel"
#define IBUS_SERVICE_PANEL_EXTENSION            "org.freedesktop.IBus.Panel.Extension"
#define IBUS_SERVICE_PANEL_EXTENSION_EMOJI      "org.freedesktop.IBus.Panel.Extension.Emoji"
#define IBUS_SERVICE_CONFIG                     "org.freedesktop.IBus.Config"
#define IBUS_SERVICE_NOTIFICATIONS              "org.freedesktop.IBus.Notifications"

#define IBUS_PATH_IBUS                          "/org/freedesktop/IBus"
#define IBUS_PATH_FACTORY                       "/org/freedesktop/IBus/Factory"
#define IBUS_PATH_PANEL                         "/org/freedesktop/IBus/Panel"
#define IBUS_PATH_PANEL_EXTENSION_EMOJI         "/org/freedesktop/IBus/Panel/Extension/Emoji"
#define IBUS_PATH_CONFIG                        "/org/freedesktop/IBus/Config"
#define IBUS_PATH_NOTIFICATIONS                 "/org/freedesktop/IBus/Notifications"
#define IBUS_PATH_INPUT_CONTEXT                 "/org/freedesktop/IBus/InputContext_%d"

#define IBUS_INTERFACE_IBUS                     "org.freedesktop.IBus"
#define IBUS_INTERFACE_PORTAL                   "org.freedesktop.IBus.Portal"
#define IBUS_INTERFACE_INPUT_CONTEXT            "org.freedesktop.IBus.InputContext"
#define IBUS_INTERFACE_FACTORY                  "org.freedesktop.IBus.Factory"
#define IBUS_INTERFACE_ENGINE                   "org.freedesktop.IBus.Engine"
#define IBUS_INTERFACE_PANEL                    "org.freedesktop.IBus.Panel"
#define IBUS_INTERFACE_CONFIG                   "org.freedesktop.IBus.Config"
#define IBUS_INTERFACE_NOTIFICATIONS            "org.freedesktop.IBus.Notifications"

G_BEGIN_DECLS

const gchar*        ibus_get_local_machine_id       (void);
void                ibus_set_display                (const gchar* display);
const gchar*        ibus_get_address                (void);
void                ibus_write_address              (const gchar* address);
const gchar*        ibus_get_user_name              (void);
glong               ibus_get_daemon_uid             (void) G_GNUC_DEPRECATED;
const gchar*        ibus_get_socket_path            (void);
gint                ibus_get_timeout                (void);
void                ibus_init                       (void);
void                ibus_main                       (void);
void                ibus_quit                       (void);
void                ibus_unset_log_handler          (void);
void                ibus_set_log_handler            (gboolean verbose);
void                ibus_free_strv                  (gchar** strv) G_GNUC_DEPRECATED;
gchar*              ibus_key_event_to_string        (guint keyval, guint modifiers);
gboolean            ibus_key_event_from_string      (const gchar* string, guint* keyval, guint* modifiers);

G_END_DECLS

#endif //GRACEFUL_IBUS_IBUS_MAIN_H
