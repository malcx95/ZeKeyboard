#ifndef H_LED
#define H_LED 

#include "leds.h"
#include <stdint.h>

const led_t LED_DUMMY = 100;
const float MAX_BYTE = 255.0;

struct LED {

    /*
     * Red value (0.0 - 1.0)
     */
    float r;

    /*
     * Green value (0.0 - 1.0)
     */
    float g;

    /*
     * Blue value (0.0 - 1.0)
     */
    float b;

    led_t port;

    void init();

    bool is_dummy() const;

    uint32_t get_hex_code() const;

};

#endif 
