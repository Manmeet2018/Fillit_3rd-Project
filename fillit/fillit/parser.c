/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 16:37:16 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/26 06:21:05 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************Check if the piece is valid or not*********/
#include "fillit.h"

static int valid_connection(char *str) // if the connections are valid or not
{
	int j; // check all the character piece's
	int ad_block; // will give no of adjacent block to each vallid char "#"

	j = 0;
	ad_block = 0;
	while (j < 20)
	{
		if (str[j] == '#')
		{
			if (str[j + 1] == '#' && (j + 1) < 20)
				ad_block++;
			if (str[j - 1] == '#' && (j - 1) >= 0)
				ad_block++;
			if (str[j + 5] == '#' && (j + 5) < 20)
				ad_block++;
			if (str[j - 5] == '#' && (j - 5) >= 0)
				ad_block++;
		}
		j++;
	}
	return (ad_block == 6 || ad_block == 8);
}
int check_piece(char *str, int res)
{
	int pos;
	int no_block;

	pos = 0;
	no_block = 1;
	while (pos < 20)
	{
		if (pos % 5 < 4)
		{
			if (!(str[pos] == '#' || str[pos] == '.'))
				return (1);
			if (str[pos] == '#' && no_block++ > 4)
				return (2);
		}
		else if (str[pos] != '\n')
			return (3);
		pos++;
	}
	if (res == 21 && str[20] != '\n')
		return (4);
	if (!valid_connection(str))
		return (5);
	return (0);
}

/****************check if the piece is valid or not************/

void find_max_min(char *s, point *min, point *max)
{
	int i;

	i = 0;
	while(i < 20)
	{
		if(s[i] == '#')
		{
			if(i / 5 < min->y)
			{
				min->y = i / 5;
			}
			if(i / 5 > max->y)
			{
				max->y = i / 5;
			}
			if(i % 5 < min->x)
			{
				min->x = i % 5;
			}
			if(i % 5 > max->x)
			{
				max->x = i % 5;
			}
		}
		i++;
	}
}
t_etris *get_piece(char *str, char value)
{
	char		**pos;
	int			i;
	point		*min;
	point		*max;
	t_etris		*piece;
	
	i = 0; 
	max = point_new(0, 0);
	min = point_new(3, 3);
	find_max_min(str, min, max); 
	pos = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	while(i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (min->y + i) * 5, max->x - min->x + 1);
		i++;
	}
	piece = tetris_new(pos, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void *)&min);
	ft_memdel((void *)&max);
	return (piece);
}

t_list *r_tetris(int fd) // make the list with the pieces in correct manner 
{
	t_list *list;
	int res;
	char *buff; // kill me
	char c;
	t_etris *tetris; 

	buff = ft_strnew(21);
	list = NULL;
	c = 'A';
	while((res = read(fd, buff, 21)) >= 20)
	{
		if (check_piece(buff, res) || !(tetris = get_piece(buff, c++)))
		{
			ft_memdel((void *)&buff);
			ft_free_list(list);
			return(NULL);
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_etris)));
		ft_memdel((void**)&tetris);
	}
	ft_memdel((void **)&buff);
	if (res)
	{
		ft_free_list(list);
		return (NULL);
	}
	ft_reverse_list(&list);
	return (list);
}
