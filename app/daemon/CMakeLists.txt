project(bus LANGUAGES C)

include(${CMAKE_SOURCE_DIR}/app/core/core.cmake)

file(GLOB IBUS_DAEMON_SRC
        component.c
        component.h

        dbusimpl.c
        dbusimpl.h

        ibusimpl.c
        ibusimpl.h

        inputcontext.c
        inputcontext.h

        engineproxy.c
        engineproxy.h

        panelproxy.c
        panelproxy.h

        factoryproxy.c
        factoryproxy.h

        server.c
        server.h

        connection.c
        connection.h

        matchrule.c
        matchrule.h

        marshalers.c
        marshalers.h

        types.h

        ../core/ibus.h

        ibusversion.h

        ibusenumtypes.c
        ibusenumtypes.h

        ibusresources.h
        ibusresources.c

        ibusmarshalers.h
        ibusmarshalers.c

        ibusobject.h
        ibusobject.c

        ibuslookuptable.c
        ibuslookuptable.h

        ibusregistry.c
        ibusregistry.h

        ibusservice.h

        ibusproperty.c
        ibusproperty.h

        ibusproplist.c
        ibusproplist.h

        ibusinternal.h

        ibusutil.c
        ibusutil.h

        ibusxevent.c
        ibusxevent.h

        ibuskeymap.c
        ibuskeymap.h

        ibusattrlist.c
        ibusattrlist.h

        ibusemoji.c
        ibusemoji.h

        ibuskeys.h
        ibuskeynames.c

        ibuskeyuni.c
        )

add_executable(ibus-daemon main.c ${IBUS_DAEMON_SRC} ${GRACEFUL_IBUS_CORE_SRC})
target_include_directories(ibus-daemon PUBLIC
        ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/app/common/
        ${GIO_INCLUDE_DIRS})
target_link_libraries(ibus-daemon PUBLIC ${GIO_LIBRARIES})
target_compile_definitions(ibus-daemon PUBLIC -D INSTALL_NAME=\"ibus-daemon\")