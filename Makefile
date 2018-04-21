# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcherend <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 13:09:00 by dcherend          #+#    #+#              #
#    Updated: 2018/04/20 13:32:58 by dcherend         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= fillit

LIB_DIR 		= ./libft/
LIB_HDR_DIR 	= ./libft/include/
OBJ_DIR 		= ./obj/
SRC_DIR 		= ./src/
HDR_DIR 		= ./include/

CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra -I$(HDR_DIR) -I$(LIB_HDR_DIR)

SRC 			= 	alt_solution.c figure_utils.c ft_create_el.c \
					ft_print_matrix.c ft_read_figures.c \
        			test.c throw_error.c validation.c memory_management.c
OBJ 			= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIB_BIN 		= $(LIB_DIR)libft.a
LIB_FLAGS 		= -lft -L$(LIB_DIR)
LIB 			= $(MAKE) -C $(LIB_DIR)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) $(LIB_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(LIB):
	make -C $(LIB_DIR)

clean:
	/bin/rm -rf $(OBJ_DIR)
	make clean -C $(LIB_DIR)
fclean: clean
	/bin/rm -rf $(OBJ)
	/bin/rm -rf $(NAME)
	make fclean -C $(LIB_DIR)
re: fclean all
