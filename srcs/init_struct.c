/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:11:23 by aminko            #+#    #+#             */
/*   Updated: 2024/02/11 16:57:47 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_check(t_check *ch)
{
	ch->amount = 0;
	ch->nt = 0;
	ch->st = 0;
	ch->wt = 0;
	ch->et = 0;
	ch->floor = 0;
	ch->ceiling = 0;
	ch->line = NULL;
	ch->trimmed = NULL;
	ch->fd = -1;
}

void	init_player(t_all *all)
{
	t_ch_map	*check;

	check = malloc(sizeof(t_ch_map));
	check->amount = 0;
	check->e = 0;
	check->n = 0;
	check->s = 0;
	check->w = 0;
	check->space_l = 0;
	all->checker = check;
}

void	init_data(t_all *all)
{
	all->s_tex = malloc(sizeof(t_win));
	all->w_tex = malloc(sizeof(t_win));
	all->e_tex = malloc(sizeof(t_win));
	all->n_tex = malloc(sizeof(t_win));
	my_img_to_xpm(all->win, all->data->s_txt, all->s_tex);
	my_img_to_xpm(all->win, all->data->n_txt, all->n_tex);
	my_img_to_xpm(all->win, all->data->e_txt, all->e_tex);
	my_img_to_xpm(all->win, all->data->w_txt, all->w_tex);
	all->player->move_speed = MOVESPEED;
	all->player->rot_speed = ROTSPEED;
}
