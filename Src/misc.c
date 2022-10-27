#include <stdint.h>

#include "misc.h"


void sleep_s(uint32_t s)
{
    uint32_t iterations_in_1_s = 1000000;
    for (uint32_t i = 0; i < (iterations_in_1_s * s); i++);
}

void sleep_us(uint32_t us)
{
    for (uint32_t i = 0; i < us; i++);
}

void sleep_dot(uint32_t d)
{
    uint32_t iterations_in_dot = 500000;
    for (uint32_t i = 0; i < (iterations_in_dot * d); i++);
}
