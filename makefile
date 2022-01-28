CC=cc
CFLAGS=-Wall -g -std=c99
LDFLAGS=-lglfw3 -lGL -pthread -ldl -lm

RM=rm -f

TARGET=bin/game
SRC=$(wildcard src/*.c)
BIN=$(patsubst src/%.c,bin/%.o,$(SRC))

.PHONY: all clean

all:	$(TARGET)
	./$(TARGET)

clean:
	$(RM) $(BIN)

$(TARGET): $(BIN)
	$(CC) -o $@ $^ $(LDFLAGS)

bin/%.o: src/%.c
	$(CC) -c -o $@ $^ $(CFLAGS)