NAME = cub3D
LIBSDIR = mlx/cub3d/libs/


SOURCES = mlx/cub3d/cub3d.c mlx/cub3d/dist_a.c mlx/cub3d/dist_b.c mlx/cub3d/do_cub_struct.c \
mlx/cub3d/drow_sprite.c mlx/cub3d/drow_wall.c \
mlx/cub3d/get_next_line.c mlx/cub3d/lists.c mlx/cub3d/parser.c \
mlx/cub3d/save.c mlx/cub3d/search_sprite.c mlx/cub3d/search_wall.c mlx/cub3d/some_functions_2.c \
mlx/cub3d/some_functions.c mlx/cub3d/valid_map.c mlx/cub3d/what_in_line_norm.c mlx/cub3d/what_in_line.c \
mlx/cub3d/where_im.c

OSOURCE= $(SOURCES:.c=.o)

FLAGS = -Wall -Werror -Wextra

MLIBS = -lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)
%.o: %.c
	gcc -c $< $(FLAGS) -o $@ -I
$(NAME): $(OSOURCE)
	gcc -o $(NAME) $(MLIBS) $(OSOURCE) -I

clean:
	@rm -rf $(OSOURCE)

fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: clean fclean all