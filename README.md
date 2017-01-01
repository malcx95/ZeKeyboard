# ZeKeyboard

ZeKeyboard is a 60% RGB-backlit mechanical keyboard, 
with 3D-printed body and custom firmware. This repository contains 
all the source code for the firmware, as well as the 3D-models of the keyboard.

![alt text](https://github.com/malcx95/ZeKeyboard/blob/master/images/keyboard_usage.JPG)

## Layout and body

ZeKeyboard has a 60% layout with the ANSI-style Enter-key, as well as the ISO-style
left-shift key.

The layout was partially generated using scripts and 
template OpenSCAD-files by [TheZoq2](https://github.com/TheZoq2/), which
you can find [here](https://github.com/TheZoq2/Keyboard). These OpenSCAD-files
contained the switch holes corresponding to the json-layout generated from [here](http://www.keyboard-layout-editor.com/), and were modeled further in Blender to form a keyboard
body.

## Backlight

The backlight consists of 64 Neopixels, using the FastLED library.

