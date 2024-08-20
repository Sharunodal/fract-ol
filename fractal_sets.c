/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:49:23 by arissane          #+#    #+#             */
/*   Updated: 2024/08/14 10:02:19 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot(double scale_x, double scale_y, t_fract *f)
{
	double	ty;
	double	tx;
	double	temp;
	int		k;

	ty = 0;
	tx = 0;
	temp = 0;
	k = 0;
	while (k < f->iter)
	{
		if ((tx * tx + ty * ty) > 4.0)
			break ;
		temp = 2 * tx * ty + scale_y;
		tx = tx * tx - ty * ty + scale_x;
		ty = temp;
		k++;
	}
	return (k);
}

static int	julia(double scale_x, double scale_y,
		double julia_c1, t_fract *f)
{
	double	temp;
	int		k;

	temp = 0;
	k = 0;
	while (k < f->iter)
	{
		if ((scale_x * scale_x + scale_y * scale_y) > 4.0)
			break ;
		temp = 2 * scale_x * scale_y + f->julia_c2;
		scale_x = scale_x * scale_x - scale_y * scale_y + julia_c1;
		scale_y = temp;
		k++;
	}
	return (k);
}

static int	tricorn(double scale_x, double scale_y, t_fract *f)
{
	double	ty;
	double	tx;
	double	temp;
	int		k;

	ty = 0;
	tx = 0;
	temp = 0;
	k = 0;
	while (k < f->iter)
	{
		if ((tx * tx + ty * ty) > 4.0)
			break ;
		temp = -2 * tx * ty + scale_y;
		tx = tx * tx - ty * ty + scale_x;
		ty = temp;
		k++;
	}
	return (k);
}

int	check_set(t_fract *fractol, double scale_x, double scale_y)
{
	int	k;

	if (fractol->set == 1)
		k = mandelbrot(scale_x, scale_y, fractol);
	if (fractol->set == 2)
		k = julia(scale_x, scale_y, fractol->julia_c1, fractol);
	if (fractol->set == 3)
		k = tricorn(scale_x, scale_y, fractol);
	return (k);
}
