# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 02:52:20 by joeduard          #+#    #+#              #
#    Updated: 2023/01/15 04:14:17 by azamario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=
ENCODER 	=	encoder
DECODER		= 	decoder

CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address 

INC			=	-I ./includes

SRC_DIR		=	./src
OBJ_DIR		=	./obj

DECOD		=	decoder.c decompress.c
ENCOD		=	compress.c dictionary.c encoder.c frequency_table.c huffman_tree.c sorted_list.c
UTILS		=	test.c utils.c


FILES		=	$(addprefix decod/, $(DECOD)) \
				$(addprefix encod/, $(ENCOD)) \
				$(addprefix utils/, $(UTILS))

SRC			=	$(addprefix $(SRC_DIR)/, $(FILES))

OBJ			=	$(subst $(SRC_DIR)/, $(OBJ_DIR)/, $(SRC:.c=.o))

all:	$(ENCODER) $(DECODER)

$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p obj/decod
	@mkdir -p obj/encod
	@mkdir -p obj/utils
	$(CC) $(FLAGS) $(INC) -c $< -o $@

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