file(GLOB GRACEFUL_IBUS_CORE_SRC
        ${CMAKE_SOURCE_DIR}/app/core/ibus.h
        ${CMAKE_SOURCE_DIR}/app/core/gi-global.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-types.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-debug.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-version.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-functions.h

        ${CMAKE_SOURCE_DIR}/app/core/gi-log.h
        ${CMAKE_SOURCE_DIR}/app/core/gi-log.c

        ${CMAKE_SOURCE_DIR}/app/core/ibus-object.h
        ${CMAKE_SOURCE_DIR}/app/core/ibus-object.c

        ${CMAKE_SOURCE_DIR}/app/core/interface/ibus-service.h
        ${CMAKE_SOURCE_DIR}/app/core/interface/ibus-service.c
        )
include_directories(${CMAKE_SOURCE_DIR}/app/core)
include_directories(${CMAKE_SOURCE_DIR}/app/core/interface)
