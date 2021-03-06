project(diskmonitor)
set(DISKMONITOR_VERSION_MAJOR "0")
set(DISKMONITOR_VERSION_MINOR "3")
set(DISKMONITOR_VERSION_PATCH "4")
set(DISKMONITOR_VERSION "${DISKMONITOR_VERSION_MAJOR}.${DISKMONITOR_VERSION_MINOR}.${DISKMONITOR_VERSION_PATCH}")



cmake_minimum_required(VERSION 2.8.12)
set (QT_MIN_VERSION "5.2.0")

# Suppress warning with CMake >= 3.3
cmake_policy(SET CMP0063 NEW)

find_package(ECM 1.6.0 REQUIRED NO_MODULE)
set (CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECompilerSettings)
include(KDECMakeSettings)
include(ECMMarkAsTest)
include(FeatureSummary)

find_package (Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
  Core
  DBus
  Widgets
  Quick
)

find_package(KF5 REQUIRED COMPONENTS
  CoreAddons
  WindowSystem
  I18n
  IconThemes
  XmlGui
  Notifications
  ConfigWidgets
  Plasma
)


kde_enable_exceptions()


include_directories( ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_SOURCE_DIR}/libdiskmonitor )

configure_file(config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)

add_subdirectory( libdiskmonitor )
add_subdirectory( settings )
add_subdirectory( app )
add_subdirectory( notifier )
add_subdirectory( translations )


feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
