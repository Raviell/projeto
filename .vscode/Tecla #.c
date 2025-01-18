// tecla_hash.c
#include "tecla_hash.h"
#include <stdio.h>
#include "pico/stdlib.h"

void handle_key_hash(uint gpio_buzzer) {
    gpio_put(gpio_buzzer, 1);
    sleep_ms(500);
    gpio_put(gpio_buzzer, 0);
}

// tecla_hash.h
#ifndef TECLA_HASH_H
#define TECLA_HASH_H

#include <stdint.h>

void handle_key_hash(uint gpio_buzzer);

#endif
