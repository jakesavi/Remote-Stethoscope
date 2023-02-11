#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h" // Intellisense fucking hates this package for some reason???
#include "tusb.h"
#include "pico/analog_microphone.h"
const struct analog_microphone_config config = {
    // GPIO to use for input, must be ADC compatible (GPIO 26 - 28)
    .gpio = 26,

    // bias voltage of microphone in volts
    .bias_voltage = 1.25,

    // sample rate in Hz
    .sample_rate = 8000,

    // number of samples to buffer
    .sample_buffer_size = 256,
};

int16_t sample_buffer[256];
volatile int samples_read = 0;
void on_analog_samples_ready()
{
    // Callback from library when all the samples in the library
    //internal sample buffer are ready for reading
    samples_read = analog_microphone_read(sample_buffer, 256);
}
void on_usb_microphone_tx_ready();
int main( void ){
    stdio_init_all();
    while(!tud_cdc_connected()){
        tight_loop_contents();
    }
    printf("ANALOG VICTORY")

    if (analog_microphone_init(&config) < 0) {
        printf("Analog microphone failed to start\n");
        while (1) {tight_loop_contents();}
    }
    analog_microphone_set_samples_ready_handler(on_analog_samples_ready());
    analog_microphone_start();
    // Initialize the UBS micriohone interface
    usb_microphone_init();
    on_usb_microphone_set_tx_ready_handler(on_usb_microphone_tx_ready);
    while(1) {
       usb_microphone_task();
    }
    return 0;
}

void on_usb_microphone_tx_ready()
{
    usb_microphone_write(sample_buffer, sizeof(sample_buffer));
}