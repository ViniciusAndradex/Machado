#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include "hardware/adc.h"      
#include "modules/joy.h"
#include "modules/game.h"
#include "modules/globals.h"
#include "modules/utils.h"
#include "modules/buttons.h"
#include "modules/buzzer.h"

int main() {
  stdio_init_all();
  adc_init();
  setup_joy();
  setup_buttons();
  
  setup_pwm_led(LED_V, 0);
  setup_pwm_led(LED_VD, 0);
  setup_pwm_led(LED_A, 0);
  setup_pwm_buzzer(BUZZER_A, 0);
  setup_pwm_buzzer(BUZZER_B, 0);
  srand(time(NULL));

  gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &callback);
  gpio_set_irq_enabled(BTN_B, GPIO_IRQ_EDGE_FALL, true);

  sleep_ms(50);
  while (true) {
    // template_display(7, 7, 7); 
    // sleep_ms(2000);
    if (is_betted == true) {
      pwm_set_gpio_level(LED_A, 2000);    
      while (true) {
        if (read_adc() == true) {
          float pay = game(value);
          if (pay > 0) {
            victory_sound();
            pwm_set_gpio_level(LED_A, 0);    
            pwm_set_gpio_level(LED_VD, 1000);
            printf("You receive: %.2f\n", pay);
            sleep_ms(5000);
            pwm_set_gpio_level(LED_VD, 0);
          } else {
            defeat_sound();
            pwm_set_gpio_level(LED_A, 0);    
            pwm_set_gpio_level(LED_V, 1000);
            printf("LOSER\n");
            sleep_ms(5000);
            pwm_set_gpio_level(LED_V, 0);
          }
          is_betted = false;
          value = 0;
          break;
        }
        sleep_ms(250);
      }
    }       
    sleep_ms(250);
  }

  return 0;
}