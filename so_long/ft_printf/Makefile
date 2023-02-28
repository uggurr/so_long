SRCS = ft_void_pointer.c \
	ft_printf.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_unsigned.c \
	ft_low_x.c \
	ft_upp_x.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
all: ${NAME}
$(NAME): ${OBJS}
	ar rc $(NAME) $(OBJS)
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
