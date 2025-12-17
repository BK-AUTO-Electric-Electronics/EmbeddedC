
CC = gcc
CFLAGS = -Iproject/inc -Wall
SRC = project/src/main.c project/src/error_handler.c project/src/math_utils.c
OBJ = $(SRC:.c=.o)
TARGET = main.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /f /q project\src\*.o $(TARGET)