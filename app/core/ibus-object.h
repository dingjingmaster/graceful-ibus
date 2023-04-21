//
// Created by dingjing on 23-4-21.
//

#if !defined (__IBUS_H_INSIDE__) && !defined (IBUS_COMPILATION)
#error "Only <ibus.h> can be included directly"
#endif

#ifndef GRACEFUL_IBUS_IBUS_OBJECT_H
#define GRACEFUL_IBUS_IBUS_OBJECT_H
#include <glib-object.h>

/**
 * @brief IBus中所有类型的基类 —— IBusObject
 */

#define IBUS_TYPE_OBJECT                (ibus_object_get_type())
#define IBUS_OBJECT(obj)                (G_TYPE_CHECK_INSTANCE_CAST((obj), IBUS_TYPE_OBJECT, IBusObject))
#define IBUS_OBJECT_CLASS(klass)        (G_TYPE_CHECK_CLASS_CAST((klass), IBUS_TYPE_OBJECT, IBusObjectClass))
#define IBUS_IS_OBJECT(obj)             (G_TYPE_CHECK_INSTANCE_TYPE((obj), IBUS_TYPE_OBJECT))
#define IBUS_IS_OBJECT_CLASS(klass)     (G_TYPE_CHECK_CLASS_TYPE((klass), IBUS_TYPE_OBJECT))
#define IBUS_OBJECT_GET_CLASS(obj)      (G_TYPE_INSTANCE_GET_CLASS((obj), IBUS_TYPE_OBJECT, IBusObjectClass))

#define IBUS_OBJECT_FLAGS(obj)              (IBUS_OBJECT(obj)->flags)
#define IBUS_OBJECT_SET_FLAGS(obj, flag)    G_STMT_START{(IBUS_OBJECT_FLAGS(obj) |= (flag));} G_STMT_END
#define IBUS_OBJECT_UNSET_FLAGS(obj, flag)  G_STMT_START{(IBUS_OBJECT_FLAGS(obj) &= ~(flag));} G_STMT_END
#define IBUS_OBJECT_IN_DESTRUCTION(obj)     (IBUS_OBJECT_FLAGS(obj) & IBUS_IN_DESTRUCTION)
#define IBUS_OBJECT_DESTROYED(obj)          (IBUS_OBJECT_FLAGS(obj) & IBUS_DESTROYED)

G_BEGIN_DECLS
typedef enum _IBusObjectFlags           IBusObjectFlags;
typedef struct _IBusObject              IBusObject;
typedef struct _IBusObjectClass         IBusObjectClass;
typedef struct _IBusObjectPrivate       IBusObjectPrivate;

typedef void (*IBusObjectDestroyFunc) (IBusObject* obj);

enum _IBusObjectFlags
{
    IBUS_IN_DESTRUCTION     = (1 << 0),
    IBUS_DESTROYED          = (1 << 1),
    IBUS_RESERVED_1         = (1 << 2),
    IBUS_RESERVED_2         = (1 << 3),
};

struct _IBusObject
{
    GInitiallyUnowned           parent;
    guint32                     flags;
    IBusObjectPrivate*          priv;
};

struct _IBusObjectClass
{
    GInitiallyUnownedClass      parent;

    void (*destroy) (IBusObject* obj);

    gpointer pdummy[7];
};

GType       ibus_object_get_type    (void);
IBusObject* ibus_object_new         (void);
void        ibus_object_destroy     (IBusObject* obj);

G_END_DECLS
#endif //GRACEFUL_IBUS_IBUS_OBJECT_H
