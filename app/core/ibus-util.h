//
// Created by dingjing on 23-4-24.
//
#if !defined (__IBUS_H_INSIDE__) && !defined (IBUS_COMPILATION)
#error "Only <ibus.h> can be included directly"
#endif

#ifndef GRACEFUL_IBUS_IBUS_UTIL_H
#define GRACEFUL_IBUS_IBUS_UTIL_H
#include <glib.h>

/**
 * SECTION: ibusutil
 * @short_description: Utilities with C-Language.
 * @stability: Unstable
 *
 * Utilized functions are available for miscellaneous purposes.
 */

/**
 * ibus_get_untranslated_language_name:
 * @_locale: A const locale name.
 *
 * Returns: untranslated language name
 */
gchar *          ibus_get_untranslated_language_name
    (const gchar    *_locale);

/**
 * ibus_get_language_name:
 * @_locale: A const locale name.
 *
 * Returns: translated language name
 */
gchar *          ibus_get_language_name         (const gchar    *_locale);


#endif //GRACEFUL_IBUS_IBUS_UTIL_H
