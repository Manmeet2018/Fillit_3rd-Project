/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 22:10:47 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/26 06:08:53 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void        free_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->size)
    {
        ft_memdel((void *)&(map->arr[i]));
        i++;
    }
    ft_memdel((void **)&(map->arr));
    ft_memdel((void **)&map);
}

void		ft_free_tetris(t_etris *tetri)
{
	int y;

	y = 0;
	while (y < tetri->length)
	{
		ft_memdel((void **)(&(tetri->piece[y])));
		y++;
	}
	ft_memdel((void **)(&(tetri->piece)));
	ft_memdel((void **)&tetri);
}

void        ft_free_list(t_list *list)
{
    t_list *temp;
    t_etris *tetris;

    while(list)
    {
        temp = list->next;
        tetris = (t_etris *)(list->content);
        ft_free_tetris(tetris);
		ft_memdel((void **)&list);
		list = temp;
    }
}
