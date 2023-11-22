ARDUINO_PATH = ${ARDUINO_DIR}
ARDUINO_PACKAGES = $(ARDUINO_PATH)/packages
TEENSY_DIR = $(ARDUINO_PACKAGES)/teensy
TEENSY_TOOLS = $(TEENSY_DIR)/tools
TEENSY_HARDWARE = $(TEENSY_DIR)/hardware

LIBRARIES_VERSION = 1.58.1
TEENSY_AVR = $(TEENSY_HARDWARE)/avr/$(LIBRARIES_VERSION)
TEENSY_LIBS = $(TEENSY_AVR)/libraries
TEENSY4_CORE = $(TEENSY_AVR)/cores/teensy4

TEENSY_COMPILE_VERSION = 11.3.1
TEENSY_COMPILE = $(TEENSY_TOOLS)/teensy-compile/$(TEENSY_COMPILE_VERSION)/arm/bin

CXX = $(TEENSY_COMPILE)/arm-none-eabi-g++
CC = $(TEENSY_COMPILE)/arm-none-eabi-gcc
AR = $(TEENSY_COMPILE)/arm-none-eabi-gcc-ar
PRECOMPILE_HELPER = $(TEENSY_TOOLS)/teensy-tools/1.58.0/precompile_helper
OBJCOPY = $(TEENSY_COMPILE)/arm-none-eabi-objcopy
POST_COMPILE = $(TEENSY_TOOLS)/teensy-tools/1.58.0/teensy_post_compile

PRECOMPILE_FLAGS = -x c++-header -O2 -g -Wall -ffunction-sections -fdata-sections -nostdlib -MMD -std=gnu++14 -fno-exceptions -fpermissive -fno-rtti -fno-threadsafe-statics -felide-constructors -Wno-error=narrowing -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -D__IMXRT1062__ -DTEENSYDUINO=158 -DARDUINO=10607 -DARDUINO_TEENSY41 -DF_CPU=600000000 -DUSB_SERIAL_HID -DLAYOUT_US_ENGLISH -I$(TEENSY4_CORE)

LINK_FLAGS = -O2 -Wl,--gc-sections,--relax -T$(TEENSY_HARDWARE)/avr/1.58.1/cores/teensy4/imxrt1062_t41.ld -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16

CXX_FLAGS = -c -O2 -g -Wall -ffunction-sections -fdata-sections -nostdlib -MMD -std=gnu++14 -fno-exceptions -fpermissive -fno-rtti -fno-threadsafe-statics -felide-constructors -Wno-error=narrowing -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -D__IMXRT1062__ -DTEENSYDUINO=158 -DARDUINO=10607 -DARDUINO_TEENSY41 -DF_CPU=600000000 -DUSB_SERIAL_HID -DLAYOUT_US_ENGLISH

CC_FLAGS = -c -O2 -g -Wall -ffunction-sections -fdata-sections -nostdlib -MMD -mthumb -mcpu=cortex-m7 -mfloat-abi=hard -mfpu=fpv5-d16 -D__IMXRT1062__ -DTEENSYDUINO=158 -DARDUINO=10607 -DARDUINO_TEENSY41 -DF_CPU=600000000 -DUSB_SERIAL_HID -DLAYOUT_US_ENGLISH

OBJCOPY_FLAGS = -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0

LIB_SRC = FastLED/src SPI OctoWS2811

LIB_PATHS = $(patsubst %,$(TEENSY_LIBS)/%,$(LIB_SRC)))

INCLUDE_LIBS = -Ibuild/pch -I$(TEENSY4_CORE) $(patsubst %,-I$(TEENSY_LIBS)/%,$(LIB_SRC))

FASTLED_HEADERS = $(wildcard $(TEENSY_LIBS)/FastLED/src/*.h)
SPI_HEADERS = $(wildcard $(TEENSY_LIBS)/SPI/*.h)
OCTOWS2811_HEADERS = $(wildcard $(TEENSY_LIBS)/OctoWS2811/*.h)

CORE_HEADERS = $(wildcard $(TEENSY4_CORE)/*.h)
LIB_HEADERS = $(FASTLED_HEADERS) $(SPI_HEADERS) $(OCTOWS2811_HEADERS)
HEADERS = $(wildcard *.h)

FASTLED_SOURCES = $(wildcard $(TEENSY_LIBS)/FastLED/src/*.cpp)
SPI_SOURCES = $(wildcard $(TEENSY_LIBS)/SPI/*.cpp)
OCTOWS2811_SOURCES = $(wildcard $(TEENSY_LIBS)/OctoWS2811/*.cpp)

CORE_CPP_SOURCES = $(wildcard $(TEENSY4_CORE)/*.cpp)
CORE_C_SOURCES = $(wildcard $(TEENSY4_CORE)/*.c)
LIB_SOURCES = $(FASTLED_SOURCES) $(SPI_SOURCES) $(OCTOWS2811_SOURCES)
SOURCES = $(wildcard *.cpp)

all: build/firmware.hex

build/pch/Arduino.h.gch:
	mkdir -p $(@D)
	$(PRECOMPILE_HELPER) $(TEENSY4_CORE) build/ $(CXX) $(PRECOMPILE_FLAGS) build/pch/Arduino.h -o build/pch/Arduino.h.gch

build/core/%.cpp.o: %.cpp $(CORE_HEADERS)
	mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) $(INCLUDE_LIBS) -c $< -o $@
	$(AR) rcs build/core/core.a $@

build/core/%.c.o: %.c $(CORE_HEADERS)
	mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -I$(TEENSY4_CORE) -c $< -o $@
	$(AR) rcs build/core/core.a $@

CORE_C_TARGETS =  $(patsubst %.c,build/core/%.c.o,$(CORE_C_SOURCES))
CORE_CPP_TARGETS =  $(patsubst %.cpp,build/core/%.cpp.o,$(CORE_CPP_SOURCES))
build/core/core.a: $(CORE_CPP_TARGETS) $(CORE_C_TARGETS)

build/libraries/%.o: %.cpp $(LIB_HEADERS) build/pch/Arduino.h.gch
	mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) $(INCLUDE_LIBS) -c $< -o $@

build/%.o: %.cpp $(HEADERS) build/pch/Arduino.h.gch
	mkdir -p $(@D)
	$(CXX) $(CXX_FLAGS) $(INCLUDE_LIBS) -c $< -o $@

TARGETS = $(patsubst %.cpp,build/%.o,$(SOURCES)) $(patsubst %.cpp,build/libraries/%.o,$(LIB_SOURCES)) build/core/core.a

build/firmware.elf: $(TARGETS)
	$(CC) $(LINK_FLAGS) -o $@ $(TARGETS) build/core/core.a -Lbuild/ -larm_cortexM7lfsp_math -lm -lstdc++

build/firmware.hex: build/firmware.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

upload: build/firmware.hex
	teensy_loader_cli --mcu=TEENSY41 -w build/firmware.hex

clean:
	rm -rf build/
