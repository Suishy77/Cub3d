/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:11:12 by aminko            #+#    #+#             */
/*   Updated: 2024/02/08 23:09:57 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	free_tab(char **tab)
{
	char	**ptdr;

	ptdr = tab;
	while (*tab)
	{
		free(*tab);
		*tab = NULL;
		tab++;
	}
	free(ptdr);
	tab = NULL;
}

void	free_memory(t_all *all) // degueulasse but brain is not braining
{
	free(all->data->e_txt);
	free(all->data->s_txt);
	free(all->data->n_txt);
	free(all->data->w_txt);
	free(all->data);
	free_tab(all->m->map);
	free(all->m);
	free(all->rc);
	free(all->checker);
	free(all->player);
	free(all->plane);
	free(all->s_tex);
	free(all->n_tex);
	free(all->w_tex);
	free(all->e_tex);
}

int	close_win(t_all *all)
{
	free_memory(all);
	mlx_destroy_image(all->win->mlx, all->win->img);
	mlx_destroy_window(all->win->mlx, all->win->win);
	free(all->win);
	printf("Game finished!\n");
	exit(0);
}

void	check_malloc(char *data, char *message, int num)
{
	if (!data)
		error_exit(message, num);
}
