/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:11:18 by aminko            #+#    #+#             */
/*   Updated: 2024/02/12 14:50:27 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	dir_2(char direction, t_all *all)
{
	if (direction == 'S')
	{
		all->player->dir_x = 0;
		all->player->dir_y = 1;
		all->plane->plane_x = 0.66;
		all->plane->plane_y = 0;
	}
	else if (direction == 'N')
	{
		all->player->dir_x = 0;
		all->player->dir_y = -1;
		all->plane->plane_x = -0.66;
		all->plane->plane_y = 0;
	}
}

void	get_dir(char direction, t_all *all)
{
	if (direction == 'W')
	{
		all->player->dir_x = -1;
		all->player->dir_y = 0;
		all->plane->plane_x = 0;
		all->plane->plane_y = 0.66;
	}
	else if (direction == 'E')
	{
		all->player->dir_x = 1;
		all->player->dir_y = 0;
		all->plane->plane_x = 0;
		all->plane->plane_y = -0.66;
	}
	else if (direction == 'S' || direction == 'N')
		dir_2(direction, all);
}

void	player_to_struct(t_all *all, int i, int j, char direction)
{
	t_player	*player;
	t_plane		*plane;

	player = malloc(sizeof(t_player));
	plane = malloc(sizeof(t_plane));
	all->plane = plane;
	player->pos_x = j + 0.5; // centre de la case
	player->pos_y = i + 0.5;
	all->m->map[i][j] = '0';
	all->player = player;
	get_dir(direction, all);
}
