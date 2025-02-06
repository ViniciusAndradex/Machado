#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include "modules/joy.h"

int main() {
    stdio_init_all();
    adc_init();
    setup_joy();

    while (true) {
        if (read_adc()) {
            prinf("Test\n");
        }        

        sleep_ms(500);
    }

    return 0;
}