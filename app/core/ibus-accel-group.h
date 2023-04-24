//
// Created by dingjing on 23-4-24.
//

#if !defined (__IBUS_H_INSIDE__) && !defined (IBUS_COMPILATION)
#error "Only <ibus.h> can be included directly"
#endif

#ifndef GRACEFUL_IBUS_IBUS_ACCEL_GROUP_H
#define GRACEFUL_IBUS_IBUS_ACCEL_GROUP_H


#include <glib.h>
#include "ibus-types.h"

G_BEGIN_DECLS


/* --- Accelerators--- */
gboolean ibus_accelerator_valid               (guint            keyval,
                                               IBusModifierType modifiers)
G_GNUC_CONST;
void     ibus_accelerator_parse               (const gchar      *accelerator,
                                               guint            *accelerator_key,
                                               IBusModifierType *accelerator_mods);
gchar*   ibus_accelerator_name                (guint            accelerator_key,
                                               IBusModifierType accelerator_mods);

G_END_DECLS



#endif //GRACEFUL_IBUS_IBUS_ACCEL_GROUP_H
