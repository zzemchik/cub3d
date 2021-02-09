NAME = cub3D
LIBSDIR = libs/


SOURCES = cub3d.c dist_a.c dist_b.c do_cub_struct.c drow_sprite.c drow_wall.c \
get_next_line.c lists.c parser.c save.c search_sprite.c search_wall.c some_functions_2.c \
some_functions.c valid_map.c what_in_line_norm.c what_in_line.c where_im.c

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