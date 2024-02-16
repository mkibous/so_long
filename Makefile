SRCS =	so_long.c get_next_line_utils.c get_next_line.c \
	chek.c graph.c idl.c path.c

B_SRCS =	so_long_bonus.c get_next_line_utils.c get_next_line.c \
	chek.c graph_bonus.c idl.c monster_bonus.c path.c

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = libft/libft.a
PRINT = printf/libftprintf.a
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
OBJ = $(SRCS:.c=.o)
B_OBJ = $(B_SRCS:.c=.o)
all: $(LIBFT) $(PRINT) $(NAME)

$(LIBFT) : libft/Makefile
	cd libft && make
$(PRINT) : printf/Makefile
	cd printf && make
bonus:$(LIBFT) $(PRINT) $(B_OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(B_OBJ) $(MLXFLAGS) -o so_long

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINT) $(OBJ) $(MLXFLAGS) -o $(NAME)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

clean_libft : libft/Makefile printf/Makefile
	cd libft && make clean
	cd printf && make clean
clean: clean_libft
	$(RM) $(OBJ) $(B_OBJ)
fclean_libft : libft/Makefile printf/Makefile
	cd libft && make fclean
	cd printf && make fclean
fclean: clean fclean_libft
	$(RM) $(NAME)
re : fclean all