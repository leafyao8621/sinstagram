CC = gcc
SRC = $(wildcard src/*/*.c) $(wildcard src/*/*/*.c) $(wildcard src/test.c)
OBJ = $(SRC:.c=.o)
BIN = test

%.o: %.c
	$(CC) -pedantic -Wall -Wextra -Werror -g -c $< -o $@

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $(BIN)

.PHONY: clean
clean:
	@rm $(OBJ)
	@rm $(BIN)
