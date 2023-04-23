
#if !defined (__IBUS_H_INSIDE__) && !defined (IBUS_COMPILATION)
#error "Only <ibus.h> can be included directly"
#endif

#ifndef __IBUS_DEBUG_H_
#define __IBUS_DEBUG_H_

#include "ibus-log.h"

#define ibus_warning(msg, args...)      LOG_WARNING(msg, ##args)

#endif

