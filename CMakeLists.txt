cmake_minimum_required(VERSION 3.12)
project(beakometry LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(3rdparty)

file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp")
add_executable(beakometry ${SOURCES})
target_include_directories(beakometry PUBLIC include ${3rdparty_DIRS})
target_link_libraries(beakometry PRIVATE ${3rdparty_LIBS})
if (UNIX)
    # math.h
    target_link_libraries(beakometry PRIVATE m)
endif ()

set(ENABLE_ASAN OFF)
if (ENABLE_ASAN AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (MSVC)
        target_compile_options(beakometry PRIVATE /fsanitize=address)
        target_link_options(beakometry PRIVATE /fsanitize=address)
    else ()
        target_compile_options(beakometry PRIVATE
                -fsanitize=address
                -fno-omit-frame-pointer
        )
        target_link_options(beakometry PRIVATE -fsanitize=address)
    endif ()
endif ()