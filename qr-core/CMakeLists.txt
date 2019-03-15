cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
set(NAMESPACE qr)
set(COMPONENT core)
project(${NAMESPACE}-${COMPONENT}
    VERSION 0.0.0
    LANGUAGES CXX
)
add_library(${PROJECT_NAME}
    include/${NAMESPACE}/qr-core.hpp
    src/qr-core.cpp
)

include(FindPkgConfig)
pkg_check_modules(QR REQUIRED IMPORTED_TARGET libqrencode>=4.0.0)
target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::QR)

add_library(${NAMESPACE}::${COMPONENT} ALIAS ${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
