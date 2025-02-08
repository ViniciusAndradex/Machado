#include "hardware/adc.h"
#include "modules/joy.h"

#define VRY_PIN 26
#define VRX_PIN 27 

void setup_joy() {
    adc_gpio_init(VRX_PIN);
    adc_gpio_init(VRY_PIN);
}

bool read_adc() {
    adc_select_input(0);
    uint16_t vrx_value = adc_read();
    adc_select_input(1);
    uint16_t vry_value = adc_read(); 
    
    if (vrx_value <= 1000 || vrx_value >= 3200 || vry_value <= 1000 || vry_value >= 3200){
        return true;
    }
    return false;
}
    