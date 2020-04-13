# // ------------------------------------------------------------------------------
#
# This is CMake-Project for btEngine.
#
# btEngine - cross-platform game enigne, designed to use low memory,
# good CPU and GPU performance.
#
# License: see "LICENSE" file.
#
# // ------------------------------------------------------------------------------

# =================================================================================
# CMake Meta-Data
# =================================================================================

# CMake-Version
cmake_minimum_required ( VERSION 3.5 FATAL_ERROR ) # QT5 + CMake required 3.5 minimum.

# =================================================================================
# PROJECT
# =================================================================================

# Project Name
set ( PROJECT_NAME "btEngine" )

# Project Version
set ( PROJECT_VERSION 0.1.1 )

# Project Description
set ( PROJECT_DESCRIPTION "btEngine" )

# Configure Project
project ( ${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION} LANGUAGES C CXX )

# C++ Version
set ( CMAKE_CXX_STANDARD 11 )
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# =================================================================================
# CONFIGS
# =================================================================================

# Configs.
include ( "cmake/config.cmake" )

# Platform.
include ( "cmake/platform.cmake" )

# ABI.
include ( "cmake/abi.cmake" )

# =================================================================================
# OPTIONS
# =================================================================================

include ( "cmake/options.cmake" )

# =================================================================================
# HEADERS
# =================================================================================

set ( BT_HEADERS
	# CONFIGS
	"config/bt_api.hpp"
	"config/bt_log.hpp"
	# ENGINE
	"bt.hpp" )

# Headers for SHARED Library.
set ( BT_PUBLIC_HEADERS "bt.hpp" )

# =================================================================================
# SOURCES
# =================================================================================

set ( BT_SOURCES
	# CONFIGS
	# ENGINE
	"bt.cpp" )

# =================================================================================
# MODULES
# =================================================================================

# MEMORY

# MUTEX

# ECS

# CORE
include ("core/core.cmake")

# RENDER

# ANDROID

# LINUX

# WINDOWS

# =================================================================================
# BUILD
# =================================================================================

include ( "cmake/build.cmake" )