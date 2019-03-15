cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(qr
    VERSION 0.0.0
    LANGUAGES CXX
)
set(SUBPROJECTS
    qr-core
    qr-prog)

macro(find_package)
    if(NOT "${ARGV0}" IN_LIST SUBPROJECTS)
        _find_package(${ARGV})
    endif()
endmacro()

foreach(subdir IN LISTS SUBPROJECTS)
    add_subdirectory(${subdir})
endforeach()
#add_executable(${PROJECT_NAME} qr.cpp)
