cmake_minimum_required(VERSION 3.19)
project(port-scanner LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Concurrent Network)

qt_standard_project_setup()

# Boost header-only
include_directories("D:/boost")

if(WIN32)
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/appicon.rc")
endif()

qt_add_executable(port-scanner
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    resources.qrc
    appicon.rc
    ${APP_ICON_RESOURCE_WINDOWS}
    icons/shield.png
)


target_link_libraries(port-scanner
    PRIVATE
        Qt::Core
        Qt6::Widgets
        ${Boost_LIBRARIES}
        ws2_32
        Qt6::Concurrent
        Qt6::Network
)

include(GNUInstallDirs)

install(TARGETS port-scanner
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET port-scanner
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
