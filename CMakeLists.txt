cmake_minimum_required(VERSION 3.15)
project(RPGBattle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Always generate compile_commands.json (useful for IntelliSense/clangd)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(RPGBattle
    ${SOURCES}
)
