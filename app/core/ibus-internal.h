//
// Created by dingjing on 23-4-23.
//

#if !defined (__IBUS_H_INSIDE__) && !defined (IBUS_COMPILATION)
#error "Only <ibus.h> can be included directly"
#endif

#ifndef GRACEFUL_IBUS_IBUS_INTERNAL_H
#define GRACEFUL_IBUS_IBUS_INTERNAL_H


#include <glib.h>
/**
 * I_:
 * @string: A string
 * @returns: The canonical representation for the string.
 *
 * Returns a canonical representation for string.
 * Interned strings can be compared for equality by comparing the pointers, instead of using strcmp().
 */
#define I_(string) g_intern_static_string (string)

/**
 * DBUS_SERVICE_DBUS:
 *
 * Address of D-Bus service.
 */
#define DBUS_SERVICE_DBUS "org.freedesktop.DBus"

/**
 * DBUS_PATH_DBUS:
 *
 * D-Bus path for D-Bus.
 */
#define DBUS_PATH_DBUS "/org/freedesktop/DBus"

/**
 * DBUS_INTERFACE_DBUS:
 *
 * D-Bus interface for D-Bus.
 */
#define DBUS_INTERFACE_DBUS "org.freedesktop.DBus"

G_GNUC_INTERNAL void ibus_g_variant_get_child_string (GVariant *variant, gsize index, char **str);

#endif //GRACEFUL_IBUS_IBUS_INTERNAL_H
