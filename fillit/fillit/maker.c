/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 18:16:13 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/26 05:03:48 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     sqt_func(int n) // find the side of the map.
{
    int side;
    
    side = 2; 
    while(side * side < n)
        side++;
    return (side);
}

t_map   *make_map(int size) // make the map.
{
    t_map *map;
    int i;
    int j;

    map = (t_map *)malloc(sizeof(t_map));
    map->size = size;
    map->arr = (char **)malloc(sizeof(char *) * size);
    i = 0;
    while(i < size)
    {
        map->arr[i] = ft_strnew(size);
        j = 0;
        while(j < size)
        {
            map->arr[i][j] = '.';
            j++;
        }
        i++;
    }
    return(map);
}

t_map   *solve(t_list * list) // solve map by caling solve_map function
{
    int size;
    t_map *map;

    size = sqt_func(ft_len_lst(list) * 4);
    map = make_map(size);
    while (!solve_map(map, list))
    {
        size++;
        free_map(map);
        map = make_map(size);
    }
    return (map);
}
