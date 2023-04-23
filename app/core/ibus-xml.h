//
// Created by dingjing on 23-4-23.
//

#if !defined (__IBUS_H_INSIDE__) && !defined (IBUS_COMPILATION)
#error "Only <ibus.h> can be included directly"
#endif

#ifndef GRACEFUL_IBUS_IBUS_XML_H
#define GRACEFUL_IBUS_IBUS_XML_H

/**
 * SECTION: ibusxml
 * @short_description: XML handling functions for IBus.
 * @stability: Stable
 *
 * IBusXML lists data structure and handling function for XML in IBus.
 */

#include <glib.h>
#include <glib-object.h>

#define IBUS_TYPE_XML (ibus_xml_get_type ())

G_BEGIN_DECLS

/**
 * IBusXML:
 * @name: Name of XML tag.
 * @text: Text enclosed by XML start tag and end tag. i.e. <tag>text</tag>.
 * @attributes: Attributes of the XML node.
 * @sub_nodes: Children node of this XML node.
 *
 * A data type representing an XML node.
 */
typedef struct
{
    gchar  *name;
    gchar  *text;
    gchar  **attributes;
    GList *sub_nodes;
} IBusXML;

#define XMLNode IBusXML

GType    ibus_xml_get_type      (void) G_GNUC_CONST;

/**
 * ibus_xml_copy:
 * @node: Root node of an XML tree.
 *
 * Creates a copy of @node, which should be freed with
 * ibus_xml_free(). Primarily used by language bindings,
 * not that useful otherwise (since @node can just be copied
 * by assignment in C).
 *
 * Returns: the newly allocated #IBusXML, which should
 *          be freed with ibus_xml_free(), or %NULL
 *          if @node was %NULL.
 **/
XMLNode *ibus_xml_copy          (const XMLNode  *node);

/**
 * ibus_xml_parse_file:
 * @name: File name to be parsed.
 *
 * Parse an XML file and return a corresponding XML tree.
 *
 * Returns: Root node of parsed XML tree.
 */
XMLNode *ibus_xml_parse_file    (const gchar    *name);

/**
 * ibus_xml_parse_buffer:
 * @buffer: Buffer to be parsed.
 *
 * Parse a string buffer which contains an XML-formatted string,
 * and return a corresponding XML tree.
 *
 * Returns: Root node of parsed XML tree.
 */
XMLNode *ibus_xml_parse_buffer  (const gchar    *buffer);

/**
 * ibus_xml_free:
 * @node: Root node of an XML tree.
 *
 * Free an XML tree.
 */
void     ibus_xml_free          (XMLNode        *node);

/**
 * ibus_xml_output:
 * @node: Root node of an XML tree.
 * @output: GString which stores the output.
 *
 * Output an XML tree to a GString.
 */
void     ibus_xml_output        (const XMLNode  *node,
                                 GString        *output);
G_END_DECLS

#endif //GRACEFUL_IBUS_IBUS_XML_H
