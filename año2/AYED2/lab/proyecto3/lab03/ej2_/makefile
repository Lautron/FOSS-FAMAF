CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g
#LDFLAGS = -lm
HEADERS = $(wildcard *.h)
SOURCES = $(wildcard *.c)
OBJ = $(SOURCES: .c = .o)
TARGET = mi_ejecutable

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(TARGET)
