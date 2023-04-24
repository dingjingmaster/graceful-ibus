//
// Created by dingjing on 23-4-24.
//

#ifndef GRACEFUL_IBUS_IBUS_ENGINE_SIMPLE_PRIVATE_H
#define GRACEFUL_IBUS_IBUS_ENGINE_SIMPLE_PRIVATE_H

#include <glib.h>


G_BEGIN_DECLS

/* Checks if a keysym is a dead key. Dead key keysym values are defined in
 * ibuskeysyms.h and the first is GDK_KEY_dead_grave.
 */
#define IS_DEAD_KEY(k) \
      ((k) >= IBUS_KEY_dead_grave && (k) <= IBUS_KEY_dead_greek)


struct _IBusComposeTablePrivate
{
    const guint16 *data_first;
    const guint32 *data_second;
    gsize first_n_seqs;
    gsize second_size;
};


gboolean ibus_check_algorithmically (const guint16              *compose_buffer,
                                     int                         n_compose,
                                     gunichar                   *output);
GVariant *
ibus_compose_table_serialize
    (IBusComposeTableEx
     *compose_table,
     gboolean                   reverse_endian);
IBusComposeTableEx *
ibus_compose_table_deserialize
    (const char                 *contents,
     gsize                       length,
     gboolean                   reverse_endian);
gboolean ibus_compose_table_check   (const IBusComposeTableEx   *table,
                                     guint16                    *compose_buffer,
                                     int                         n_compose,
                                     gboolean                   *compose_finish,
                                     gboolean                   *compose_match,
                                     GString                    *output,
                                     gboolean                    is_32bit);
gunichar ibus_keysym_to_unicode     (guint16                     keysym,
                                     gboolean                    combining,
                                     gboolean                   *need_space);

G_END_DECLS

#endif //GRACEFUL_IBUS_IBUS_ENGINE_SIMPLE_PRIVATE_H
