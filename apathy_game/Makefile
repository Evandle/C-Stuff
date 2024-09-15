# Name of the executable
TARGET = game

# Source files
SOURCES = text_ad.c data.c map.c

# Compiler flags
CFLAGS = -g  # Add -g for debugging

# Compiler
CC = gcc

# Default target that compiles the program
all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Clean target to remove the compiled program
clean:
	rm -f $(TARGET)
