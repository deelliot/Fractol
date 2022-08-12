/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_handle_input_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:47:17 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/12 17:12:46 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_translation(int key, t_win *win)
{
	if (key == UP)
		win->y_offset += 10;
	if (key == DOWN)
		win->y_offset -= 10;
	if (key == LEFT)
		win->x_offset += 10;
	if (key == RIGHT)
		win->x_offset -= 10;
	mlx_clear_window(win->mlx, win->win);
	execute_image(win);
}

void	handle_zoom(int key, t_win *win)
{
	double	x;
	double	y;

	if (key == ZOOM_IN)
		win->zoom = 1.0 / 1.01;
	else
		win->zoom = 1.01 / 1.0;
	x = ft_linear_conversion(win->width_range, win->x_range, \
		win->x_range.median);
	y = ft_linear_conversion(win->height_range, win->y_range, \
		win->y_range.median);
	win->x_range.max = x + ((win->x_range.max - x) * win->zoom);
	win->x_range.min = x + ((win->x_range.min - x) * win->zoom);
	win->y_range.max = y + ((win->y_range.max - y) * win->zoom);
	win->y_range.min = y + ((win->y_range.min - y) * win->zoom);
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
	win->x_offset = 0.0;
	win->y_offset = 0.0;
	win->colour = 0x060C0F;
	win->x_range = ft_create_range(-2.00, 0.47);
	win->y_range = ft_create_range(-1.12, 1.12);
	mlx_clear_window(win->mlx, win->win);
	execute_image(win);
}
