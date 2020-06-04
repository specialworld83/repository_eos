project(BreathTheme)

cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

set(INSTALL_SDDM_THEME TRUE)

include(WriteBasicConfigVersionFile)
include(FeatureSummary)

find_package(ECM 1.5.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

# Set version
set(THEME_VERSION_MAJOR 0)
set(THEME_VERSION_MINOR 1)
set(THEME_VERSION_PATCH 0)
set(THEME_VERSION_STRING "${THEME_VERSION_MAJOR}.${THEME_VERSION_MINOR}.${THEME_VERSION_PATCH}")

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS Plasma)
  
include(ECMInstallIcons)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(GenerateExportHeader)

add_subdirectory(icons)
add_subdirectory(icons-dark)
add_subdirectory(breath)
add_subdirectory(wallpapers)

plasma_install_package(lookandfeel org.kde.breath.desktop look-and-feel lookandfeel)

if (INSTALL_SDDM_THEME)
# Install the login theme into the SDDM directory
# Longer term we need to look at making SDDM load from look and feel somehow.. and allow copying at runtime
    #NOTE this trailing slash is important to rename the directory
    install(DIRECTORY sddm-theme/ DESTINATION ${KDE_INSTALL_FULL_DATADIR}/sddm/themes/breath PATTERN "README.txt" EXCLUDE PATTERN "components" EXCLUDE PATTERN "dummydata" EXCLUDE)
endif()

INSTALL(FILES colors/Breath.colors colors/BreathDark.colors DESTINATION ${DATA_INSTALL_DIR}/color-schemes/)
if(EXISTS ${CMAKE_SOURCE_DIR}/po AND IS_DIRECTORY ${CMAKE_SOURCE_DIR}/po)
  find_package(KF5I18n CONFIG REQUIRED)
  ki18n_install(po)
endif()

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
