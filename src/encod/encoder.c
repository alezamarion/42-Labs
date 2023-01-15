/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:46:01 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/15 03:53:14 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/labs.h"

int	main(void)
{
    t_huff huff;

	init_data(&huff);
	   // MAIN ENCODER
	huff.size = get_file_size();
	printf("\t\nQUANTIDADE CARACTERES: %d\n", huff.size);
	huff.text = calloc(huff.size + 2, sizeof(unsigned char));
	read_text(huff.text);
	printf("\nTEXTO: \n%s\n", huff.text);

//-------------------parte 1: Tabela de Frequencia---------------------
	initialize_table(huff.frequecy_table);
	fill_frequency_table(huff.text, huff.frequecy_table);
	print_frequecy_table(huff.frequecy_table);
//-------------------parte 2: Lista Encadeada Ordenada---------------------
	creat_list(&huff.list);
	fill_list(huff.frequecy_table, &huff.list);
	print_list(&huff.list);
//-------------------parte 3: Montar a Árvore de Huffman---------------------
	huff.tree = mount_tree(&huff.list);
	printf("\n\t---ARVORE DE HUFFMAM---\n");
	print_tree(huff.tree, 0);
//-------------------parte 4: Montar um dicionario---------------------
	huff.colunms = tree_height(huff.tree) + 1;
	printf("ALTURA: %d\n", huff.colunms);
	huff.dictionary = allocate_dictionary(huff.colunms);
	generate_dictionary(huff.dictionary, huff.tree, "", huff.colunms);
	print_dictionary(huff.dictionary);

//-------------------parte 5: codificar--------------------
	huff.encoded = code(huff.dictionary, huff.text);
	printf("\n\tTEXTO CODIFICADO: \n%s\n", huff.encoded);
	
//-------------------parte 6: compactar--------------------
	compress_file(huff.encoded);

    return(0);
}