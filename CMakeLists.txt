# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
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
# ====================================================================================
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

project(Projeto-matriz-contagem C CXX ASM)

pico_sdk_init()

add_executable(Projeto-matriz-contagem Projeto-matriz-contagem.c )

pico_set_program_name(Projeto-matriz-contagem "Projeto-matriz-contagem")
pico_set_program_version(Projeto-matriz-contagem "0.1")

pico_enable_stdio_uart(Projeto-matriz-contagem 0)
pico_enable_stdio_usb(Projeto-matriz-contagem 1)

pico_generate_pio_header(Projeto-matriz-contagem ${CMAKE_CURRENT_LIST_DIR}/Projeto-matriz-contagem.pio)

target_sources(Projeto-matriz-contagem PRIVATE Projeto-matriz-contagem.c)

target_link_libraries(Projeto-matriz-contagem
        pico_stdlib
        hardware_pio
        pico_bootrom
        hardware_pwm
        )

target_include_directories(Projeto-matriz-contagem PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)


pico_add_extra_outputs(Projeto-matriz-contagem)

#Adicione esta linha para gerar o arquivo .hex
add_custom_command(TARGET Projeto-matriz-contagem POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:Projeto-matriz-contagem> ${PROJECT_BINARY_DIR}/Projeto-matriz-contagem.hex
)

