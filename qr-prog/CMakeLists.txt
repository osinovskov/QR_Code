cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(NAMESPACE qr)
set(COMPONENT prog)
project(${NAMESPACE}-${COMPONENT}
    VERSION 0.0.0
    LANGUAGES CXX
)

add_executable(${PROJECT_NAME}
    src/prog.cpp
)

add_executable(${NAMESPACE}::${COMPONENT} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

find_package(qr-core 0.0.0 REQUIRED)
target_link_libraries(${PROJECT_NAME} qr::core)
