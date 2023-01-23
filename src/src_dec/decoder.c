/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:48:11 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/15 19:48:21 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

int	main(void)
{

unsigned int *block;
t_huff huff;

init_data(&huff);

		block = (unsigned int *)attach_memory_block("/bin/ls", 0, 1);
		
	//	print_frequecy_table(block);

	//	-------------------parte 2: Lista Encadeada Ordenada---------------------
	creat_list(&huff.list);
	fill_list(block, &huff.list);

//-------------------parte 3: Montar a Árvore de Huffman---------------------
	huff.tree = mount_tree(&huff.list);

//-------------------parte 7: decompactar--------------------
	unzip_file(huff.tree);

//-------------------Liberando memória---------------------
//	free(huff.list);
	detach_memory_block(block);
	return (0);
}
