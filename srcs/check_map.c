/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:10:46 by aminko            #+#    #+#             */
/*   Updated: 2024/02/12 14:52:33 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_player(t_all *all)
{
	if (all->checker->e == 0 && all->checker->w == 0
		&& all->checker->s == 0 && all->checker->n == 0)
		error_exit("No player on the map", 12);
}

void	check_corners(t_all *all, int i, int j)
{
	if (i == 0 || i == all->m->height - 1 || j == 0 || j == all->m->width)
		error_exit("Zero is found in a corner. Wrong map", 13);
}

int	check_symbol(t_all *all, char **map, int i, int j)
{
	return ((i >= 0 && i < all->m->height) && (j >= 0 && j < all->m->width)
		&& (map[i][j] == '0' || map[i][j] == 'N'
		|| map[i][j] == 'E' || map[i][j] == 'W'
		|| map[i][j] == 'S'));
}

int	check_is_zero(t_all *all, char **map, int i, int j)
{
	return ((i >= 0 && i < all->m->height)
		&& (j >= 0 && j < all->m->width) && map[i][j] == '0');
}

void	check_one_player(t_all *all, char **map, int i, int j)
{
	if (i == 0 || i == all->m->height)
		error_exit("Player in the wrong place", 14); // lil map not working
	if (map[i][j] == 'N' && all->checker->n == 0)
		all->checker->n++;
	else if (map[i][j] == 'E' && all->checker->e == 0)
		all->checker->e++;
	else if (map[i][j] == 'W' && all->checker->w == 0)
		all->checker->w++;
	else if (map[i][j] == 'S' && all->checker->s == 0)
		all->checker->s++;
	else
		error_exit("Something wrong with player", 15);
	if (all->checker->n + all->checker->e + all->checker->s
		+ all->checker->w > 1)
		error_exit("There should be one player", 15);
	if (!check_is_zero(all, map, i, j - 1)
		&& !check_is_zero(all, map, i, j + 1)
		&& !check_is_zero(all, map, i + 1, j)
		&& !check_is_zero(all, map, i - 1, j))
		error_exit("Player surrounded by walls. Wrong map", 16);
	player_to_struct(all, i, j, map[i][j]);
}


/*
1111111111
1N00000001
1010000101
1000000001
1111111111
 */
