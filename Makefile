CC = cc -g
CFLAGS = -Wall -Werror -Wextra
OPTION = -L./mlx -lmlx -framework OpenGL -framework AppKit
NAME = cub3D
RM = rm -rf

MANDATORY = $(addprefix srcs/, $(SRCS))

SRCS =  \
	main.c \
	ft_error.c \
	parsing/init_data.c \
	parsing/check_identifier.c \

OBJS = $(MANDATORY:c=o)

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