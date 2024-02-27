# Compiler
CC := gcc

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INCLUDE_DIR :=  $(SRC_DIR)/include

# Source files (excluding main.c)
SRC_FILES :=  $(wildcard $(SRC_DIR)/*.c)

# Header files
HEADER_FILES := $(wildcard $(INCLUDE_DIR)/*.h) $(wildcard $(INCLUDE_DIR)/**/*.h)

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

# Rule to link object files into executable
$(EXECUTABLE): $(OBJ_FILES) | $(INCLUDE_FILES)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

# Rule to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	$(CC) $(CFLAGS) -c $< -o $@



# Clean target
clean:
	@rm -f $(OBJ_DIR)/*.o $(EXECUTABLE)

# Include dependency files
-include $(OBJ_FILES:.o=.d)

.PHONY: all clean


