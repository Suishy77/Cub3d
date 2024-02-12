/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:11:50 by aminko            #+#    #+#             */
/*   Updated: 2024/02/08 22:49:58 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	error_exit(char *str, int num)
{
	printf("Error:\n     %s", str);
	exit(num);
}

void	print_tab(t_map *m)
{
	char	**map;

	map = m->map;
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
}

char	*ft_spaces_str(int width, int len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (width - len + 1));
	while (i < width - len)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	skip_empty_shit(t_check *ch)
{
	ch->trimmed = ft_strtrim(ch->line, " \t\v\f\r");
	if (ch->trimmed && *(ch->trimmed))
	{
		free(ch->trimmed);
		return ;
	}
	if (ch->line)
		free(ch->line);
	if (ch->trimmed)
		free(ch->trimmed);
	while (get_next_line(ch->fd, &ch->line))
	{
		ch->trimmed = ft_strtrim(ch->line, " \t\v\f\r");
		if (ch->trimmed && *(ch->trimmed))
		{
			free(ch->trimmed);
			break ;
		}
		free(ch->line);
		ch->line = NULL;
		free(ch->trimmed);
		ch->trimmed = NULL;
	}
	if (!ch->line || !*(ch->line))
		error_exit("Error with map data!", 6);
}
