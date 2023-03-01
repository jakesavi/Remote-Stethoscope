#include "pico/stdlib.h"
#include "hardware/adc.h"

int main(){
	stdio_init_all();
	adc_init();
	adc_gpio_init(26);
	adc_select_input(0);

	while(true){
	uint16_t raw_value = adc_read();
	printf("Raw ADC value: %d \n", raw_value);

	}
}
