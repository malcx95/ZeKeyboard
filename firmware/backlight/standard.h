#ifndef STANDARD_H
#define STANDARD_H 

#include "backlight.h"

class Standard : public Backlight {
    public:
        
        Standard(Tlc5940* tlc, Ze::Board* keyboard)

        virtual void setup();
        
};

#endif /* ifndef STANDARD_H */
