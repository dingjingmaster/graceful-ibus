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
#include "ibus-property.h"
#include "ibus-component.h"
#include "ibus-attribute.h"
#include "ibus-engine-desc.h"
#include "ibus-lookup-table.h"
#include "ibus-property-list.h"
#include "ibus-attribute-list.h"
/* ibus core -- end */

#include "ibusservice.h"
#include "ibusfactory.h"
#include "ibusengine.h"
#include "ibusenginesimple.h"
#include "ibuskeysyms.h"
#include "ibuskeymap.h"
#include "ibuskeys.h"
#include "ibusenumtypes.h"
#include "ibushotkey.h"
#include "ibusconfigservice.h"
#include "ibuspanelservice.h"
#include "ibusutil.h"
#include "ibusregistry.h"
#include "ibusemoji.h"
#include "ibusxevent.h"
#include "ibusaccelgroup.h"
#include "ibus-serializable.h"

#ifndef IBUS_DISABLE_DEPRECATED
#include "ibuskeysyms-compat.h"
#include "ibus-observed-path.h"
#endif

#undef __IBUS_H_INSIDE__

#endif //GRACEFUL_IBUS_IBUS_H
