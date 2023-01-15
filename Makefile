# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 02:52:20 by joeduard          #+#    #+#              #
#    Updated: 2023/01/14 22:29:18 by joeduard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=
ENCODER 	=	encoder
DECODER		= 	decoder

CC			=	gcc

FLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address 

INC			=	-I ./includes

decoder		=	decoder.c decompress.c
encoder		=	compress.c dictionary.c encoder.c frequency_table.c huffman_tree.c sorted_list.c
utils		=	test.c utils.c


FILES		=	$(addprefix decoder/, $(decoder)) \
				$(addprefix encoder/, $(encoder)) \
				$(addprefix utils/, $(utils))


SRC			=	$(FILES)
OBJ			=	$(addprefix $(OBJ_DIR)/, $(FILES:.c=%.o))

all:		$(ENCODER) $(DECODER)

$(NAME): all

$(NAME):	$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj/decoder
	@mkdir -p obj/encoder
	@mkdir -p obj/utils
	$(CC) $(FLAGS) $(INC) -c $< -o $@


run: encoder
	./$(ENCODER)

run: decoder
	./$(DECODER)

clean:
	@rm -rf obj
	@echo "Objects files deleted."

fclean:		clean
	@rm -f $(NAME)
	@echo "Executable deleted."

norm:
	norminette src

add: fclean
		git add .
		git status

re:			fclean all

.PHONY: all, clean, fclean, re