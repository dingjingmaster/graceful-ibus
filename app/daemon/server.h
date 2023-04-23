//
// Created by dingjing on 23-4-23.
//

#ifndef GRACEFUL_IBUS_SERVER_H
#define GRACEFUL_IBUS_SERVER_H
#include "ibus.h"

G_BEGIN_DECLS

void bus_server_init (void);
void bus_server_run (void);
void bus_server_quit (gboolean restart);
const gchar *bus_server_get_address (void);

G_END_DECLS

#endif //GRACEFUL_IBUS_SERVER_H
