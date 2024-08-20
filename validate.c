/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:37:29 by arissane          #+#    #+#             */
/*   Updated: 2024/08/14 11:22:07 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_message(void)
{
	ft_printf("Available fractal sets:\nmandelbrot\njulia\ntricorn\n");
	ft_printf("\nYou may also include up to two numbers with values\n");
	ft_printf("between -2 and 2 in order to change the julia set values.\n");
	ft_printf("The default values are -0.839 and 0.193\n");
	ft_printf("Example of valid input:\n");
	ft_printf("./fractol julia 0.381 -0.147\n");
}

int	is_number(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0' && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

double	ft_atod(char *str, double number, double sign, double division)
{
	int		i;

	i = 0;
	if (str[i] == '-')
	{
		sign = -1.0;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number + (str[i] - 48) * division;
		division = 0.1 * division;
		i++;
	}
	return (sign * number);
}

int	validate(char **argv)
{
	int		i;
	double	number;

	i = 2;
	while (argv[i] != NULL)
	{
		if (is_number(argv[i]) == (-1))
			return (-1);
		number = ft_atod(argv[i], 0, 1.0, 0.1);
		if (number > 2.0 || number < -2.0)
			return (-1);
		i++;
		if (i > 4)
			return (-1);
	}
	return (1);
}
