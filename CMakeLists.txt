cmake_minimum_required (VERSION 3.0)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_SYSROOT /opt/umic200/sysroot)
set(CMAKE_STAGING_PREFIX /home/umic)

#set(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabihf-gcc)
#set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabihf-g++)

# set(CMAKE_C_FLAGS "-O0 -g3")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

include_directories(SYSTEM /opt/umic200/sysroot/usr/local/include)

project (helloworld)

add_executable(helloworld source/hello.c)
target_link_libraries(${PROJECT_NAME} umic)
