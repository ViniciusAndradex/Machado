#include "hardware/pwm.h"
#include "pico/stdlib.h"
#include "modules/globals.h"
#include "modules/buzzer.h"

const float BUZZER_DIVIDER = 4.0;   
const uint16_t BUZZER_FREQUENCY = 4000;

void setup_pwm_buzzer(int buzzer_pin, uint16_t frequency) {
    uint slice;

    gpio_set_function(buzzer_pin, GPIO_FUNC_PWM);
    slice = pwm_gpio_to_slice_num(buzzer_pin);

    uint32_t wrap_value = (125000000 / (BUZZER_DIVIDER * frequency)) - 1;

    pwm_set_clkdiv(slice, BUZZER_DIVIDER);
    pwm_set_wrap(slice, wrap_value);
    pwm_set_gpio_level(buzzer_pin, 0); // Inicia com PWM zerado (buzzer desligado)
    pwm_set_enabled(slice, true);
}

void beep_dual(int buzzer1, int buzzer2, uint16_t frequency, uint32_t duration) {
    uint slice1 = pwm_gpio_to_slice_num(buzzer1);
    uint slice2 = pwm_gpio_to_slice_num(buzzer2);

    if (frequency > 0) {
        uint32_t wrap_value = (125000000 / (BUZZER_DIVIDER * frequency)) - 1;

        // Configuração para ambos os buzzers
        pwm_set_wrap(slice1, wrap_value);
        pwm_set_gpio_level(buzzer1, wrap_value / 2);
        
        pwm_set_wrap(slice2, wrap_value);
        pwm_set_gpio_level(buzzer2, wrap_value / 2);
    } else {
        pwm_set_gpio_level(buzzer1, 0);
        pwm_set_gpio_level(buzzer2, 0);
    }

    sleep_ms(duration);

    pwm_set_gpio_level(buzzer1, 0);
    pwm_set_gpio_level(buzzer2, 0);
}

void victory_sound() {
    beep_dual(BUZZER_A, BUZZER_B, 1200, 2000);
    sleep_ms(20);
    beep_dual(BUZZER_A, BUZZER_B, 1600, 1000);
}

void defeat_sound() {
    beep_dual(BUZZER_A, BUZZER_B, 400, 2000);
    sleep_ms(20);
    beep_dual(BUZZER_A, BUZZER_B, 200, 1000);
}