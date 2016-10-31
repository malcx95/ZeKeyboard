#include <Arduino.h>
#include "backlight.h"
#include <stdint.h>
#include "list.h"

namespace Ze {

    const int MODIFIER_SHIFT = -1;
    const int MODIFIER_CTRL = -2;
    const int MODIFIER_ALT = -3;
    const int MODIFIER_SUPER = -4;
    const int MODIFIER_FN = -5;

    struct Key {

        LED* led;
        int code;
        bool is_modifier();
    
    };

    class Keyboard {

        public:

            Keyboard();
            ~Keyboard();

            void update();

        private:
    
    };

};
