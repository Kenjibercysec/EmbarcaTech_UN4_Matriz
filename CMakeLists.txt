cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)

project(EmbarcaTech-UN4 C CXX ASM)

pico_sdk_init()

add_executable(EmbarcaTech-UN4 EmbarcaTech-UN4.c )

pico_set_program_name(EmbarcaTech-UN4 "EmbarcaTech-UN4")
pico_set_program_version(EmbarcaTech-UN4 "0.1")

pico_enable_stdio_uart(EmbarcaTech-UN4 0)
pico_enable_stdio_usb(EmbarcaTech-UN4 1)

pico_generate_pio_header(EmbarcaTech-UN4 ${CMAKE_CURRENT_LIST_DIR}/EmbarcaTech-UN4.pio)

target_sources(EmbarcaTech-UN4 PRIVATE EmbarcaTech-UN4.c)

target_link_libraries(EmbarcaTech-UN4
        pico_stdlib
        hardware_pio
        pico_bootrom
        hardware_pwm
        )

target_include_directories(EmbarcaTech-UN4 PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(EmbarcaTech-UN4 
        
        )

pico_add_extra_outputs(EmbarcaTech-UN4)

// Adicione esta linha para gerar o arquivo .hex
add_custom_command(TARGET EmbarcaTech-UN4 POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex ${CMAKE_CURRENT_BINARY_DIR}/EmbarcaTech-UN4 ${CMAKE_CURRENT_BINARY_DIR}/EmbarcaTech-UN4.hex
)

