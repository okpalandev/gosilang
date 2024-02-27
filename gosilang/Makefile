# Makefile for gosilang project

# Compiler
CC := gcc

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INCLUDE_DIR := $(SRC_DIR)/include
# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler flags
CFLAGS := -Wall -Wextra -Wpedantic -g -MMD -I$(INCLUDE_DIR) -std=c2x

# Linker flags
LDFLAGS :=

# Executable name
EXECUTABLE := $(BIN_DIR)/gosi

# Main target
all: $(EXECUTABLE)

# Rule to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into executable
$(EXECUTABLE): $(OBJ_FILES)
	@$(CC) $(LDFLAGS) $^ -o $@

# Clean target
clean:
	@rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)

# Include dependency files
-include $(OBJ_FILES:.o=.d)

.PHONY: all clean
