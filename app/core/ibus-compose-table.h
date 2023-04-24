//
// Created by dingjing on 23-4-24.
//

#ifndef GRACEFUL_IBUS_IBUS_COMPOSE_TABLE_H
#define GRACEFUL_IBUS_IBUS_COMPOSE_TABLE_H

#include <glib.h>


G_BEGIN_DECLS

typedef struct _IBusComposeTable IBusComposeTable;
typedef struct _IBusComposeTableEx IBusComposeTableEx;
typedef struct _IBusComposeTablePrivate IBusComposeTablePrivate;
typedef struct _IBusComposeTableCompact IBusComposeTableCompact;
typedef struct _IBusComposeTableCompactEx IBusComposeTableCompactEx;
typedef struct _IBusComposeTableCompactPrivate IBusComposeTableCompactPrivate;

struct _IBusComposeTable
{
    guint16 *data;
    gint max_seq_len;
    gint n_seqs;
    guint32 id;
};

struct _IBusComposeTableEx
{
    IBusComposeTablePrivate *priv;
    /* @data is const value to accept mmap data and the releasable allocation
     * is assigned to @rawdata. */
    const guint16 *data;
    gint max_seq_len;
    gint n_seqs;
    guint32 id;
    char *rawdata;
};


/**
 * ibus_compose_table_new_with_file:
 * @compose_file: The path of the compose file
 * @compose_tables: (nullable): The list of other @IBusComposeTableEx
 * and the generating @IBusComposeTableEx excludes the compose keys
 * which are included in the other @IBusComposeTableEx.
 *
 * Generate @IBusComposeTableEx from the compose file.
 *
 * Returns: @IBusComposeTableEx
 */
IBusComposeTableEx *
ibus_compose_table_new_with_file (const gchar *compose_file,
                                  GSList
                                  *compose_tables);
IBusComposeTableEx *
ibus_compose_table_load_cache    (const gchar *compose_file);
void              ibus_compose_table_save_cache    (IBusComposeTableEx
                                                    *compose_table);
GSList *          ibus_compose_table_list_add_array
    (GSList
     *compose_tables,
     const guint16
     *data,
     gint         max_seq_len,
     gint         n_seqs);
GSList *          ibus_compose_table_list_add_file (GSList
                                                    *compose_tables,
                                                    const gchar *compose_file);
GSList *          ibus_compose_table_list_add_table (GSList
                                                     *compose_tables,
                                                     IBusComposeTableEx
                                                     *compose_table);

G_BEGIN_DECLS


#endif //GRACEFUL_IBUS_IBUS_COMPOSE_TABLE_H
