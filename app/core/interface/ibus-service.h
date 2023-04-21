//
// Created by dingjing on 23-4-21.
//

#if !defined (__IBUS_H_INSIDE__) && !defined (IBUS_COMPILATION)
#error "Only <ibus.h> can be included directly"
#endif

#ifndef GRACEFUL_IBUS_IBUS_SERVICE_H
#define GRACEFUL_IBUS_IBUS_SERVICE_H
#include <gio/gio.h>
#include "ibus-object.h"

#define IBUS_TYPE_SERVICE               (ibus_service_get_type())
#define IBUS_SERVICE(obj)               (G_TYPE_CHECK_INSTANCE_CAST((obj), IBUS_TYPE_SERVICE, IBusService))
#define IBUS_SERVICE_CLASS(klass)       (G_TYPE_CHECK_CLASS_CAST((klass), IBUS_TYPE_SERVICE, IBusServiceClass))
#define IBUS_IS_SERVICE(obj)            (G_TYPE_CHECK_INSTANCE_TYPE((obj), IBUS_TYPE_SERVICE))
#define IBUS_IS_SERVICE_CLASS(klass)    (G_TYPE_CHECK_CLASS_TYPE((klass), IBUS_TYPE_SERVICE))
#define IBUS_SERVICE_GET_CLASS(obj)     (G_TYPE_INSTANCE_GET_CLASS ((obj), IBUS_TYPE_SERVICE, IBusServiceClass))

G_BEGIN_DECLS
typedef struct _IBusService             IBusService;
typedef struct _IBusServiceClass        IBusServiceClass;
typedef struct _IBusServicePrivate      IBusServicePrivate;

struct _IBusService
{
    IBusObject                  parent;
    IBusServicePrivate*         priv;
};

struct _IBusServiceClass
{
    IBusObjectClass                     parent;

    void (*service_method_call)         (IBusService* service, GDBusConnection* conn, const gchar* sender, const gchar* objPath, const gchar* ifaceName, const gchar* methodName, GVariant* params, GDBusMethodInvocation* inv);
    GVariant* (*service_get_property)   (IBusService* service, GDBusConnection* conn, const gchar* sender, const gchar* objPath, const gchar* ifaceName, const gchar* propName, GError** error);
    gboolean (*service_set_property)    (IBusService* service, GDBusConnection* conn, const gchar* sender, const gchar* objPath, const gchar* ifaceName, const gchar* propName, GVariant* value, GError** error);
    GArray* interfaces;
    gpointer pdummy[4];
};

GType               ibus_service_get_type               (void);
IBusService*        ibus_service_new                    (GDBusConnection* conn, const gchar* path);
const gchar*        ibus_service_get_object_path        (IBusService* service);
GDBusConnection*    ibus_service_get_connection         (IBusService* service);
gboolean            ibus_service_register               (IBusService* service, GDBusConnection* connection, GError** error);
void                ibus_service_unregister             (IBusService* service, GDBusConnection* conn);
gboolean            ibus_service_emit_signal            (IBusService* service, const gchar* destBusName, const gchar* ifaceName, const gchar* sigName, GVariant* params, GError** error);
gboolean            ibus_service_class_add_interfaces   (IBusServiceClass* klass, const gchar* xmlData);

G_END_DECLS

#endif //GRACEFUL_IBUS_IBUS_SERVICE_H
