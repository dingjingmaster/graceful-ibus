cmake_minimum_required(VERSION 3.5)

project(graceful-ibus LANGUAGES C CXX)

set(DEBUG ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(
        -w -g
        -D QT_NO_KEYWORDS
        -D QT_MESSAGELOGCONTEXT

        -D PACKAGE_NAME=\\"${PROJECT_NAME}\\"
        -D G_LOG_DOMAIN=\\"${PROJECT_NAME}\\"
        -D PACKAGE_VERSION=\\"${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}\\")

find_package (PkgConfig)
find_package(Qt5LinguistTools REQUIRED)
find_package(Qt5 COMPONENTS Core Network Widgets Gui DBus X11Extras Concurrent Xml REQUIRED)

pkg_check_modules(GIO REQUIRED gio-2.0)
pkg_check_modules(GTK2 REQUIRED gtk+-2.0)
pkg_check_modules(LIBCURL REQUIRED libcurl)
pkg_check_modules(THREAD REQUIRED gthread-2.0)
pkg_check_modules(PROTOBUF REQUIRED protobuf)

cmake_host_system_information(RESULT OS QUERY OS_NAME)
MESSAGE(STATUS "OS name: ${OS}")

cmake_host_system_information(RESULT RELEASE QUERY OS_RELEASE)
MESSAGE(STATUS "OS release: ${RELEASE}")

execute_process(COMMAND bash -c "qmake --version | grep -i 'qt version' | awk '{print $4}' | tr '\n' ' '|sed 's/ //g'" OUTPUT_VARIABLE CUR_QT_VERSION)
MESSAGE(STATUS "Qt Version: ${CUR_QT_VERSION}")

execute_process(COMMAND uname -m OUTPUT_VARIABLE OS_ARCH OUTPUT_STRIP_TRAILING_WHITESPACE)
MESSAGE(STATUS "OS arch: '${OS_ARCH}'")



# client
#add_subdirectory(client)
#add_subdirectory(kernel)
#add_subdirectory(tools)
#add_subdirectory(extensions)
#add_subdirectory(gui)
#add_subdirectory(data)
#add_subdirectory(demo)
#add_subdirectory(daemon)
