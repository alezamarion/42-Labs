/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:46:01 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/17 02:35:55 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

int	main(void)
{
    t_huff huff;

	
	unsigned int *block;

	init_data(&huff);

	huff.size = get_file_size();
	huff.text = calloc(huff.size + 2, sizeof(unsigned char));
	read_text(huff.text);

//-------------------parte 1: Tabela de Frequencia---------------------
	initialize_table(huff.frequecy_table);
	fill_frequency_table(huff.text, huff.frequecy_table);
	block = (unsigned int *)attach_memory_block("/bin/ls", SIZEBLOCK, 1);
	memcpy(block, huff.frequecy_table, sizeof(int) * 256);
//-------------------parte 2: Lista Encadeada Ordenada---------------------
	creat_list(&huff.list);
	fill_list(huff.frequecy_table, &huff.list);

//-------------------parte 3: Montar a Árvore de Huffman---------------------
	huff.tree = mount_tree(&huff.list);

//-------------------parte 4: Montar um dicionario---------------------
	huff.colunms = tree_height(huff.tree) + 1;
	huff.dictionary = allocate_dictionary(huff.colunms);
	generate_dictionary(huff.dictionary, huff.tree, "", huff.colunms);

//-------------------parte 5: codificar--------------------
	huff.encoded = code(huff.dictionary, huff.text);

//-------------------parte 6: compactar--------------------
	compress_file(huff.encoded);
	detach_memory_block(block);

	free(huff.text);
	free(huff.encoded);
	free(huff.decoded);
	free_tree(huff.tree);
	free_table(huff.dictionary);

    return(0);
}