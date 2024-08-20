/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:28:00 by arissane          #+#    #+#             */
/*   Updated: 2024/04/26 11:43:24 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*str;
	unsigned char	c2;

	a = 0;
	str = (unsigned char *) s;
	c2 = (unsigned char) c;
	while (a < n)
	{
		if (str[a] == c2)
			return ((void *) &s[a]);
		a++;
	}
	return (NULL);
}
