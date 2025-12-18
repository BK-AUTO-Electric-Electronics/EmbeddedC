CC = gcc
CFLAGS = -Wall -Wextra -Iinc

SRC = src/main.c src/math_utils.c src/error_handler.c
OBJ = $(SRC:.c=.o)

TARGET = app.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f $(OBJ) $(TARGET)