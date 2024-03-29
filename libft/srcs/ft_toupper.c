/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminko <aminko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:54:59 by aminko            #+#    #+#             */
/*   Updated: 2022/11/09 13:54:56 by aminko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** Converts an lower-case letter to the corresponding upper-case letter.
** The argument must be representable as an unsigned char or the value of EOF.
** Difference between 'A' and 'a' in ASCII is 32.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* int main(void)
{
	int c = 'c';
	printf("%c", ft_toupper(c));
	return (0);
}
 */
