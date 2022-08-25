/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_handle_input_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:47:17 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/25 12:39:38 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_translation(int key, t_win *win)
{
	int	inc;

	if (win->fractol_option == 4)
		inc = 1;
	else
		inc = 10;
	if (key == UP)
		win->y_offset += inc;
	if (key == DOWN)
		win->y_offset -= inc;
	if (key == LEFT)
		win->x_offset += inc;
	if (key == RIGHT)
		win->x_offset -= inc;
	mlx_clear_window(win->mlx, win->win);
	execute_image(win);
}

void	handle_zoom(int key, int x, int y, t_win *win)
{
	double	x_axis;
	double	y_axis;

	if (x == -1)
		x = win->width_range.median;
	if (y == -1)
		y = win->height_range.median;
	if (key == ZOOM_IN || key == SCROLL_UP)
		win->zoom = 0.9;
	else
		win->zoom = 1.1;
	x_axis = ft_linear_conversion(win->width_range, win->x_range, \
		x + win->x_offset);
	y_axis = ft_linear_conversion(win->height_range, win->y_range, \
		y + win->y_offset);
	win->x_range.max = x_axis + ((win->x_range.max - x_axis) * win->zoom);
	win->x_range.min = x_axis + ((win->x_range.min - x_axis) * win->zoom);
	win->y_range.max = y_axis + ((win->y_range.max - y_axis) * win->zoom);
	win->y_range.min = y_axis + ((win->y_range.min - y_axis) * win->zoom);
	mlx_clear_window(win->mlx, win->win);
	execute_image(win);
}

void	handle_colour(t_win *win)
{
	win->colour += 1;
	if (win->colour == 5)
		win->colour = 0;
	mlx_clear_window(win->mlx, win->win);
	execute_image(win);
}

void	handle_iterations(int key, t_win *win)
{
	if (key == ITER_UP)
		win->max_iter += 10;
	if (key == ITER_DOWN)
	{
		if (win->max_iter > 10)
			win->max_iter -= 10;
	}
	mlx_clear_window(win->mlx, win->win);
	execute_image(win);
}

void	handle_reset(t_win *win)
{
	win->max_iter = 300;
	win->zoom = 0.0;
	win->y_offset = 0.0;
	win->colour = 0;
	win->mouse_x = -0.7269;
	win->mouse_y = 0.1889;
	win->lock = 1;
	fractal_positions(win);
	mlx_clear_window(win->mlx, win->win);
	execute_image(win);
}
