/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeduard <joeduard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:48:11 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/14 21:51:23 by joeduard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/labs.h"

int	main(void)
{
  t_huff huff;
    	//MAIN DECODER
 
//-------------------parte 7: decompactar--------------------
	printf("\n\tARQUIVO DESCOMPACTADO:\n");
	unzip_file(huff.tree);

//-------------------parte 8: decodificar--------------------
	huff.decoded = decode(huff.encoded, huff.tree);
	printf("\n\tTEXTO DECODIFICADO: \n%s\n", huff.decoded);

//-------------------Liberando memória---------------------
	free(huff.text);
	free(huff.encoded);
	free(huff.decoded);
	free_tree(huff.tree);
	free_table(huff.dictionary);
	return (0);
}
