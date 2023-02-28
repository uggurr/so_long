NAME        := so_long
CC        := gcc
FLAGS    := -Wall -Wextra -Werror

SRCS        :=            libft/ft_strnstr.c \
                          libft/ft_isdigit.c \
                          libft/ft_lstadd_back.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_lstnew.c \
                          libft/ft_strlcpy.c \
                          libft/ft_strlen.c \
                          libft/ft_lstlast.c \
                          libft/ft_memcmp.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_lstclear.c \
                          libft/ft_lstiter.c \
                          libft/ft_strchr.c \
                          libft/ft_striteri.c \
                          libft/ft_bzero.c \
                          libft/ft_strjoin.c \
                          libft/ft_isascii.c \
                          libft/ft_memcpy.c \
                          libft/ft_isprint.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_lstsize.c \
                          libft/ft_toupper.c \
                          libft/ft_split.c \
                          libft/ft_lstadd_front.c \
                          libft/ft_strrchr.c \
                          libft/ft_isalpha.c \
                          libft/ft_memchr.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_memset.c \
                          libft/ft_substr.c \
                          libft/ft_strncmp.c \
                          libft/ft_strmapi.c \
                          libft/ft_strtrim.c \
                          libft/ft_memmove.c \
                          libft/ft_strlcat.c \
                          libft/ft_calloc.c \
                          libft/ft_strdup.c \
                          libft/ft_atoi.c \
                          libft/ft_isalnum.c \
                          libft/ft_lstdelone.c \
                          libft/ft_itoa.c \
                          libft/ft_tolower.c \
                          ft_printf/ft_low_x.c \
                          ft_printf/ft_printf.c \
                          ft_printf/ft_putchar.c \
                          ft_printf/ft_putnbr.c \
                          ft_printf/ft_putstr.c \
                          ft_printf/ft_unsigned.c \
                          ft_printf/ft_upp_x.c \
                          ft_printf/ft_void_pointer.c \
                          object_check.c \
                          wall_check.c \
                          ft_mlx.c \
                          so_long.c \
                          error.c \
                          get_next_line/get_next_line_utils.c \
                          get_next_line/get_next_line.c \
                          accessible_check.c \
                          accessible_check2.c \
                          opened_check.c \
                          key_move.c \

OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}
RM		    := rm -f
$(NAME): ${OBJS}
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit

all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1


fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a

re:			fclean all

.PHONY:		all clean fclean re
