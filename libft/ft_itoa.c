/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:12:54 by arissane          #+#    #+#             */
/*   Updated: 2024/05/11 09:23:21 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	length(int n)
{
	int		len;
	long	a;

	len = 0;
	a = n;
	if (a < 0 || a == 0)
	{
		a = -a;
		len++;
	}
	while (a > 0)
	{
		len++;
		a = a / 10;
	}
	return (len);
}

static char	*addnb(char *str, int n, int len, int sign)
{
	if (n == -2147483648)
	{
		str[len] = '8';
		n = 214748364;
		len--;
	}
	if (len == 0)
		str[len] = n + 48;
	while (len >= 0)
	{
		if (sign < 0 && len == 0)
			str[len] = '-';
		else
			str[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	len = length(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	str[len] = '\0';
	len--;
	str = addnb(str, n, len, sign);
	return (str);
}
