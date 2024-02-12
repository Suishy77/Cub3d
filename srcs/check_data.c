/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:10:27 by aminko            #+#    #+#             */
/*   Updated: 2024/02/12 14:40:16 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_spaces(t_all *all, char **map, int i, int j) // symbol: zero or player
{
	if (check_symbol(all, map, i, j - 1)
		|| check_symbol(all, map, i, j + 1)
		|| check_symbol(all, map, i + 1, j)
		|| check_symbol(all, map, i - 1, j)
		|| check_symbol(all, map, i + 1, j + 1)
		|| check_symbol(all, map, i - 1, j + 1)
		|| check_symbol(all, map, i + 1, j - 1)
		|| check_symbol(all, map, i - 1, j - 1))
		error_exit("Zero symbol found in wrong place", 3);
}

void	check_line_spaces(t_all *all, char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != ' ')
		{
			if (all->checker->space_l == 1)
				error_exit("Space line inside the map", 4);
			return ;
		}
		j++;
	}
	all->checker->space_l = 1; // 1 space line accepted?!
}

void	check_map(t_all *all)
{
	char		**map;
	int			i;
	int			j;

	i = -1;
	map = all->m->map;
	while (map[i] && (++i < all->m->height))
	{
		j = -1;
		check_line_spaces(all, map, i);
		while (map[i][++j] && j < all->m->width)
		{
			if (map[i][j] == ' ')
				check_spaces(all, map, i, j);
			else if (map[i][j] == '0')
				check_corners(all, i, j);
			else if (map[i][j] == '1')
				;
			else if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				check_one_player(all, map, i, j);
			else
				error_exit("Invalid symbol in map", 5);
		}
	}
}
