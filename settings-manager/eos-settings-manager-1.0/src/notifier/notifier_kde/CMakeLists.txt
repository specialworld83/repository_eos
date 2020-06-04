cmake_policy(SET CMP0063 NEW)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

file(GLOB NOTIFIER_KDE_GLOB
     csm_kde_notifier.desktop
     csm_kde_notifier_settings.desktop
     icons/language.png
     icons/tux-eos.png)

set(NOTIFIER_KDE_SRCS
    ${NOTIFIER_KDE_GLOB}
    main.cpp
    Notifier.cpp
    NotifierApp.cpp)

set(NOTIFIER_KDE_RESOURCES
    notifier.qrc)
QT5_ADD_RESOURCES (NOTIFIER_KDE_SRCS ${NOTIFIER_KDE_RESOURCES})

add_executable(eossm_kde_notifier ${NOTIFIER_KDE_SRCS})
target_compile_definitions(eossm_kde_notifier PRIVATE -DPROJECT_VERSION="${PROJECT_VERSION}")
target_link_libraries(eossm_kde_notifier
    msm
    Qt5::Widgets
    KF5::Notifications)

install(TARGETS eossm_kde_notifier DESTINATION ${CMAKE_INSTALL_BINDIR})
install(PROGRAMS eossm_kde_notifier.desktop DESTINATION ${KDE_INSTALL_AUTOSTARTDIR})
install(FILES eossm_kde_notifier_settings.desktop DESTINATION ${CMAKE_INSTALL_DATADIR}/applications)
