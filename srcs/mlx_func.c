/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:11:28 by aminko            #+#    #+#             */
/*   Updated: 2024/02/11 18:53:21 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->l_len + x * (win->bpp / 8));
	*(unsigned int *) dst = color;
}

void	right_left(t_all *all, int key_code, double move_speed)
{
	if (key_code == A_LEFT)
	{
		if ((all->m->map[(int)all->player->pos_y][(int)(all->player->pos_x - \
					all->plane->plane_x * move_speed)]) == '0')
			all->player->pos_x -= all->plane->plane_x * move_speed;
		if (all->m->map[(int)(all->player->pos_y - all->plane->plane_y * \
					move_speed)][(int)all->player->pos_x] == '0')
			all->player->pos_y -= all->plane->plane_y * move_speed;
	}
	if (key_code == D_RIGHT)
	{
		if ((all->m->map[(int)all->player->pos_y][(int)(all->player->pos_x + \
					all->plane->plane_x * move_speed)]) == '0')
			all->player->pos_x += all->plane->plane_x * move_speed;
		if (all->m->map[(int)(all->player->pos_y + all->plane->plane_y * \
					move_speed)][(int)all->player->pos_x] == '0')
			all->player->pos_y += all->plane->plane_y * move_speed;
	}
}

void	up_down(t_all *all, int key_code, double move_speed)
{
	if (key_code == W_UP || key_code == UP)
	{
		if (all->m->map[(int)all->player->pos_y][(int)(all->player->pos_x + \
					all->player->dir_x * move_speed)] == '0')
			all->player->pos_x += all->player->dir_x * move_speed;
		if (all->m->map[(int)(all->player->pos_y + all->player->dir_y * \
					move_speed)][(int)all->player->pos_x] == '0')
			all->player->pos_y += all->player->dir_y * move_speed;
	}
	if (key_code == S_DOWN || key_code == DOWN)
	{
		if (all->m->map[(int)all->player->pos_y][(int)(all->player->pos_x - \
				all->player->dir_x * move_speed)] == '0')
			all->player->pos_x -= all->player->dir_x * move_speed;
		if (all->m->map[(int)(all->player->pos_y - all->player->dir_y * \
				move_speed)][(int)all->player->pos_x] == '0')
			all->player->pos_y -= all->player->dir_y * move_speed;
	}
}

void	rotate(t_all *all, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->player->dir_x;
	all->player->dir_x = all->player->dir_x * cos(rot_speed)
		- all->player->dir_y * sin(rot_speed);
	all->player->dir_y = old_dir_x * sin(rot_speed)
		+ all->player->dir_y * cos(rot_speed);
	old_plane_x = all->plane->plane_x;
	all->plane->plane_x = all->plane->plane_x * cos(rot_speed)
		- all->plane->plane_y * sin(rot_speed);
	all->plane->plane_y = old_plane_x * sin(rot_speed)
		+ all->plane->plane_y * cos(rot_speed);
}

int	key_hook(int key_code, t_all *all)
{
	if (key_code == ESC)
		close_win(all);
	if (key_code == W_UP || key_code == S_DOWN
		|| key_code == UP || key_code == DOWN)
		up_down(all, key_code, all->player->move_speed);
	if (key_code == A_LEFT || key_code == D_RIGHT)
		right_left(all, key_code, all->player->move_speed);
	if (key_code == RIGHT)
		rotate(all, -all->player->rot_speed); //
	if (key_code == LEFT)
		rotate(all, all->player->rot_speed);
	raycast_start(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	return (0);
}
