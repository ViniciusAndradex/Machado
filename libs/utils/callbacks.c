#include "pico/stdlib.h"
#include "modules/globals.h"

absolute_time_t last_interrupt_time = 0;

void callback(uint gpio, uint32_t events) {
  busy_wait_us(10000);

  if (gpio_get(gpio) == 0) {
    absolute_time_t current_time = get_absolute_time();
    if (absolute_time_diff_us(last_interrupt_time, current_time) > 100000) {
      if (gpio == BTN_A) {
        value = 100.0;
      } else if (gpio == BTN_B) {
        value = 250.0;
      }
      is_betted = true;
      last_interrupt_time = current_time;
    }
  } 
}