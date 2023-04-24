//
// Created by dingjing on 23-4-21.
//

#include "ibus-object.h"

#include "ibus-marshal.h"

#define IBUS_OBJECT_GET_PRIVATE(o)      ((IBusObjectPrivate*) ibus_object_get_instance_private(o))

enum
{
    DESTROY = 0,
    LAST_SIGNAL,
};

struct _IBusObjectPrivate
{
    gpointer            pad;
};

static guint            gObjectSignals[LAST_SIGNAL] = {0};

static GObject*     ibus_object_constructor     (GType type, guint n, GObjectConstructParam* args);
static void         ibus_object_dispose         (IBusObject* obj);
static void         ibus_object_finalize        (IBusObject* obj);
static void         ibus_object_real_destroy    (IBusObject* obj);

G_DEFINE_TYPE_WITH_PRIVATE(IBusObject, ibus_object, G_TYPE_INITIALLY_UNOWNED)

static void ibus_object_class_init (IBusObjectClass* klass)
{
    GObjectClass* objClass = G_OBJECT_CLASS(klass);

    objClass->constructor = ibus_object_constructor;
    objClass->dispose = (GObjectFinalizeFunc) ibus_object_dispose;
    objClass->finalize = (GObjectFinalizeFunc) ibus_object_finalize;

    klass->destroy = ibus_object_real_destroy;

    gObjectSignals[DESTROY] = g_signal_new(g_intern_static_string("destroy"), G_TYPE_FROM_CLASS(objClass), G_SIGNAL_RUN_LAST,
                                           G_STRUCT_OFFSET(IBusObjectClass, destroy), NULL, NULL, _ibus_marshal_VOID__VOID, G_TYPE_NONE, 0);
}

static void ibus_object_init (IBusObject* obj)
{
    obj->flags = 0;
    obj->priv = IBUS_OBJECT_GET_PRIVATE(obj);
}

static GObject* ibus_object_constructor (GType type, guint n, GObjectConstructParam* args)
{
    GObject* obj = G_OBJECT_CLASS(ibus_object_parent_class)->constructor (type, n, args);

    return obj;
}

static void ibus_object_dispose (IBusObject* obj)
{
    if (!(IBUS_OBJECT_FLAGS(obj) & IBUS_IN_DESTRUCTION)) {
        IBUS_OBJECT_SET_FLAGS(obj, IBUS_IN_DESTRUCTION);
        if (!(IBUS_OBJECT_FLAGS(obj) & IBUS_DESTROYED)) {
            g_signal_emit (obj, gObjectSignals[DESTROY], 0);
            IBUS_OBJECT_SET_FLAGS(obj, IBUS_DESTROYED);
        }
        IBUS_OBJECT_UNSET_FLAGS(obj, IBUS_IN_DESTRUCTION);
    }

    G_OBJECT_CLASS(ibus_object_parent_class)->dispose(G_OBJECT(obj));
}

static void ibus_object_finalize (IBusObject* obj)
{
    G_OBJECT_CLASS(ibus_object_parent_class)->finalize(G_OBJECT(obj));
}

static void ibus_object_real_destroy (IBusObject* obj)
{
    g_signal_handlers_destroy(obj);
}

IBusObject* ibus_object_new (void)
{
    GObject* obj = g_object_new (IBUS_TYPE_OBJECT, NULL);

    return IBUS_OBJECT(obj);
}

void ibus_object_destroy (IBusObject* obj)
{
    g_return_if_fail(IBUS_OBJECT(obj));

    if (!(IBUS_OBJECT_FLAGS(obj) & IBUS_IN_DESTRUCTION)) {
        g_object_run_dispose (G_OBJECT(obj));
    }
}