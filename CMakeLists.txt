cmake_minimum_required(VERSION 3.17)

project(jetbrains_launchers C)

set(CMAKE_C_STANDARD 99)

add_executable(intellij WIN32 main.c intellij.rc)
add_executable(datagrip WIN32 main.c datagrip.rc)
add_executable(pycharm WIN32 main.c pycharm.rc)

set_target_properties(intellij PROPERTIES COMPILE_FLAGS "-DINTELLIJ")
set_target_properties(datagrip PROPERTIES COMPILE_FLAGS "-DDATAGRIP")
set_target_properties(pycharm PROPERTIES COMPILE_FLAGS "-DPYCHARM")