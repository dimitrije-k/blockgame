CC=cc
CFLAGS=-Wall -Wno-incompatible-pointer-types -g -std=c99 -I"include"
LDFLAGS=-lglfw3 -lGL -pthread -ldl -lm -lglad

RM=rm -f

TARGET=bin/game
SRC=$(wildcard src/*.c)
BIN=$(patsubst src/%.c,bin/%.o,$(SRC))

all: $(TARGET) clean
	@echo Executing $<
	@./$(TARGET)

clean:
	@echo Removing $(words $(BIN)) files
	@$(RM) $(BIN)

$(TARGET): $(BIN)
	@echo Linking $@
	@$(CC) -o $@ $^ $(LDFLAGS)

bin/%.o: src/%.c
	@echo Compiling $@
	@$(CC) -c -o $@ $^ $(CFLAGS)