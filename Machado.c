#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include "modules/joy.h"
#include "modules/game.h"

int main() {
    stdio_init_all();
    adc_init();
    setup_joy();
    srand(time(NULL));

    while (true) {
        if (read_adc()) {
            float pay = game(100.0);
            pritnf("You receive: %02f", pay);
        }        
        sleep_ms(500);
    }

    return 0;
}