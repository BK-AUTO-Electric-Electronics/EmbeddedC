CC = gcc
CFLAGS = -Wall -Wextra -Iinc

SRC = src/main.c src/math_utils.c src/error_handler.c
OUT = app

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

clean:
	rm -f $(OUT)
