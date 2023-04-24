file(GLOB GRACEFUL_IBUS_CORE_SRC
        ${CMAKE_SOURCE_DIR}/app/core/ibus.h
        ${CMAKE_SOURCE_DIR}/app/core/gi-global.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-types.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-debug.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-version.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-functions.h

        ${CMAKE_SOURCE_DIR}/app/core/ibus-log.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-log.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-bus.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-bus.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-xml.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-xml.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-main.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-main.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-text.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-text.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-proxy.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-proxy.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-error.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-error.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-object.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-object.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-config.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-config.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-marshal.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-marshal.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-unicode.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-unicode.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-internal.h

        ${CMAKE_SOURCE_DIR}/app/core/ibus-property.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-property.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-attribute.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-attribute.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-component.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-component.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-engine-desc.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-engine-desc.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-serializable.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-serializable.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-lookup-table.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-lookup-table.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-input-context.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-input-context.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-property-list.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-property-list.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-observed-path.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-observed-path.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-attribute-list.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-attribute-list.c

        ${CMAKE_SOURCE_DIR}/app/core/interface/ibus-service.h
        ${CMAKE_SOURCE_DIR}/app/core/interface/ibus-service.c

        #######
        ${CMAKE_SOURCE_DIR}/app/core/ibus-keys.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-key-names.c
        ${CMAKE_SOURCE_DIR}/app/core/ibus-key-syms-compat.h

        ${CMAKE_SOURCE_DIR}/app/core/ibus-util.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-util.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-emoji.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-emoji.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-xevent.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-xevent.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-engine.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-engine.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-factory.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-factory.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-key-map.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-key-map.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-hot-key.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-hot-key.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-registry.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-registry.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-accel-group.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-accel-group.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-panel-service.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-panel-service.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-engine-simple.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-engine-simple.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-compose-table.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-compose-table.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-config-service.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-config-service.c

        )

include_directories(${CMAKE_SOURCE_DIR}/app/core)
include_directories(${CMAKE_SOURCE_DIR}/app/core/interface)

add_definitions(-D X11_LOCALEDATADIR=\\"/usr/share/X11/locale\\" )

