//
// Created by dingjing on 23-4-21.
//

#ifndef GRACEFUL_IBUS_IBUS_H
#define GRACEFUL_IBUS_IBUS_H

#define __IBUS_H_INSIDE__

/* ibus core -- start */
#include "ibus-xml.h"
#include "ibus-log.h"
#include "ibus-bus.h"
#include "ibus-text.h"
#include "ibus-main.h"
#include "ibus-proxy.h"
#include "ibus-error.h"
#include "ibus-config.h"
#include "ibus-object.h"
#include "ibus-unicode.h"
#include "ibus-version.h"
#include "ibus-service.h"
#include "ibus-property.h"
#include "ibus-component.h"
#include "ibus-attribute.h"
#include "ibus-engine-desc.h"
#include "ibus-lookup-table.h"
#include "ibus-property-list.h"
#include "ibus-attribute-list.h"
/* ibus core -- end */

#include "ibus-keys.h"
#include "ibus-util.h"
#include "ibus-emoji.h"
#include "ibus-engine.h"
#include "ibus-xevent.h"
#include "ibus-factory.h"
#include "ibus-key-map.h"
#include "ibus-hot-key.h"
#include "ibus-registry.h"
#include "ibus-key-syms.h"
#include "ibus-accel-group.h"
#include "ibus-serializable.h"
#include "ibus-engine-simple.h"
#include "ibus-panel-service.h"
#include "ibus-config-service.h"

#include "ibusenumtypes.h"

#ifndef IBUS_DISABLE_DEPRECATED
#include "ibus-observed-path.h"
#include "ibus-key-syms-compat.h"
#endif

#undef __IBUS_H_INSIDE__

#endif //GRACEFUL_IBUS_IBUS_H
