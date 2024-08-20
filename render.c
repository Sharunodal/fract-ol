/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:52:55 by arissane          #+#    #+#             */
/*   Updated: 2024/08/14 10:26:36 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	colour_pixel(t_fract *fractol, int x, int y, int colour)
{
	fractol->data_addr[x * 4 + y * 4 * WIN_WIDTH] = colour;
	fractol->data_addr[x * 4 + y * 4 * WIN_WIDTH + 1] = colour >> 8;
	fractol->data_addr[x * 4 + y * 4 * WIN_WIDTH + 2] = colour >> 16;
	fractol->data_addr[x * 4 + y * 4 * WIN_WIDTH + 3] = colour >> 24;
}

static double	scale_nb(double pos, double new_min,
		double new_max, double old_max)
{
	double	old_min;
	double	result;

	old_min = 0;
	result = (new_max - new_min) * (pos - old_min)
		/ (old_max - old_min) + new_min;
	return (result);
}

void	render(t_fract *f, int x, int y, int k)
{
	double	scale_x;
	double	scale_y;

	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			scale_x = scale_nb((double)x, f->x_min, f->x_max,
					(double)WIN_WIDTH) * f->zoom + f->shift_x;
			scale_y = scale_nb((double)y, f->y_min, f->y_max,
					(double)WIN_HEIGHT) * f->zoom + f->shift_y;
			k = check_set(f, scale_x, scale_y);
			if (k == f->iter)
				colour_pixel(f, x, y, 0x000000);
			else
				colour_pixel(f, x, y, f->palette[k]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
