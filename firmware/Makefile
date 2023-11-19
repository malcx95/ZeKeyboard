CXX = /home/malcolm/.arduino15/packages/teensy/tools/teensy-compile/11.3.1/arm/bin/arm-none-eabi-g++

CC = /home/malcolm/.arduino15/packages/teensy/tools/teensy-compile/11.3.1/arm/bin/arm-none-eabi-gcc

LINK_FLAGS = -O2 -Wl,--gc-sections,--relax -T/home/malcolm/.arduino15/packages/teensy/hardware/avr/1.58.1/cores/teensy4/imxrt1062_t41.ld -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16

CXX_FLAGS = -c -O2 -g -Wall -ffunction-sections -fdata-sections -nostdlib -MMD -std=gnu++14 -fno-exceptions -fpermissive -fno-rtti -fno-threadsafe-statics -felide-constructors -Wno-error=narrowing -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -D__IMXRT1062__ -DTEENSYDUINO=158 -DARDUINO=10607 -DARDUINO_TEENSY41 -DF_CPU=600000000 -DUSB_SERIAL_HID -DLAYOUT_US_ENGLISH

LIB_PATHS = /home/malcolm/.arduino15/packages/teensy/hardware/avr/1.58.1/cores/teensy4 /home/malcolm/.arduino15/packages/teensy/hardware/avr/1.58.1/libraries/FastLED/src /home/malcolm/.arduino15/packages/teensy/hardware/avr/1.58.1/libraries/SPI /home/malcolm/.arduino15/packages/teensy/hardware/avr/1.58.1/libraries/OctoWS2811

LIBS = $(patsubst %,-I%,$(LIB_PATHS))

HEADERS = $(wildcard *.h)

SOURCES = $(wildcard *.cpp)

build/%.o: %.cpp $(HEADERS)
	mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) $(LIBS) -c $< -o $@

TARGETS = $(patsubst %.cpp,build/%.o,$(SOURCES))

firmware.elf: $(TARGETS)
	$(CC) $(LINK_FLAGS) -o $@ $(TARGETS)

all: firmware.elf

clean:
	rm -rf build/
