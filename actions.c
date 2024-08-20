/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 08:44:03 by arissane          #+#    #+#             */
/*   Updated: 2024/08/14 10:13:04 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	help_message(void)
{
	ft_printf("Controls:\narrow keys : move\n");
	ft_printf("+ : zoom in\n");
	ft_printf("- : zoom out\n");
	ft_printf("mouse scroll : zoom in/out\n");
	ft_printf("J : change to julia\n");
	ft_printf("M : change to mandelbrot\n");
	ft_printf("C : change the colours\n");
	ft_printf("spacebar : change the colour palette\n");
	ft_printf("] : increase definition\n");
	ft_printf("[ : decrease definition\n");
	ft_printf("esc : exit\n");
}

static int	key_press_helper(int keycode, t_fract *fractol)
{
	if (keycode == 91 && fractol->iter > 0)
		fractol->iter -= 10;
	else if (keycode == 93 && fractol->iter < INT_MAX)
		fractol->iter += 10;
	else if (keycode == 32)
	{
		if (fractol->colour_set < 2)
			fractol->colour_set += 1;
		else
			fractol->colour_set = 1;
	}
	else if (keycode == 99)
	{
		if (fractol->colour > 1000000000)
			fractol->colour = 0x111111;
		else
			fractol->colour += 80000;
	}
	else
		return (-1);
	set_palette(fractol);
	return (0);
}

int	key_press(int keycode, t_fract *fractol)
{
	if (keycode == 65307)
		free_window(fractol);
	else if (keycode == 65362)
		fractol->shift_y -= (0.1 * fractol->zoom);
	else if (keycode == 65364)
		fractol->shift_y += (0.1 * fractol->zoom);
	else if (keycode == 65361)
		fractol->shift_x -= (0.1 * fractol->zoom);
	else if (keycode == 65363)
		fractol->shift_x += (0.1 * fractol->zoom);
	else if (keycode == 61)
		fractol->zoom *= 0.9;
	else if (keycode == 45)
		fractol->zoom *= 1.1;
	else if (keycode == 109 && fractol->set != 1)
		fractol->set = 1;
	else if (keycode == 106 && fractol->set != 2)
		fractol->set = 2;
	else if (keycode == 104)
		help_message();
	else if (key_press_helper(keycode, fractol) == -1)
		return (0);
	render(fractol, 0, 0, 0);
	return (0);
}

int	mouse_event(int keycode, int x, int y, t_fract *f)
{
	double	halfx;
	double	halfy;

	halfx = (double)WIN_WIDTH / 2;
	halfy = (double)WIN_HEIGHT / 2;
	if (keycode == 4)
	{
		if (x < halfx)
			f->shift_x -= ((halfx - (double)x) / WIN_WIDTH * f->zoom);
		else if (x > halfx)
			f->shift_x += (((double)x - halfx) / WIN_WIDTH * f->zoom);
		if (y < halfy)
			f->shift_y -= ((halfy - (double)y) / WIN_HEIGHT * f->zoom);
		else if (y > halfy)
			f->shift_y += (((double)y - halfy) / WIN_HEIGHT * f->zoom);
		f->zoom *= 0.9;
	}
	else if (keycode == 5)
		f->zoom *= 1.1;
	else
		return (0);
	render(f, 0, 0, 0);
	return (0);
}
