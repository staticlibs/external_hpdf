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
set ( ${PROJECT_NAME}_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../../libharu )

# dependencies
set ( ${PROJECT_NAME}_DEPS zlib libpng )
hpdf_pkg_check_modules ( ${PROJECT_NAME}_DEPS_PC REQUIRED ${PROJECT_NAME}_DEPS )

# library
file ( GLOB_RECURSE ${PROJECT_NAME}_SRC ${${PROJECT_NAME}_SOURCE_DIR}/src/*.c )
file ( GLOB_RECURSE ${PROJECT_NAME}_HEADERS ${${PROJECT_NAME}_SOURCE_DIR}/include/*.hpp )
add_library ( ${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SRC} ${${PROJECT_NAME}_HEADERS} )
source_group ( "src" FILES ${${PROJECT_NAME}_SRC} )
source_group ( "include" FILES ${${PROJECT_NAME}_HEADERS} )
target_include_directories ( ${PROJECT_NAME} BEFORE PRIVATE
        ${${PROJECT_NAME}_SOURCE_DIR}/include
        ${${PROJECT_NAME}_DEPS_PC_INCLUDE_DIRS} )
if ( ${CMAKE_CXX_COMPILER_ID}x MATCHES "MSVCx" )
    target_compile_definitions ( ${PROJECT_NAME} PRIVATE 
            -D_CRT_SECURE_NO_WARNINGS
            -D_CRT_SECURE_NO_DEPRECATE )
endif ( )
