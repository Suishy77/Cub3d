/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:11:01 by aminko            #+#    #+#             */
/*   Updated: 2024/02/08 17:07:06 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_cub(char *file)
{
	char *str;
	int fd;

	str = ft_strnstr(file, ".cub", ft_strlen(file));
	if ((!str || ft_strlen(str) != 4) || ft_strlen(file) <= 4)
		error_exit("No file extension", 2);
	if ((fd = open(file, O_DIRECTORY)) != -1)
		error_exit("Is a directory", 2);
	if ((fd = open(file, O_RDONLY)) == -1)
		error_exit("Invalid file", 2);
	close(fd);
}

int	main(int ac, char **av)
{
	t_all	all;

	if (ac != 2)
		error_exit("Wrong amount of arguments", 1);
	check_cub(av[1]);
	parse_data(av, &all);
	executing(&all);
}
