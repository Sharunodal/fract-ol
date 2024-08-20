/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:55:32 by arissane          #+#    #+#             */
/*   Updated: 2024/08/06 12:05:23 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	shading2(int colour, double fraction)
{
	int	set[3];

	set[0] = (colour >> 16) & 0xFF;
	set[1] = (colour >> 8) & 0xFF;
	set[2] = (colour >> 0) & 0xFF;
	set[0] = (set[0]) * fraction;
	set[1] = (set[1]) * fraction;
	set[2] = (set[2]) * fraction;
	return (0xFF << 24 | set[0] << 16 | set[1] << 8 | set[2]);
}

static void	shading(t_fract *fractol)
{
	int		i;
	double	fraction;

	i = 0;
	while (i < (fractol->iter - 1))
	{
		fraction = (double)i / fractol->iter;
		fractol->palette[i] = shading2(fractol->colour, fraction);
		i++;
	}
	while (i < fractol->iter)
	{
		fractol->palette[i] = 0xFFFFFF;
		i++;
	}
	fractol->palette[i] = 0;
}

static void	multiplied(t_fract *fractol)
{
	int	i;

	i = 0;
	while (i < fractol->iter)
	{
		fractol->palette[i] = fractol->colour * i;
		i++;
	}
	fractol->palette[i] = 0;
}

void	set_palette(t_fract *fractol)
{
	if (fractol->palette)
		free(fractol->palette);
	fractol->palette = malloc(sizeof(int) * fractol->iter + 1);
	if (!fractol->palette)
		free_window(fractol);
	if (fractol->colour_set == 1)
		multiplied(fractol);
	if (fractol->colour_set == 2)
		shading(fractol);
}
