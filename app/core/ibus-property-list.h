//
// Created by dingjing on 23-4-23.
//

#if !defined (__IBUS_H_INSIDE__) && !defined (IBUS_COMPILATION)
#error "Only <ibus.h> can be included directly"
#endif

#ifndef GRACEFUL_IBUS_IBUS_PROPERTY_LIST_H
#define GRACEFUL_IBUS_IBUS_PROPERTY_LIST_H

/**
 * SECTION: ibusproplist
 * @Title: IBusPropList
 * @Short_description: An #IBusProperty container.
 * @Stability: Stable
 *
 * See_also: #IBusProperty, #IBusEngine
 *
 */

#include "ibus-property.h"
#include "ibus-serializable.h"

G_BEGIN_DECLS

/*
 * Type macros.
 */
/* define IBusPropList macros */
#define IBUS_TYPE_PROP_LIST             \
    (ibus_prop_list_get_type ())
#define IBUS_PROP_LIST(obj)             \
    (G_TYPE_CHECK_INSTANCE_CAST ((obj), IBUS_TYPE_PROP_LIST, IBusPropList))
#define IBUS_PROP_LIST_CLASS(klass)     \
    (G_TYPE_CHECK_CLASS_CAST ((klass), IBUS_TYPE_PROP_LIST, IBusPropListClass))
#define IBUS_IS_PROP_LIST(obj)          \
    (G_TYPE_CHECK_INSTANCE_TYPE ((obj), IBUS_TYPE_PROP_LIST))
#define IBUS_IS_PROP_LIST_CLASS(klass)  \
    (G_TYPE_CHECK_CLASS_TYPE ((klass), IBUS_TYPE_PROP_LIST))
#define IBUS_PROP_LIST_GET_CLASS(obj)   \
    (G_TYPE_INSTANCE_GET_CLASS ((obj), IBUS_TYPE_PROP_LIST, IBusPropListClass))

/* FIXME: https://mail.gnome.org/archives/gtk-doc-list/2015-July/msg00004.html
 * If ibusproperty.h and ibusproplist.h includes each other,
 * gtk-doc build outputs several warnings:
 *
 * # cd html && gtkdoc-mkhtml ibus ../ibus-docs.sgml
 * ../ibus-docs.sgml:4: element refentry: validity error : ID IBusPropList
 * already defined
 * ../ibus-docs.sgml:172: element refsect2: validity error : ID
 * IBusPropListClass already defined
 * Warning: multiple "IDs" for constraint linkend: IBusPropList.
 * Warning: multiple "IDs" for constraint linkend: IBusPropList.
 * Warning: multiple "IDs" for constraint linkend: IBusPropListClass.
 */
#ifndef __PROPLIST_DEFINED
#define __PROPLIST_DEFINED
typedef struct _IBusPropList IBusPropList;
typedef struct _IBusPropListClass IBusPropListClass;
#endif

/**
 * IBusPropList:
 * @properties: GArray that holds IBusProperties.
 *
 * An array of IBusProperties.
 */
struct _IBusPropList {
    IBusSerializable parent;

    /*< public >*/
    GArray *properties;
};

/**
 * IBusPropListClass:
 * @parent: The parent class.
 *
 * Class structure for #IBusPropList.
 */
struct _IBusPropListClass {
    IBusSerializableClass parent;
};

GType            ibus_prop_list_get_type    ();

/**
 * ibus_prop_list_new:
 *
 * Create a new #IBusPropList.
 *
 * Returns: A newly allocated #IBusPropList.
 */
IBusPropList    *ibus_prop_list_new         ();

/**
 * ibus_prop_list_append:
 * @prop_list: An IBusPropList.
 * @prop: IBusProperty to be append to @prop_list.
 *
 * Append an IBusProperty to an IBusPropList, and increase reference.
 */
void             ibus_prop_list_append      (IBusPropList   *prop_list,
                                             IBusProperty   *prop);

/**
 * ibus_prop_list_get:
 * @prop_list: An IBusPropList.
 * @index: Index of an IBusPropList.
 *
 * Gets #IBusProperty at given index. Borrowed reference.
 *
 * Returns: (transfer none): #IBusProperty at given index, %NULL if no such
 *     #IBusProperty.
 */
IBusProperty    *ibus_prop_list_get         (IBusPropList   *prop_list,
                                             guint           index);

/**
 * ibus_prop_list_update_property:
 * @prop_list: An IBusPropList.
 * @prop: IBusProperty to be update.
 *
 * Update an IBusProperty in IBusPropList.
 *
 * Returns: %TRUE if succeeded, %FALSE otherwise.
 */
gboolean         ibus_prop_list_update_property
    (IBusPropList   *prop_list,
     IBusProperty   *prop);
G_END_DECLS


#endif //GRACEFUL_IBUS_IBUS_PROPERTY_LIST_H
