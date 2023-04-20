project(bus LANGUAGES C)

include(${CMAKE_SOURCE_DIR}/app/common/common.cmake)

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

        global.c
        global.h

        server.c
        server.h

        connection.c
        connection.h

        matchrule.c
        matchrule.h

        marshalers.c
        marshalers.h

        types.h

        ibus.h

        ibusversion.h

        ibusenumtypes.c
        ibusenumtypes.h

        ibusshare.c
        ibusshare.h

        ibusresources.h
        ibusresources.c

        ibusbus.h
        ibusbus.c

        ibusmarshalers.h
        ibusmarshalers.c

        ibustext.c
        ibustext.h

        ibusserializable.c
        ibusserializable.h

        ibusobject.h
        ibusobject.c

        ibuslookuptable.c
        ibuslookuptable.h

        ibusregistry.c
        ibusregistry.h

        ibuscomponent.c
        ibuscomponent.h

        ibusservice.c
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

        ibusproxy.c
        ibusproxy.h

        ibusenginedesc.c
        ibusenginedesc.h

        ibuskeymap.c
        ibuskeymap.h

        ibusxml.c
        ibusxml.h

        ibusattrlist.c
        ibusattrlist.h

        ibusunicode.c
        ibusunicode.h

        ibuserror.c
        ibuserror.h

        ibusobservedpath.c
        ibusobservedpath.h

        ibusattribute.c
        ibusattribute.h

        ibusemoji.c
        ibusemoji.h

        ibuskeys.h
        ibuskeynames.c

        ibuskeyuni.c

        ibusconfig.c
        ibusconfig.h

        ibusinputcontext.c
        ibusinputcontext.h
        )

add_executable(ibus-daemon main.c ${IBUS_DAEMON_SRC} ${GRACEFUL_IBUS_COMMON_SRC})
target_include_directories(ibus-daemon PUBLIC
        ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/app/common/
        ${GIO_INCLUDE_DIRS})
target_link_libraries(ibus-daemon PUBLIC ${GIO_LIBRARIES})
target_compile_definitions(ibus-daemon PUBLIC -D INSTALL_NAME=\"ibus-daemon\")