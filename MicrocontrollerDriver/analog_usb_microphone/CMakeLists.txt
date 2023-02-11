cmake_minimum_required(VERSION 3.12)
include(pico_sdk_import.cmake)
project(analog_microphone)
# initialize pico
pico_sdk_init()
# rest of your project
add_executable(analog_usb_microphone
    main.c
    usb_descriptors.c
    usb_microphone.c
)

target_include_directories(pico_analog_microphone INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/src/include
)
target_include_directories(usb_microphone PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(usb_microphone PRIVATE tinyusb_device tinyusb_board pico_pdm_microphone)
target_link_libraries(pico_analog_microphone INTERFACE pico_stdlib hardware_adc hardware_dma)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(usb_microphone)
