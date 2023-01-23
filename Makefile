# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 02:52:20 by joeduard          #+#    #+#              #
#    Updated: 2023/01/15 19:45:52 by azamario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

 
ENCODER = encoder
DECODER = decoder

OBJECTS_DIR = ./obj
SOURCE_DIR = ./src
INCLUDE_DIR = ./includes

SOURCES =	shm_memory.c decompress.c compress.c dictionary.c frequency_table.c \
				huffman_tree.c sorted_list.c test.c utils.c

ENCODER_SOURCES = src/src_enc/encoder.c
DECODER_SOURCES = src/src_dec/decoder.c

SUB_DIRS = $(shell find $(SOURCE_DIR) -type d)
VPATH = $(OBJECTS_DIR) $(SOURCE_DIR) $(SUB_DIRS)
OBJECTS = $(addprefix $(OBJECTS_DIR)/, $(SOURCES:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 -g3 -I$(INCLUDE_PATH)

all: $(ENCODER) $(DECODER)

$(ENCODER): $(OBJECTS)
	cc $(CFLAGS) $(INCLUDE_DIR) $(ENCODER_SOURCES) $(OBJECTS) -o $(ENCODER)

$(DECODER): $(OBJECTS)
	cc $(CFLAGS) $(INCLUDE_DIR) $(DECODER_SOURCES) $(OBJECTS) -o $(DECODER)

$(OBJECTS_DIR)/%.o: %.c
	mkdir -p $(OBJECTS_DIR)
	cc $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJECTS_DIR)
	rm -r *.jrg

fclean: clean
	rm -f $(ENCODER)
	rm -f $(DECODER)

re: fclean all

.PHONY: all clean fclean re