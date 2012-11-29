project(gestures-kde)

set(GESTURES_KDE_VERSION "0.1.0")
configure_file(config.h.cmake
               ${CMAKE_CURRENT_BINARY_DIR}/config.h )

find_package(KDE4 REQUIRED)

include(FindPkgConfig)
include(KDE4Defaults)

pkg_check_modules(GEIS REQUIRED libgeis)
pkg_check_modules(X11 REQUIRED x11)
pkg_check_modules(XTEST REQUIRED xtst)

add_definitions(${QT_DEFINITIONS} ${KDE_DEFINITIONS})

include_directories(${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${KDE4_INCLUDES}
    ${GEIS_INCLUDES}
    ${X11_INCLUDES}
    ${XTEST_INCLUDES}
)

add_subdirectory(src)
