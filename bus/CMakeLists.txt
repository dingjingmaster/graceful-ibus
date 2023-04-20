project(bus LANGUAGES C CXX)

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

        ../src/ibus.h

        ../src/ibusversion.h

        ../src/ibusenumtypes.c
        ../src/ibusenumtypes.h

        ../src/ibusshare.c
        ../src/ibusshare.h

        ../src/ibusresources.h
        ../src/ibusresources.c

        ../src/ibusbus.h
        ../src/ibusbus.c

        ../src/ibusmarshalers.h
        ../src/ibusmarshalers.c

        ../src/ibustext.c
        ../src/ibustext.h

        ../src/ibusserializable.c
        ../src/ibusserializable.h

        ../src/ibusobject.h
        ../src/ibusobject.c

        ../src/ibuslookuptable.c
        ../src/ibuslookuptable.h

        ../src/ibusregistry.c
        ../src/ibusregistry.h

        ../src/ibuscomponent.c
        ../src/ibuscomponent.h

        ../src/ibusservice.c
        ../src/ibusservice.h

        ../src/ibusproperty.c
        ../src/ibusproperty.h

        ../src/ibusproplist.c
        ../src/ibusproplist.h

        ../src/ibusinternal.h

        ../src/ibusutil.c
        ../src/ibusutil.h

        ../src/ibusxevent.c
        ../src/ibusxevent.h

        ../src/ibusproxy.c
        ../src/ibusproxy.h

        ../src/ibusenginedesc.c
        ../src/ibusenginedesc.h

        ../src/ibuskeymap.c
        ../src/ibuskeymap.h

        ../src/ibusxml.c
        ../src/ibusxml.h

        ../src/ibusattrlist.c
        ../src/ibusattrlist.h

        ../src/ibusunicode.c
        ../src/ibusunicode.h

        ../src/ibuserror.c
        ../src/ibuserror.h

        ../src/ibusobservedpath.c
        ../src/ibusobservedpath.h

        ../src/ibusattribute.c
        ../src/ibusattribute.h

        ../src/ibusemoji.c
        ../src/ibusemoji.h

        ../src/ibuskeys.h
        ../src/ibuskeynames.c

        ../src/ibuskeyuni.c

        ../src/ibusconfig.c
        ../src/ibusconfig.h

        ../src/ibusinputcontext.c
        ../src/ibusinputcontext.h
        )

add_executable(ibus-daemon main.c ${IBUS_DAEMON_SRC})
target_include_directories(ibus-daemon PUBLIC
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/bus
        ${GIO_INCLUDE_DIRS}
        )
target_link_libraries(ibus-daemon PUBLIC ${GIO_LIBRARIES})