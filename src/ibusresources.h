#ifndef __RESOURCE__ibus_H__
#define __RESOURCE__ibus_H__

#include <gio/gio.h>

G_GNUC_INTERNAL GResource *_ibus_get_resource (void);

G_GNUC_INTERNAL void _ibus_register_resource (void);
G_GNUC_INTERNAL void _ibus_unregister_resource (void);

#endif
