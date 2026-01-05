CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = automotive_manager
SRCS = main.c \
       module_manager.c \
       function_handler.c \
       bitmask_utils.c \
       error_handler.c
OBJS = $(SRCS:.c=.o)
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)
rebuild: clean all