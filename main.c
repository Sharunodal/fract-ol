/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:25:14 by arissane          #+#    #+#             */
/*   Updated: 2024/08/14 10:42:10 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_input(t_fract *fractol, char **argv)
{
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		fractol->set = 1;
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		fractol->set = 2;
		if (argv[2] && is_number(argv[2]) == 0)
			fractol->julia_c1 = ft_atod(argv[2], 0, 1.0, 0.1);
		if (argv[3] && is_number(argv[3]) == 0)
			fractol->julia_c2 = ft_atod(argv[3], 0, 1.0, 0.1);
	}
	else if (ft_strncmp(argv[1], "tricorn", 8) == 0)
		fractol->set = 3;
	else
	{
		error_message();
		free_window(fractol);
	}
	render(fractol, 0, 0, 0);
}

static void	initialize(t_fract *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	f->img = mlx_new_image(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	f->data_addr = mlx_get_data_addr(f->img, &f->pixel_bits,
			&f->line_bytes, &f->endian);
	f->colour = 0x1155FF;
	f->palette = NULL;
	f->x_min = -2.0;
	f->x_max = 2.0;
	f->y_min = -2.0;
	f->y_max = 2.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->zoom = 1.0;
	f->set = 0;
	f->colour_set = 1;
	f->julia_c1 = -0.839;
	f->julia_c2 = 0.193;
	f->iter = 40;
}

int	main(int argc, char **argv)
{
	t_fract	fractol;

	if (argc < 2 || validate(argv) == -1)
	{
		error_message();
		return (0);
	}
	initialize(&fractol);
	set_palette(&fractol);
	check_input(&fractol, argv);
	mlx_hook(fractol.win, 17, 0, end_event, &fractol);
	mlx_key_hook(fractol.win, key_press, &fractol);
	mlx_mouse_hook(fractol.win, mouse_event, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
