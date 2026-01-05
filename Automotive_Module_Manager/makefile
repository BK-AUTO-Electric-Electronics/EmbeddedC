CC = gcc
CFLAGS = -Wall -Wextra -Iinc
OUT = app.exe 

SRCS = \
	main.c \
	module_manager.c \
	bitmask_utils.c \
	function_handler.c \
	error_handler.c

all:
	$(CC) $(SRCS) $(CFLAGS) -o $(OUT)

clean:
	if exist $(OUT) del /F /Q $(OUT)