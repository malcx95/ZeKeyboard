#ifndef H_LED
#define H_LED 

#include "config.h"
#ifdef SIXTY_PERCENT
    #include "ledssixty.h"
#elif defined FULLSIZE
    #include "ledsfull.h"
#endif

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

    /*
     * The index on the LEDstrip
     */
    led_t port;

    /*
     * Place for storage of variables the
     * particular effect requires, such as 
     * a WaterParticle in the WATER effect.
     */
    void* aux;

    void init();

    bool is_dummy() const;

    uint32_t get_hex_code(float brightness) const;

};

#endif 
