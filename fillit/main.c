/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:18:31 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/26 02:06:07 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void print_map(t_map *map) // print the whole map 
{
	int i;

	i = 0;
	while(i < map->size)
	{
		ft_putstr(map->arr[i]);
		ft_putchar('\n');
		i++;
	}
}

int main(int ac, char **av)
{
	t_list *list; // kill me
	t_map *map; // kill me

	if (ac !=2)
	{
		ft_putstr("usage: input_file\n");
		return(1);
	}
	if (!(list = r_tetris(open(av[1], O_RDONLY))))
	{
		ft_putstr("error\n");
		return (1);
	}
	map = solve(list);
	print_map(map);
	free_map(map);  // make me 
	ft_free_list(list); // make me 
	return (0);
}