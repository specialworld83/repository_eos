project(breath-icons NONE)

cmake_minimum_required(VERSION 2.8)
# include specific modules
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

if (WIN32)
   set(ICON_INSTALL_DIR         "share/icons"             ) # The icon install dir (default ${SHARE_INSTALL_PREFIX}/share/icons/)
else (WIN32)
   set(SHARE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}/share" )
   set(ICON_INSTALL_DIR     "${SHARE_INSTALL_PREFIX}/icons" )
endif(WIN32)

########### install files ###############

set( breath_icon_dirs 16 22 24 32 48 96 128 scalable symbolic)


set(BREATH_INSTALL_DIR ${ICON_INSTALL_DIR}/breath)
install( DIRECTORY ${breath_icon_dirs} DESTINATION ${BREATH_INSTALL_DIR} PATTERN "*.sh" EXCLUDE )
install( FILES index.theme DESTINATION ${BREATH_INSTALL_DIR})
