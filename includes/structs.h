/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 02:57:33 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/14 20:59:06 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define SIZE 256
typedef struct s_node
{
	unsigned char	character;
	int				frequency;
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*next;
}					t_node;
typedef struct s_list
{
	t_node			*first_node;
	int				tam;
}					t_list;

typedef struct s_huff
{
	unsigned char	*text;
	unsigned int	frequecy_table[SIZE];
	t_list			list;
	t_node			*tree;
	int				colunms;
	int				size;
	char 			**dictionary;
	char			*encoded;
	char			*decoded;
}				t_huff;

#endif