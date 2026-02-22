#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN1 = 26;
const int BTN2 = 7;

int main() {
    stdio_init_all();

    gpio_init(BTN1);
    gpio_set_dir(BTN1, GPIO_IN);
    gpio_pull_up(BTN1);

    gpio_init(BTN2);
    gpio_set_dir(BTN2, GPIO_IN);
    gpio_pull_up(BTN2);

    int cnt1 = 0, cnt2 = 0;
    int last1 = 1, last2 = 1;

    while (true) {
        int b1 = gpio_get(BTN1);

        
        if (last1 == 1 && b1 == 0) {
            sleep_ms(30);  
            if (gpio_get(BTN1) == 0) {  
                cnt1++;
                printf("Botao 1: %d\n", cnt1);
            }
        }

        last1 = b1;

        int b2 = gpio_get(BTN2);

        if (last2 == 1 && b2 == 0) {
            sleep_ms(30);
            if (gpio_get(BTN2) == 0) {
                cnt2++;
                printf("Botao 2: %d\n", cnt2);
            }
        }

        last2 = b2;

        sleep_ms(1);
    }
}