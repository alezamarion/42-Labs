/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shm_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 03:58:11 by joeduard          #+#    #+#             */
/*   Updated: 2023/01/15 19:48:07 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

static int    get_shared_block(char *file, int size, int segment)
{
    key_t    key;

    key = ftok((char *)file, (int)segment);
    if (key == ERROR)
        return (ERROR);
    return (shmget(key, size, 0644 | IPC_CREAT));
}

void    *attach_memory_block(char *file, int size, int segment)
{
    int    shared_block_id;

    shared_block_id = get_shared_block(file, size, segment);
    if (shared_block_id == ERROR)
        return (NULL);
    return (shmat(shared_block_id, NULL, 0));
}

short    detach_memory_block(void *block)
{
    return (shmdt(block) != ERROR);
}

short    destroy_memory_block(char *file, int segment)
{
    int    shared_block_id;

    shared_block_id = get_shared_block(file, 0, segment);
    if (shared_block_id == ERROR)
        return (0);
    return (shmctl(shared_block_id, IPC_RMID, NULL) != ERROR);
}