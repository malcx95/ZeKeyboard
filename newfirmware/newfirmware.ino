#include <KeyboardController.h>
#include <MouseController.h>
#include <Usb.h>
#include <address.h>
#include <adk.h>
#include <confdescparser.h>
#include <hid.h>
#include <hidboot.h>
#include <hidusagestr.h>
#include <parsetools.h>
#include <usb_ch9.h>

#include <Keyboard.h>
#include <KeyboardLayout.h>

#include <Keyboard.h>

#include "src/firmware.hpp"
#include "test.h"

Firmware firmware;

void setup() {
    firmware.setup();
    test();
}

void loop() {
    firmware.update();
}
