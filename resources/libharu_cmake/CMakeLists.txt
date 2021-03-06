# Copyright 2016, akashche at redhat.com
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# this file is based on https://github.com/libharu/libharu/blob/d84867ebf9f3de6afd661d2cdaff102457fbc371/CMakeLists.txt
cmake_minimum_required ( VERSION 2.8.12 )
project ( hpdf C )
include ( ${CMAKE_CURRENT_LIST_DIR}/../macros.cmake )

if ( NOT DEFINED ${PROJECT_NAME}_LOOKASIDE_DIR )
    set ( ${PROJECT_NAME}_LOOKASIDE_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../lookaside_libharu  CACHE INTERNAL "" )
endif ( )

# dependencies
set ( ${PROJECT_NAME}_DEPS zlib libpng )
hpdf_pkg_check_modules ( ${PROJECT_NAME}_DEPS_PC REQUIRED ${PROJECT_NAME}_DEPS )

# check deplibs cache
if ( STATICLIB_USE_DEPLIBS_CACHE )
    set ( ${PROJECT_NAME}_CACHED_LIB_PATH ${STATICLIB_DEPLIBS_CACHE_DIR}/${CMAKE_STATIC_LIBRARY_PREFIX}${PROJECT_NAME}${CMAKE_STATIC_LIBRARY_SUFFIX} )
    if ( EXISTS ${${PROJECT_NAME}_CACHED_LIB_PATH} )
        add_library( ${PROJECT_NAME} STATIC IMPORTED GLOBAL )
        set_target_properties( ${PROJECT_NAME} PROPERTIES IMPORTED_LOCATION ${${PROJECT_NAME}_CACHED_LIB_PATH} )
        message ( STATUS "Using cached library: [${${PROJECT_NAME}_CACHED_LIB_PATH}]" )
        return ( )
    endif ( )
endif ( )

# library
file ( GLOB_RECURSE ${PROJECT_NAME}_SRC ${${PROJECT_NAME}_LOOKASIDE_DIR}/src/*.c )
file ( GLOB_RECURSE ${PROJECT_NAME}_HEADERS ${${PROJECT_NAME}_LOOKASIDE_DIR}/include/*.hpp )
add_library ( ${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HEADERS} )
source_group ( "src" FILES ${${PROJECT_NAME}_SRC} )
source_group ( "include" FILES ${${PROJECT_NAME}_HEADERS} )
target_include_directories ( ${PROJECT_NAME} BEFORE PRIVATE
        ${${PROJECT_NAME}_LOOKASIDE_DIR}/include
        ${${PROJECT_NAME}_DEPS_PC_INCLUDE_DIRS} )
if ( ${CMAKE_CXX_COMPILER_ID}x MATCHES "MSVCx" )
    target_compile_options ( ${PROJECT_NAME} PRIVATE
            /wd4244 /wd4305 /wd4267 /wd4018 )
    target_compile_definitions ( ${PROJECT_NAME} PRIVATE 
            -D_CRT_SECURE_NO_WARNINGS
            -D_CRT_SECURE_NO_DEPRECATE )
endif ( )
