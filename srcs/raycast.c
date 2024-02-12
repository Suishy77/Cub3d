/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:11:42 by aminko            #+#    #+#             */
/*   Updated: 2024/02/11 18:47:08 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycast_start(t_all *all)
{
	int	x; // pixel horizontal position

	x = -1;
	while (++x < WIDTH)
	{
		all->rc->camera_x = 2 * x / (double)WIDTH - 1; // x-coordinate in camera space
		all->rc->ray_dir_x = all->player->dir_x
			+ all->plane->plane_x * all->rc->camera_x; // ray direction x
		all->rc->ray_dir_y = all->player->dir_y
			+ all->plane->plane_y * all->rc->camera_x; // y
		all->rc->map_x = (int)(all->player->pos_x); // player's x-coordinate
		all->rc->map_y = (int)(all->player->pos_y); // y
		if (all->rc->ray_dir_x == 0)
			all->rc->delt_dist_x = 1e30; // calc dist to next x
		else
			all->rc->delt_dist_x = fabs(1 / all->rc->ray_dir_x);
		if (all->rc->ray_dir_y == 0)
			all->rc->delt_dist_y = 1e30;
		else
			all->rc->delt_dist_y = fabs(1 / all->rc->ray_dir_y);
		toujour_raycast_hein(all);
		dda_algo(all);
		print_map(x, all);
	}
}

void	toujour_raycast_hein(t_all *all)
{
	t_raycast	*rc;

	rc = all->rc;
	rc->hit = 0;
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1; // if the ray is pointing towards negative x-direction
		rc->s_dist_x = (all->player->pos_x - rc->map_x) * rc->delt_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->s_dist_x = (rc->map_x + 1.0 - all->player->pos_x) * rc->delt_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->s_dist_y = (all->player->pos_y - rc->map_y) * rc->delt_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->s_dist_y = (rc->map_y + 1.0 - all->player->pos_y) * rc->delt_dist_y;
	}
	all->rc = rc;
}

void	dda_algo(t_all *all) // calculates ray collisions
{
	while (all->rc->hit == 0)
	{
		if (all->rc->s_dist_x < all->rc->s_dist_y)
		{
			all->rc->s_dist_x += all->rc->delt_dist_x;
			all->rc->map_x += all->rc->step_x;
			all->rc->side = 0;
		}
		else
		{
			all->rc->s_dist_y += all->rc->delt_dist_y;
			all->rc->map_y += all->rc->step_y;
			all->rc->side = 1;
		}
		if (all->m->map[all->rc->map_y][all->rc->map_x] == '1')
			all->rc->hit = 1;
		blabla(all);
	}
}

void	blabla(t_all *all)
{
	if (all->rc->side == 0)
		all->rc->perp_wall_dist = all->rc->s_dist_x - all->rc->delt_dist_x; // perp dist from player to wall where ray hit
	else
		all->rc->perp_wall_dist = all->rc->s_dist_y - all->rc->delt_dist_y;
	all->rc->line_height = (int)(HEIGHT / all->rc->perp_wall_dist);
	all->rc->draw_start = -all->rc->line_height / 2 + HEIGHT / 2; // wall to be drawn
	if (all->rc->draw_start < 0)
		all->rc->draw_start = 0; // start pixel pos, not extend beyond the top edge of the screen
	all->rc->draw_end = all->rc->line_height / 2 + HEIGHT / 2;
	if (all->rc->draw_end >= HEIGHT)
		all->rc->draw_end = HEIGHT - 1; // end pixel pos, not ext bottom
}
