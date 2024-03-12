# Directories
SRC_DIR := .
OBJ_DIR := ../obj
INCLUDE_DIR := $(SRC_DIR)/include

# Files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler and flags
CC := gcc
AR := ar
CFLAGS := -Wall -Wextra -Wpedantic -I$(INCLUDE_DIR) -std=c2x
LDFLAGS := -L$(OBJ_DIR)

# Targets
all: $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

.PHONY: all clean
