#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include "hardware/adc.h"      
#include "modules/joy.h"
#include "modules/game.h"
#include "modules/globals.h"
#include "modules/utils.h"
#include "modules/buttons.h"

int main() {
    stdio_init_all();
    adc_init();
    setup_joy();
    setup_buttons();
    srand(time(NULL));

    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &callback);
    gpio_set_irq_enabled(BTN_B, GPIO_IRQ_EDGE_FALL, true);

    sleep_ms(50);
    while (true) {
      if (is_betted == true) {
        while (true) {
          if (read_adc() == true) {
            float pay = game(value);
            is_betted = false;
            value = 0;
            printf("You receive: %.2f\n", pay);
            break;
          }
          sleep_ms(250);
        }
      }       
      sleep_ms(250);
    }

    return 0;
}