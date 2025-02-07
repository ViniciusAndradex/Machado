# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

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
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Machado C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(Machado Machado.c libs/game/game.c libs/game/joystick.c libs/game/button.c 
libs/utils/callback.c libs/ssd1306/ssd1306.c libs/ssd1306/twi.c)

pico_set_program_name(Machado "Machado")
pico_set_program_version(Machado "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(Machado 0)
pico_enable_stdio_usb(Machado 0)

# Add the standard library to the build
target_link_libraries(Machado
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(Machado PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(Machado 
        hardware_i2c
        
        )

# Add ADC
target_link_libraries(Machado
    hardware_adc
)
# Add SSD1306
target_link_libraries(${PROJECT_NAME} PRIVATE 
    ssd1306
)

add_subdirectory(libs)
target_include_directories(Machado PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/libs/ssd1306)
pico_add_extra_outputs(Machado)