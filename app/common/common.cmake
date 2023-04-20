file(GLOB GRACEFUL_IBUS_COMMON_SRC
        ${CMAKE_SOURCE_DIR}/app/common/gi-global.h
        ${CMAKE_SOURCE_DIR}/app/common/ibus-types.h
        ${CMAKE_SOURCE_DIR}/app/common/ibus-debug.h
        ${CMAKE_SOURCE_DIR}/app/common/ibus-version.h
        ${CMAKE_SOURCE_DIR}/app/common/ibus-functions.h

        ${CMAKE_SOURCE_DIR}/app/common/gi-log.h
        ${CMAKE_SOURCE_DIR}/app/common/gi-log.c
        )
include_directories(${CMAKE_SOURCE_DIR}/app/common)