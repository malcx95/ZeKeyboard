#ifndef H_LED
#define H_LED 

#include "leds.h"
#include <stdint.h>

const led_t LED_DUMMY = 100;
const uint8_t MAX_BYTE = 255;

struct LED {

    /*
     * Brightness value (0.0 - 1.0)
     */
    float brightness;

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
