/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 02:54:14 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/15 03:58:34 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABS_H
# define LABS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <locale.h>
# include <stdbool.h>
# include "structs.h"
# include <unistd.h>

//compress_file.c
void	compress_file(char str[]);
void    unzip_file(t_node *root);

//compress.c
char *code (char **dictionary, unsigned char *text);

//decompress.c
char    *decode(char text[], t_node *root);

//dictionary.c
char    **allocate_dictionary(int colunms);
void    generate_dictionary(char **dict, t_node *root, char *path, int column);
void    print_dictionary(char **dictionary);

//frequency_table.c
void	initialize_table(unsigned int tab[]);
void	fill_frequency_table(unsigned char text[], unsigned int tab[]);
void	print_frequecy_table(unsigned int tab[]);

//huffman_tree.c
t_node	*remove_first_node(t_list *list);
t_node	*mount_tree(t_list *list);
void	print_tree(t_node *root, int tam);
int     tree_height(t_node  *root);

//sorted_list.c
void	creat_list(t_list *list);
void	insert_in_order(t_list *list, t_node *node);
void	fill_list(unsigned int tab[], t_list *list);
void	print_list(t_list *list);

//test.c
int     get_file_size();

//utils.c
void    free_table(char **table);
void    free_tree(t_node *root);
void	read_text(unsigned char *text);
void	init_data(t_huff *data);

#endif