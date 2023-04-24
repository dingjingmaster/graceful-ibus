project(dsm-ibus-portal LANGUAGES C)

include(${CMAKE_SOURCE_DIR}/app/core/core.cmake)

execute_process(COMMAND "gdbus-codegen --header --output ${CMAKE_SOURCE_DIR}/app/portal/ibus-portal-dbus.h
                    ${CMAKE_SOURCE_DIR}/app/portal/org.freedesktop.IBus.Portal.xml")
execute_process(COMMAND "gdbus-codegen --body --output ${CMAKE_SOURCE_DIR}/app/portal/ibus-portal-dbus.c
                    ${CMAKE_SOURCE_DIR}/app/portal/org.freedesktop.IBus.Portal.xml")

add_executable(ibus-portal main.c ${GRACEFUL_IBUS_CORE_SRC})
target_include_directories(ibus-portal PUBLIC
        ${CMAKE_SOURCE_DIR}/app ${CMAKE_SOURCE_DIR}/app/core/
        ${GIO_INCLUDE_DIRS})
target_link_libraries(ibus-portal PUBLIC ${GIO_LIBRARIES})
target_compile_definitions(ibus-portal PUBLIC -D INSTALL_NAME=\"ibus-portal\")
