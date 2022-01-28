CC=cc
CFLAGS=-Wall -g -std=c99 -I"include"
LDFLAGS=-lglfw3 -lGL -pthread -ldl -lm -lglad

RM=rm -f

TARGET=bin/game
SRC=$(wildcard src/*.c)
BIN=$(patsubst src/%.c,bin/%.o,$(SRC))

all:	$(TARGET) clean
	./$(TARGET)

clean:
	$(RM) $(BIN)

$(TARGET): $(BIN)
	$(CC) -o $@ $^ $(LDFLAGS)

bin/%.o: src/%.c
	$(CC) -c -o $@ $^ $(CFLAGS)