cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(Cirket LANGUAGES CXX)
elseif(UNIX)
    project(Cirket)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})


find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

#=================== INCLUSION OF Project Files ====================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/CirketEditor/UI")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/CirketEditor/Source")

include_directories(${FORMS_DIR})
include_directories(${SOURCE_DIR})

FILE(GLOB UIs *.ui)
# to generate header files for .ui files
qt_wrap_ui(UI_HEADERS  ${UIs})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${SOURCE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

#=================== SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR} ${UI_HEADERS})

# Add the executable
if (WIN32) 
    add_executable(Editor WIN32 ${SOURCES} ${UI_HEADERS})
elseif(UNIX)
    add_executable(Editor ${SOURCES} ${UI_HEADERS})
endif()

# Add the target includes for Editor
target_include_directories(Editor PRIVATE ${FORMS_DIR})
target_include_directories(Editor PRIVATE "${CMAKE_SOURCE_DIR}/CirketEditor/Vendor/NodeEditor/Include")
target_include_directories(Editor PRIVATE "${CMAKE_SOURCE_DIR}/CirketEditor/Vendor/NodeEditor/Include/QtNodes")
target_include_directories(Editor PRIVATE ${SOURCE_DIR})

add_subdirectory("${CMAKE_SOURCE_DIR}/CirketEditor/Vendor/NodeEditor")

#===================== LINKING LIBRARIES =======================#
target_link_libraries(Editor Qt6::Widgets QtNodes ${UI_HEADERS})

