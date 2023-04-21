//
// Created by dingjing on 23-4-20.
//

#ifndef GRACEFUL_IBUS_GI_GLOBAL_H
#define GRACEFUL_IBUS_GI_GLOBAL_H
#include <stdlib.h>
#include <stdbool.h>

#include "config.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DEFAULT_ENGINE "xkb:us::eng"

static char**               gArgv = NULL;
static char*                gAddress = IBUS_SOCKET_DIR;
static char*                gCache = "auto";
static bool                 gMemPro = false;
static bool                 gVerbose = false;
static int                  gDBusTimeout = 15000;

#ifdef __cplusplus
}
#endif

#endif //GRACEFUL_IBUS_GI_GLOBAL_H
