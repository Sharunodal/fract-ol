/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arissane <arissane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:26:29 by arissane          #+#    #+#             */
/*   Updated: 2024/08/14 11:07:39 by arissane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	shift_x;
	double	shift_y;
	double	julia_c1;
	double	julia_c2;
	double	zoom;
	int		*palette;
	int		colour;
	int		colour_set;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		set;
	int		iter;
}	t_fract;

int		validate(char **argv);
int		is_number(char *str);
void	error_message(void);
double	ft_atod(char *str, double number, double sign, double division);
void	free_window(t_fract *fractol);
int		key_press(int keycode, t_fract *fractol);
int		mouse_event(int keycode, int x, int y, t_fract *f);
int		end_event(t_fract *fractol);
int		check_set(t_fract *fractol, double scale_x, double scale_y);
void	set_palette(t_fract *fractol);
void	render(t_fract *f, int x, int y, int k);

#endif
