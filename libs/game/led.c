#include "pico/stdlib.h"
#include "modules/led.h"
#include "hardware/pwm.h"
#include "modules/globals.h"

const uint16_t PERIOD = 2000;   // Período do PWM (valor máximo do contador)
const float DIVIDER_PWM = 16.0; // Divisor fracional do clock para o PWM
const uint16_t LED_STEP = 100;  // Passo de incremento/decremento para o duty cycle do LED

void setup_pwm_led(int led, uint16_t level) {
  uint slice;

  gpio_set_function(led, GPIO_FUNC_PWM);
  slice = pwm_gpio_to_slice_num(led); 
  pwm_set_clkdiv(slice, DIVIDER_PWM);    
  pwm_set_wrap(slice, PERIOD);           
  pwm_set_gpio_level(led, level);    
  pwm_set_enabled(slice, true);         

}