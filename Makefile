# # Arduino Library base folder and example structure
# EXAMPLES_BASE = examples
# EXAMPLE ?= Example1_BasicReadings

# # Arduino CLI executable name and directory location
# ARDUINO_CLI = arduino-cli
# ARDUINO_CLI_DIR = .

# # Arduino CLI Board type
# BOARD_TYPE ?= arduino:avr:uno

# # Default port to upload to
# SERIAL_PORT ?= COM18

# # Optional verbose compile/upload trigger
# V ?= 0
# VERBOSE=

# # Build path -- used to store built binary and object files
# BUILD_DIR=_build
# BUILD_PATH=$(PWD)/$(EXAMPLES_BASE)/$(EXAMPLE)/$(BUILD_DIR)

# ifneq ($(V), 0)
#     VERBOSE=-v
# endif

# .PHONY: all example program clean

# all: example

# example:
#     $(ARDUINO_CLI_DIR)/$(ARDUINO_CLI) compile $(VERBOSE) --build-path=$(BUILD_PATH) --build-cache-path=$(BUILD_PATH) -b $(BOARD_TYPE) $(EXAMPLES_BASE)/$(EXAMPLE)

# program:
#     $(ARDUINO_CLI_DIR)/$(ARDUINO_CLI) upload $(VERBOSE) -p $(SERIAL_PORT) --fqbn $(BOARD_TYPE) $(EXAMPLES_BASE)/$(EXAMPLE)

# clean:
#     @rm -rf $(BUILD_PATH)
#     @rm $(EXAMPLES_BASE)/$(EXAMPLE)/*.elf
#     @rm $(EXAMPLES_BASE)/$(EXAMPLE)/*.hex


COMPILE = arduino-cli compile --fqbn arduino:avr:uno arduino-tone
UPLOAD = arduino-cli upload -p /dev/ttyUSB0 --fqbn arduino:avr:uno arduino-tone

all:
	$(COMPILE)
	$(UPLOAD)

.PHONY: all build