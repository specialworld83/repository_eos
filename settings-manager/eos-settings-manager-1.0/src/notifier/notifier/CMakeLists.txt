cmake_policy(SET CMP0063 NEW)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB NOTIFIER_GLOB
     csm_notifier.desktop
     csm_notifier_settings.desktop
     icons/language.png
     icons/tux-eos.png)

set(NOTIFIER_SRCS
    ${NOTIFIER_GLOB}
    main.cpp
    Notifier.cpp
    NotifierApp.cpp)

set(NOTIFIER_RESOURCES
    notifier.qrc)
QT5_ADD_RESOURCES (NOTIFIER_SRCS ${NOTIFIER_RESOURCES})

add_executable(eossm_notifier ${NOTIFIER_SRCS})
target_compile_definitions(eossm_notifier PRIVATE -DPROJECT_VERSION="${PROJECT_VERSION}")
target_link_libraries(eossm_notifier
    msm
    Qt5::Widgets)

install(TARGETS eossm_notifier DESTINATION ${CMAKE_INSTALL_BINDIR})
install(PROGRAMS eossm_notifier.desktop DESTINATION ${KDE_INSTALL_AUTOSTARTDIR})
install(FILES eossm_notifier_settings.desktop DESTINATION ${CMAKE_INSTALL_DATADIR}/applications)
