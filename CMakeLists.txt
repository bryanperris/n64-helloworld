cmake_minimum_required(VERSION 2.8)

project(helloworld C)

set(CMAKE_C_COMPILER mips64-elf-gcc)
set(CMAKE_CXX_COMPILER mips64-elf-g++)
set(CMAKE_ASM_COMPILER mips64-elf-as)
set(CMAKE_C_FLAGS "-std=gnu99 -march=vr4300 -mtune=vr4300 -Wall -I/usr/local/mips64-elf/include")
set(CMAKE_C_LINK_EXECUTABLE "mips64-elf-ld <OBJECTS> -L/usr/local/mips64-elf/lib -ldragon -lc -lm -ldragonsys -Tn64.ld -o <TARGET>")
set(CMAKE_ASM_FLAGS "-mtune=vr4300 -march=vr4300")
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

add_executable(${CMAKE_PROJECT_NAME} main.c)

add_custom_command(
    TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generate N64 Catridge Image"
    COMMAND mips64-elf-objcopy ${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}.bin -O binary
    COMMAND n64tool -l 2M -t ${CMAKE_PROJECT_NAME} -h /usr/local/mips64-elf/lib/header -o ${CMAKE_PROJECT_NAME}.z64 ${CMAKE_PROJECT_NAME}.bin
    COMMAND chksum64 ${CMAKE_PROJECT_NAME}.z64
)