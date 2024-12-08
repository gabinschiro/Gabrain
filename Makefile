TARGET = bin/gabrain
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

CC = gcc
CFLAGS = -Wall -Wextra -std=c23 -I$(INCLUDE_DIR)

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(dir $@)
	$(CC) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild
