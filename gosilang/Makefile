# Makefile for GosiLang (Gossip Programming Language)
CC := gcc
CFLAGS := -I$(INCLUDE_DIR) -MMD -Wall -Wextra -Werror -g -O0 -std=c2x -Wpedantic
LDFLAGS:= -lm

# Directories
SRC_DIR := core
OBJ_DIR := /obj
BIN_DIR := /bin
INCLUDE_DIR := include

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/**/*.c)

# Header files
HEADER_FILES := $(wildcard $(INCLUDE_DIR)/**/*.h)

# Object files
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

ifeq ($(OS),Windows_NT)
		MKDIR := @mkdir $(subst /,\,$(dir $@)) 2> NUL || exit 0	
else
		MKDIR := @mkdir -p
endif

# Executable name
ifeq ($(OS),Windows_NT)
    EXECUTABLE := $(BIN_DIR)/gosi.exe
else
    EXECUTABLE := $(BIN_DIR)/gosi
endif

all: $(EXECUTABLE)

# Build rule
$(EXECUTABLE): $(OBJ_FILES)
	$(MKDIR) $(BIN_DIR)
	@echo "Compiling" $(EXECUTABLE)
	$(CC) $(OBJ_FILES) $(SRC_DIR)/main.c -o $@ $(LDFLAGS)

# Compile rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	$(MKDIR) $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


# Clean target
clean:
ifeq ($(OS),Windows_NT)
	@rm -R  $(OBJ_DIR) $(EXECUTABLE)
else
	@rm -rf $(OBJ_DIR) $(EXECUTABLE)
endif

# Include dependency files
-include $(OBJ_FILES:$(OBJ_DIR)/%.o=$(OBJ_DIR)/%.d)

.PHONY: all clean
