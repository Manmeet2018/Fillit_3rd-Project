/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:22:30 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/26 06:24:01 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void put_piece(t_etris *tetri, t_map *map, point *p, char c)
{
    int a;
    int b;

    a = 0;
    while(a < tetri->breadth)
    {
        b = 0;
        while(b < tetri->length)
        {
            if(tetri->piece[b][a] == '#')
                map->arr[p->y + b][p->x + a] = c;
            b++;
        }
        a++;
    }
	ft_memdel((void **)&p);
}

int check_place(t_etris *tetri, t_map *map, int i, int j)
{
    int a;
    int b;

    a = 0;
    while(a < tetri->breadth)
    {
        b = 0;
        while(b < tetri->length)
        {
            if(tetri->piece[b][a] == '#' && map->arr[j + b][i + a] != '.')
                return (0);
            b++;
        }
        a++;
    }
	put_piece(tetri, map, point_new(i, j), tetri->c);
    return (1);
}

int solve_map(t_map *map, t_list *list)
{
    int i;
    int j;
    t_etris *tetri;

    if(list == NULL)
        return (1);
    tetri = (t_etris *)list->content;
    j = 0;
    while(j < map->size - tetri->length + 1)
    {
        i = 0;
        while(i < map->size - tetri->breadth + 1)
        {
            if (check_place(tetri, map, i, j))
            {
                if (solve_map(map, list->next))
                    return (1);
                else
                    put_piece(tetri, map, point_new(i, j), '.');
            }
            i++;
        }
        j++;
    }
    return (0);
}
