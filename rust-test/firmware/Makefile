upload:
	cargo objcopy --release -- -O ihex firmware.hex
	teensy_loader_cli --mcu=TEENSY41 -w firmware.hex

