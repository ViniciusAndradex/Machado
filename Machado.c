#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include "hardware/adc.h"      
#include "modules/joy.h"
#include "modules/game.h"
#include "modules/file.h"

int main() {
    stdio_init_all();
    adc_init();
    setup_joy();
    srand(time(NULL));

    while (true) {
        if (read_adc()) {
            float value = bet_value();
            float pay = game(100.0);
            printf("You receive: %02f", pay);
        }        
        sleep_ms(500);
    }

    return 0;
}