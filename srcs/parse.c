/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:11:35 by aminko            #+#    #+#             */
/*   Updated: 2024/02/12 14:31:18 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	continue_truc(t_map *m, t_all *all, t_list *head)
{
	m->map[++all->i] = NULL;
	m->height = all->height;
	m->width = all->width;
	all->m = m;
	free_list(head);
}

void	make_map_tab(t_all *all, t_list *lst, int height, int width) // makes empty map
{
	t_list	*head;
	t_map	*m;
	char	*tmp;

	all->i = -1;
	m = malloc(sizeof(t_map));
	m->map = malloc(sizeof(char *) * (height + 1));
	head = lst;
	while (lst)
	{
		if ((int)ft_strlen(lst->content) < width)
		{
			tmp = ft_spaces_str(width, ft_strlen(lst->content));
			m->map[++all->i] = ft_strjoin(lst->content, tmp);
			free(tmp);
		}
		else
			m->map[++all->i] = ft_strdup(lst->content);
		free(lst->content);
		lst = lst->next;
	}
	continue_truc(m, all, head);
}

void	keep_parsing(t_all *all, t_list *lst)
{
	make_map_tab(all, lst, all->height, all->width); //empty
	init_player(all);
	check_map(all); // TODO: check_map is correct or no
	check_player(all);
}

void	parse_map(t_check *ch, t_all *all)
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ch->line));
	all->width = ft_strlen(ch->line);
	all->height = 1;
	while (get_next_line(ch->fd, &ch->line))
	{
		ft_lstadd_back(&lst, ft_lstnew(ch->line));
		all->temp = ft_strlen(ch->line);
		if (all->temp > all->width)
			all->width = all->temp;
		all->height++;
	}
	if (all->height != 1)
	{
		ch->trimmed = ft_strtrim(ch->line, " \t\n");
		if (*(ch->trimmed))
		{
			ft_lstadd_back(&lst, ft_lstnew(ch->line));
			all->height++;
		}
		free(ch->trimmed);
	}
	keep_parsing(all, lst);
}

void	parse_data(char **av, t_all *all)
{
	t_data	*data;
	t_check	ch;

	init_check(&ch);
	data = malloc(sizeof(t_data));
	if (!data)
		error_exit("Malloc error", 21);
	ch.fd = open(av[1], O_RDONLY);
	if (ch.fd == -1)
		error_exit("Couldn't open the file", 22);
	while (get_next_line(ch.fd, &ch.line) && ch.amount < 6)
	{
		ch.trimmed = ft_strtrim(ch.line, " \t\v\f\r");
		free(ch.line);
		if (ch.trimmed && *(ch.trimmed))
			add_txt(data, &ch);
		else if (ch.trimmed)
			free(ch.trimmed);
	}
	if (ch.amount < 6)
		error_exit("Not enough data", 23);
	skip_empty_shit(&ch);
	parse_map(&ch, all);
	all->data = data;
	close(ch.fd);
}
