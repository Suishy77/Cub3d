/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:10:36 by aminko            #+#    #+#             */
/*   Updated: 2024/02/08 22:46:35 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_file(char *path) /// fd dans if ok?
{
	char *str;
	int fd;

	str = ft_strnstr(path, ".xpm", ft_strlen(path));
	if ((!str || ft_strlen(str) != 4) || ft_strlen(path) <= 4)
		error_exit("Wrong texture format", 2);
	if ((fd = open(path, O_RDONLY)) == -1)
		error_exit("Couldn't open file with texture", 2);
	close(fd);
}

void	add_path(char **args, t_check *ch, t_data *data)
{
	check_file(args[1]);
	if (!ft_strncmp("NO", args[0], 3) && !ch->nt)
	{
		data->n_txt = ft_strdup(args[1]);
		ch->nt++;
	}
	else if (!ft_strncmp("SO", args[0], 3) && !ch->st)
	{
		data->s_txt = ft_strdup(args[1]);
		ch->st++;
	}
	else if (!ft_strncmp("WE", args[0], 3) && !ch->wt)
	{
		data->w_txt = ft_strdup(args[1]);
		ch->wt++;
	}
	else if (!ft_strncmp("EA", args[0], 3) && !ch->et)
	{
		data->e_txt = ft_strdup(args[1]);
		ch->et++;
	}
	else
		error_exit("Identifiers repetitive", 9);
}

void	add_txt(t_data *data, t_check *ch)
{
	char	**args;

	args = ft_split(ch->trimmed, ' ');
	free(ch->trimmed);
	ch->trimmed = NULL;
	if (args[2] || !args[0] || !args[1])
		error_exit("Wrong amount of args in texture parsing", 10);
	if (!ft_strncmp("NO", args[0], 3) || !ft_strncmp("SO", args[0], 3)
		|| !ft_strncmp("WE", args[0], 3) || !ft_strncmp("EA", args[0], 3))
		add_path(args, ch, data);
	else if (!ft_strncmp("F", args[0], 2) || !ft_strncmp("C", args[0], 2))
		add_colors(args, ch, data);
	else
		error_exit("Wrong texture identifier", 11);
	ch->amount++;
	free_tab(args);
}
