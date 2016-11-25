#ifndef H_LED
#define H_LED 

#include "leds.h"
#include <stdint.h>

const led_t LED_DUMMY = 100;

struct LED {

//    LED(led_t port);

    bool is_dummy() const;

    led_t port;

    /*
     * Brightness value (0 - 1)
     */
    float brightness;

};

#endif 
