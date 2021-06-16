cmake_minimum_required(VERSION 3.17)

project(jetbrains_launchers C)

set(CMAKE_C_STANDARD 99)

add_executable(intellij WIN32 main.c intellij.rc)
add_executable(datagrip WIN32 main.c datagrip.rc)
add_executable(pycharm WIN32 main.c pycharm.rc)
add_executable(clion WIN32 main.c clion.rc)
add_executable(phpstorm WIN32 main.c phpstorm.rc)
add_executable(goland WIN32 main.c goland.rc)
add_executable(webstorm WIN32 main.c webstorm.rc)

set_target_properties(intellij PROPERTIES COMPILE_FLAGS "-DINTELLIJ")
set_target_properties(datagrip PROPERTIES COMPILE_FLAGS "-DDATAGRIP")
set_target_properties(pycharm PROPERTIES COMPILE_FLAGS "-DPYCHARM")
set_target_properties(clion PROPERTIES COMPILE_FLAGS "-DCLION")
set_target_properties(phpstorm PROPERTIES COMPILE_FLAGS "-DPHPSTORM")
set_target_properties(goland PROPERTIES COMPILE_FLAGS "-DGOLAND")
set_target_properties(webstorm PROPERTIES COMPILE_FLAGS "-DWEBSTORM")