/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:11:07 by aminko            #+#    #+#             */
/*   Updated: 2024/02/11 18:42:02 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_fc(t_all *all, int x)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < all->rc->draw_start)
		{
			my_mlx_pixel_put(all->win, x, y, create_rgb(all->data->ceiling[0], \
					all->data->ceiling[1], all->data->ceiling[2]));
		}
		else if (y >= all->rc->draw_end)
		{
			my_mlx_pixel_put(all->win, x, y, create_rgb(all->data->floor[0], \
					all->data->floor[1], all->data->floor[2]));
		}
		++y;
	}
}

void	print_map(int x, t_all *all)
{
	if (all->rc->side == 0)
	{
		all->rc->wall_x = all->player->pos_y + all->rc->perp_wall_dist * \
				all->rc->ray_dir_y;
	}
	else
	{
		all->rc->wall_x = all->player->pos_x + all->rc->perp_wall_dist * \
				all->rc->ray_dir_x;
	}
	all->rc->wall_x -= floor((all->rc->wall_x));
	draw_walls(all, x);
	draw_fc(all, x);
}

void	executing(t_all *all)
{
	all->win = malloc(sizeof(t_win));
	all->rc = malloc(sizeof(t_raycast));
	all->win->mlx = mlx_init();
	init_data(all);
	all->win->win = mlx_new_window(all->win->mlx, WIDTH, HEIGHT, "Cub3D");
	all->win->img = mlx_new_image(all->win->mlx, WIDTH, HEIGHT);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bpp,
			&all->win->l_len, &all->win->end);
	raycast_start(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
	mlx_do_key_autorepeaton(all->win->mlx);
	mlx_hook(all->win->win, 2, 0x1, key_hook, all);
	mlx_hook(all->win->win, 33, (1L << 17), close_win, all);
	mlx_loop(all->win->mlx);
}
