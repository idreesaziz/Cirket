cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(Cirket LANGUAGES CXX)
elseif(UNIX)
    project(Cirket)
endif()

add_subdirectory(CirketEditor)
