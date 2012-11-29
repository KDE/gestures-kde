set(kded_SRCS
    actions/types/ActionTypeEnum.cpp
    actions/factory/ActionFactory.cpp
    actions/implementation/MoveWindow.cpp
    actions/implementation/ChangeDesktop.cpp
    actions/implementation/CloseWindow.cpp
    actions/implementation/DragAndDrop.cpp
    actions/implementation/MinimizeWindow.cpp
    actions/implementation/ChangeViewport.cpp
    actions/implementation/SendKeys.cpp
    actions/implementation/Scroll.cpp
    actions/implementation/ShowDesktop.cpp
    actions/implementation/ResizeWindow.cpp
    actions/implementation/MouseClick.cpp
    actions/implementation/MaximizeRestoreWindow.cpp
    actions/implementation/RunCommand.cpp
    config/Config.cpp
    gestures/types/GestureTypeEnum.cpp
    gestures/types/GestureDirectionEnum.cpp
    gestures/handler/GestureHandler.cpp
    gestures/factory/GestureFactory.cpp
    gestures/implementation/Gesture.cpp
    gestures/collector/GestureCollector.cpp
    windows/WindowListener.cpp
    Gestures.cpp
)

kde4_add_plugin(kded_gestures ${kded_SRCS})
target_link_libraries(kded_gestures
    ${KDE4_KDEUI_LIBS}
    ${QT_QTXML_LIBRARY}
    ${GEIS_LIBRARIES}
    ${X11_LIBRARIES}
    ${XTEST_LIBRARIES}
)

install(TARGETS kded_gestures DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES gestures.desktop DESTINATION ${SERVICES_INSTALL_DIR}/kded)
