NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

CFLAGS += -I ./includes

FLAGS_MLX = -lmlx -framework OpenGL -framework AppKit

PRINT_LIB = ft_printf/libftprintf.a

SRCS_SL = echeck.c get_next_line.c get_next_line_utils.c map_checker.c positions.c utils.c chooseimg.c moves.c messages.c error.c main.c checkers.c

SRCS = $(addprefix src/, $(SRCS_SL))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(FLAGS_MLX) $(PRINT_LIB) -o $(NAME)

clean:
	@make clean -C ft_printf
	rm -f $(OBJS)

fclean:	clean
	@make fclean -C ft_printf
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
