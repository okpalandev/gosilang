# Variables
CC = gcc
CFLAGS = -I -MMD -Wall -Wextra -Werror -g -O0 -std=c2x -Wpedantic
OBJDIR = obj
SRCDIR = core
TARGET = main

# Source and object files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Create obj directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Rule to build the main target
$(TARGET): $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Include dependencies
-include $(OBJS:.o=.d)

# Clean rule
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Phony targets
.PHONY: all clean
