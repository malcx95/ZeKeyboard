# ZeKeyboard

ZeKeyboard is a 60% RGB-backlit mechanical keyboard, 
with 3D-printed body and custom firmware. This repository contains 
all the source code for the firmware, as well as the 3D-models of the keyboard.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/keyboard_usage.JPG)

## Layout and body

ZeKeyboard has a 60% layout with the ANSI-style Enter-key, as well as the ISO-style
left-shift key.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/keyboard_front.JPG)

The layout was partially generated using scripts and 
template OpenSCAD-files by [TheZoq2](https://github.com/TheZoq2/), which
you can find [here](https://github.com/TheZoq2/Keyboard). These OpenSCAD-files
contained the switch holes corresponding to the json-layout generated from 
[here](http://www.keyboard-layout-editor.com/), and were modeled further
in Blender to form a keyboard body.

## Switches

ZeKeyboard uses 62 Gateron Brown mechanical switches, which are very similar to 
Cherry MX Brown, in the sense that they have tactile feedback without a click. These
particular switches are the SMD-LED-compatible ones, meaning they have a white body
with clear top, and a large hole for an SMD-LED to shine through.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/keycapoff.JPG)

## Backlight

The backlight consists of 64 Adafruit Neopixel RGB-LEDs. Each LED is hot-glued in place
right below each switch to shine through the 
hole in the switch, lighting up the keycap. This lights
each keycap up more uniformly than LED:s mounted right below the keycap. There are also
two extra LED:s for the spacebar, to the left and right of the main LED.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/key_press.JPG)

## Controller

The controller used is a Teensy 3.2. I could have chosen a cheaper Teensy, like
Teensy LC, but I wanted enough computing power for the effects I was going to implement.
Also, at the time of purchase, I had a different approach to implementing the 
backlight (involving five TLC5940 chips), which required the extra ports available on the
more expensive Teensy 3.2.

