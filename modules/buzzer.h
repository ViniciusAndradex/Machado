#ifndef BUZZER_H
#define BUZZER_H

void defeat_sound();
void victory_sound();
void beep_dual(int buzzer1, int buzzer2, uint16_t frequency, uint32_t duration);
void setup_pwm_buzzer(int buzzer_pin, uint16_t frequency);

#endif