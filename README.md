# ZeKeyboard

ZeKeyboard is a series of home-made RGB-backlit mechanical keyboards, 
with 3D-printed bodies and custom firmware. 3 keyboards have been made,
one with 60% layout, one with a full size layout, and most recently one
with a 60% layout plus a numpad (the "V2" keyboard). This repository contains all the source
code for the firmware, as well as the 3D-models of the keyboards.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/keyboard_usage.JPG)

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/v2.jpg)

## Layout and body

The first keyboard was the one with the 60% layout, pictured below. It uses the ANSI-style Enter-key,
as well as the ISO-style left-shift key.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/keyboard_front.JPG)

The layout for this keyboard was partially generated using scripts and 
template OpenSCAD-files by [TheZoq2](https://github.com/TheZoq2/), which
you can find [here](https://github.com/TheZoq2/Keyboard). These OpenSCAD-files
contained the switch holes corresponding to the json-layout generated from 
[here](http://www.keyboard-layout-editor.com/), and were modeled further
in Blender to form a keyboard body.

The layout for the fullsize keyboard (picture unavailable) and the V2 keyboard (pictured below)
could not be generated using the aforementioned script, so they were manually modeled
in Blender from the json-layout generated from [here](http://www.keyboard-layout-editor.com/).
The V2 body also features carbon fibre handrests.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/v2_side.jpg)

## Switches

All keyboards use Gateron Brown mechanical switches, which are very similar to 
Cherry MX Brown, in the sense that they have tactile feedback without a click. These
particular switches are the SMD-LED-compatible ones, meaning they have a white body
with clear top, and a large hole for an SMD-LED to shine through.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/keycapoff.JPG)

## Backlight

The backlight consists of Adafruit Neopixel RGB-LEDs. Each LED is hot-glued in place
right below each switch to shine through the 
hole in the switch, lighting up the keycap. This lights
each keycap up more uniformly than LED:s mounted right below the keycap.
On the 60% and V2 keyboard are also two extra LED:s for the spacebar, to the left and right of the main LED.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/key_press.JPG)

On the V2 keyboard, there are three LED:s shining inside a cavity in the handrest, illuminating
the ZeKeyboard logo.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/v2_logo.jpg)

## Controller

For the 60% keyboard, the controller used is a Teensy 3.2. I could have chosen a cheaper Teensy, like
Teensy LC, but I wanted enough computing power for the effects I was going to implement.
Also, at the time of purchase, I had a different approach to implementing the 
backlight (involving five TLC5940 chips), which required the extra ports available on the
more expensive Teensy 3.2.

For the other keyboards, due to the larger number of keys, a Teensy 3.5 is used, as it's faster
and has more RAM.
