/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <maparmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 14:59:32 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/26 06:20:56 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
typedef struct s_tetris
{
	char	**piece;
	int		length;
	int		breadth;
	char	c;
} 			t_etris;

typedef struct s_point
{
	int		x;
	int		y;
}			point;

typedef struct s_map
{
	int		size;
	char	**arr;
}			t_map;

t_list		*r_tetris(int fd);
t_etris		*get_piece(char *str, char value);
void		find_max_min(char *s, point *min, point *max);
int			check_piece(char *str, int res);
static int	valid_connection(char *str);
t_etris		*tetris_new(char **pos, int l, int b, char value);
point		*point_new(int a, int b);
void		ft_reverse_list(t_list **alst);
int			sqt_func(int n);
t_map		*make_map(int size);
t_map		*solve(t_list * list);
int			solve_map(t_map *map, t_list *list);
void 		put_piece(t_etris *tetri, t_map *map, point *point, char c);
int			check_place(t_etris *tetri, t_map *map, int i, int j);
int			solve_map(t_map *map, t_list *list);
int			ft_len_lst(t_list *l);
void		free_map(t_map *map);
void        ft_free_list(t_list *list);

#endif
