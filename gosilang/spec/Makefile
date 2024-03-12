# Compiler
CC := gcc

# Directories
SRC_DIR := ../src
OBJ_DIR := ../obj
BIN_DIR := ../bin
INCLUDE_DIR := ../include

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)
UNIT_TEST_FILES := $(wildcard unit/*.c)
INTEGRATION_TEST_FILES := $(wildcard integration/*.c)
ACCEPTANCE_TEST_FILES := $(wildcard acceptance/*.c)

# Object files
OBJ_FILES := $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler flags
CFLAGS := -Wall -Wextra -Wpedantic -g -MMD -I$(INCLUDE_DIR) -std=c2x

# Linker flags
LDFLAGS := -L$(BIN_DIR) -lgosi -lcriterion

# Executable name
EXECUTABLE := $(BIN_DIR)/gosi

# Main target
all: $(EXECUTABLE) test

# Rule to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile test files
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files into executable
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to compile and run unit tests
unit_test: $(UNIT_TEST_FILES:.c=.o) $(filter-out $(OBJ_DIR)/main.o, $(OBJ_FILES))
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	./unit_test

# Rule to compile and run integration tests
integration_test: $(INTEGRATION_TEST_FILES:.c=.o) $(filter-out $(OBJ_DIR)/main.o, $(OBJ_FILES))
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	./integration_test

# Rule to compile and run acceptance tests
acceptance_test: $(ACCEPTANCE_TEST_FILES:.c=.o) $(filter-out $(OBJ_DIR)/main.o, $(OBJ_FILES))
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
	./acceptance_test

# Clean target
clean:
	rm -f $(OBJ_DIR)/*.o $(EXECUTABLE) unit_test integration_test acceptance_test

# Include dependency files
-include $(OBJ_FILES:.o=.d) $(UNIT_TEST_FILES:.c=.d) $(INTEGRATION_TEST_FILES:.c=.d) $(ACCEPTANCE_TEST_FILES:.c=.d)


.PHONY: all clean unit_test integration_test acceptance_test
