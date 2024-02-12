/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:57:25 by aminko            #+#    #+#             */
/*   Updated: 2024/01/28 17:24:54 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	char	*pointer;

	pointer = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (pointer == NULL)
		return (NULL);
	temp = pointer;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = '\0';
	return (pointer);
}
