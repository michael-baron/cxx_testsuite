cmake_minimum_required(VERSION 3.16)

project(cxx_testsuite
    VERSION 1.0
    LANGUAGES C CXX
)

# Use a reasonably modern C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect all source files
file(GLOB PROJECT_SOURCES
    "*.cpp"
    "*.c"
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

# Optional warning levels
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

# Enable compile_commands.json for static analysis tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
