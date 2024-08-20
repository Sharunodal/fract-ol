/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:39:50 by arissane          #+#    #+#             */
/*   Updated: 2024/05/11 09:24:44 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long long int	check_number(const char *str, long long int a,
								long long int number, int sign)
{
	long long int	check;

	while (str[a] >= '0' && str[a] <= '9')
	{
		check = number;
		number = number * 10;
		if (sign == 1 && check != (number / 10))
			return (-1);
		if (sign == -1 && check != (number / 10))
			return (0);
		number = number + (str[a] - 48);
		a++;
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	long long int	a;
	long long int	number;
	int				sign;

	a = 0;
	number = 0;
	sign = 1;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign = -1;
		a++;
	}
	if (str[a] >= '0' && str[a] <= '9')
		number = check_number(str, a, number, sign);
	return (sign * number);
}
