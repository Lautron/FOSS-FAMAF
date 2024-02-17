CC = gcc
GDB = gdb
VAL = valgrind
CFLAGS = -Wall -Werror -Wextra -ansi -pedantic -std=gnu11 -g `pkg-config --cflags --libs glib-2.0`
VFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes -s
EXCLUDE= ../../mybash.c ../../parsing.c  # Files to exclude when compiling, use it for incomplete modules
TMP_SOURCES = $(wildcard ../../*.c) 
TEST_SOURCE= builtin_test.c # The test source
SOURCES = $(filter-out $(EXCLUDE),$(TMP_SOURCES))  # This command excludes files present in EXCLUDE from SOURCE
SOURCES += $(TEST_SOURCE)
HEADERS = $(SOURCES:.c=.h)
OBJECTS = $(SOURCES:.c=.o)
TARGET = test # Name of executable
ARGS = # Args to run executable

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(TARGET)
	./$^ $(ARGS)

gdb: $(TARGET)
	$(GDB) --args ./$^ $(ARGS)
	
val: $(TARGET)
	$(VAL) $(VFLAGS) ./$^ $(ARGS)

.PHONY: clean

clean:
	rm -f $(OBJECTS) $(TARGET)

