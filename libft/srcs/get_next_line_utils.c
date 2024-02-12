/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:25:30 by aminko            #+#    #+#             */
/*   Updated: 2024/01/28 16:38:12 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_g(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
