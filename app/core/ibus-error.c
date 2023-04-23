//
// Created by dingjing on 23-4-23.
//

#include "ibus-error.h"

#include <gio/gio.h>
#include "ibus-types.h"

static const GDBusErrorEntry ibus_error_entries[] =
    {
        { IBUS_ERROR_NO_ENGINE, "org.freedesktop.IBus.Error.NoEngine" },
    };

GQuark ibus_error_quark (void)
{
    static volatile gsize quark_volatile = 0;

    g_dbus_error_register_error_domain ("ibus-error-quark", &quark_volatile, ibus_error_entries, G_N_ELEMENTS (ibus_error_entries));

    return (GQuark) quark_volatile;
}
