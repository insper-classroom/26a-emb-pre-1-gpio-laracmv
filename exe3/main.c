#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_R = 4;
const int LED_G = 6;
const int BNT_R = 28;
const int BNT_G = 26;

int main() {
  int i_LED_R = 0;
  int i_LED_G = 0;
  stdio_init_all();

  gpio_init(LED_G);
  gpio_set_dir(LED_G, GPIO_OUT);

  gpio_init(LED_R);
  gpio_set_dir(LED_R, GPIO_OUT);

  gpio_init(BNT_G);
  gpio_set_dir(BNT_G, GPIO_IN);
  gpio_pull_up(BNT_G);

  gpio_init(BNT_R);
  gpio_set_dir(BNT_R, GPIO_IN);
  gpio_pull_up(BNT_R);

  while (true) {
    if (!gpio_get(BNT_G)){
      i_LED_G = !i_LED_G; 
      gpio_put(LED_G, i_LED_G);

      while (!gpio_get(BNT_G)){
      };

    }

    if (!gpio_get(BNT_R)){
      i_LED_R = !i_LED_R; 
      gpio_put(LED_R, i_LED_R);
      sleep_ms(200);
      
    }
  }
}
