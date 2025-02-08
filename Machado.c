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
#include "modules/display.h"
#include "modules/led.h"
#include "libs/ssd1306/ssd1306.h"

int main() {
  stdio_init_all();
  i2c_init(i2c1, 400000);
  adc_init();
  setup_joy();
  init_button(BTN_A);
  init_button(BTN_B);
  setup_pwm_led(LED_V, 0);
  setup_pwm_led(LED_VD, 0);
  setup_pwm_led(LED_A, 0);
  setup_pwm_buzzer(BUZZER_A, 0);
  setup_pwm_buzzer(BUZZER_B, 0);
  setup_i2c(I2C_SDA);
  setup_i2c(I2C_SCL);
  ssd1306_init();

  srand(time(NULL));

  gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &callback);
  gpio_set_irq_enabled(BTN_B, GPIO_IRQ_EDGE_FALL, true);

  sleep_ms(50);
  while (true) {
    print_layout("  MACHADO BET", "  A to bet 200", "  B to bet 300");
    sleep_ms(50);
    if (is_betted == true) {
      print_layout("  MACHADO BET", "PULL THE JOYSTICK", "--------");
      pwm_set_gpio_level(LED_A, 2000);    
      while (true) {
        if (read_adc() == true) {
          struct GameResult result = game(value);
          game_template(result.game_numbers[0], result.game_numbers[1], result.game_numbers[2]);
          if (result.pay > 0) {
            // Converte o valor de result_pay para uma string
            char result_string[32];
            snprintf(result_string, sizeof(result_string), "     %.2f", result.pay);  // Formata o valor de pay para string

            victory_sound();
            pwm_set_gpio_level(LED_A, 0);    
            pwm_set_gpio_level(LED_VD, 1000);
            print_layout("  MACHADO BET", "   YOU WIIINN", result_string);
            sleep_ms(7000);
            pwm_set_gpio_level(LED_VD, 0);
          } else {
            defeat_sound();
            pwm_set_gpio_level(LED_A, 0);    
            pwm_set_gpio_level(LED_V, 1000);
            print_layout("  MACHADO BET", "  YOU LOOSEEE", "   TRY AGAIN");
            sleep_ms(7000);
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

  return 1;
}