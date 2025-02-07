#include "pico/stdlib.h"       
#include "modules/globals.h"

void setup_buttons() {
    init_button(BTN_A);
    init_button(BTN_B);
}
void init_button(int btn) {
  gpio_init(btn);
  gpio_set_dir(btn, GPIO_IN);
  gpio_pull_up(btn);
}

