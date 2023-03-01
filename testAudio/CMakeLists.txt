cmake_minimum_required(VERSION 3.13)
cmake_minimum_required(VERSION 3.13)
# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(../pico-sdk/pico_sdk_init.cmake)

project(main)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()


add_executable(main
	main.c)
target_link_libraries(main pico_stdlib hardware_adc)

pico_add_extra_outputs(main)
# rest of your project

