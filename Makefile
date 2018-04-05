NAME = fillit

all: $(NAME)

$(NAME):
	gcc test.c ft_create_el.c ft_create_figure.c ft_print_scheme.c ft_fill_matrix.c -L./libft -lft	
