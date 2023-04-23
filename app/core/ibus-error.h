//
// Created by dingjing on 23-4-23.
//

#if !defined (__IBUS_H_INSIDE__) && !defined (IBUS_COMPILATION)
#error "Only <ibus.h> can be included directly"
#endif

#ifndef GRACEFUL_IBUS_IBUS_ERROR_H
#define GRACEFUL_IBUS_IBUS_ERROR_H

/**
 * SECTION: ibuserror
 * @short_description: Error functions and definition.
 * @stability: Stable
 *
 * This file defines some error functions and definition.
 */

#include <glib.h>

G_BEGIN_DECLS

#define IBUS_ERROR ibus_error_quark()
GQuark ibus_error_quark (void);

G_END_DECLS

#endif //GRACEFUL_IBUS_IBUS_ERROR_H
