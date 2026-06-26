cmake_minimum_required(VERSION 3.10.0)
project(MOBA_CPP VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")


include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
)

FetchContent_MakeAvailable(raylib)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(MOBA_CPP src/main.cpp
    include/main.hpp
    src/MainCamera.cpp
    include/MainCamera.hpp
    include/GlobalSettings.hpp
    include/Utils.hpp)

target_link_libraries(MOBA_CPP PRIVATE raylib)

set_target_properties(MOBA_CPP PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)