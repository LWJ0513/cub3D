CC = cc
CFLAGS = -Wall -Werror -Wextra
OPTION = -L./mlx -lmlx -framework OpenGL -framework AppKit
NAME = cub3D
RM = rm -rf

MANDATORY = $(addprefix srcs/, $(SRCS))
MANDATORY_PAR = $(addprefix srcs/parsing/, $(SRCS_PAR))
MANDATORY_EXE = $(addprefix srcs/execute/, $(SRCS_EXE))

SRCS_PAR = \
	ft_error.c \
	parsing.c \
	init_data.c \
	check_identifier.c \
	validate_map.c \
	set_map.c\

SRCS_EXE =  \
	open_window.c \
	key_press.c \
	calc.c \
	wall.c
	
SRCS =  \
	main.c 


OBJS = $(MANDATORY:c=o) $(MANDATORY_EXE:c=o) $(MANDATORY_PAR:c=o) $(MANDATORY:c=o)

%.o : %c
	$(CC) $(OPTION) $(CFLAGS) -c -o $@ $^

$(NAME) : $(OBJS)
	$(MAKE) -C ./libft/
	cd mlx && $(MAKE)
	$(CC) $(OPTION) $(CFLAGS) -o $@ $^ ./libft/libft.a

all : $(NAME)

clean :
	$(MAKE) -C ./libft/ clean
	$(MAKE) -C ./mlx/ clean
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) -C ./libft/ fclean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re