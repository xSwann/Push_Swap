
# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g3

# Name of the executable
NAME = push_swap

# Source files
SRCS = push_swap.c \
       normalize.c \
       sorting.c \
       utils.c \
       utils2.c \
       utils3.c \
       actions/push.c \
       actions/rotate.c \
       actions/swap.c \
       actions/reverse_rotate.c \
       handler.c \
       ft_split.c

# ft_printf files
PRINTF_SRCS = ft_printf/ft_printf.c ft_printf/functions.c
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADER = header.h
PRINTF_HEADER = ft_printf/ft_printf.h

# Default target
all: $(NAME)

# Linking the program
$(NAME): $(OBJS) $(PRINTF_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF_OBJS)

# Compiling source files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Compiling ft_printf source files
ft_printf.o: ft_printf.c $(PRINTF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

functions.o: functions.c $(PRINTF_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS) $(PRINTF_OBJS)

# Clean everything including the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re