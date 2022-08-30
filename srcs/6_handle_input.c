/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_handle_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:09:59 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/30 13:10:19 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	esc_program(t_win *win)
{
	free_win(win);
	exit(1);
}

int	handle_input(int key, t_win *win)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		handle_translation(key, win);
	if (key == ZOOM_IN || key == ZOOM_OUT)
		handle_zoom(key, -1, -1, win);
	if (key == COLOUR)
		handle_colour(win);
	if (key == ITER_UP || key == ITER_DOWN)
		handle_iterations(key, win);
	if (key == POWER)
		handle_power(win);
	if (key == RESET)
		handle_reset(win);
	if (key == ESC)
		esc_program(win);
	return (0);
}

int	mouse_input(int mouse, int x, int y, t_win *win)
{
	if (mouse == SCROLL_UP || mouse == SCROLL_DOWN)
		handle_zoom(mouse, x, y, win);
	if (mouse == MOUSE_LEFT)
	{
		if (win->lock == 1)
			win->lock = 0;
		else
			win->lock = 1;
	}
	if (mouse == MOUSE_RIGHT)
	{
		win->fractol_option += 1;
		if (win->fractol_option == 6)
			win->fractol_option = 0;
		mlx_clear_window(win->mlx, win->win);
		fractal_positions(win);
		execute_image(win);
	}
	return (0);
}

int	mouse_motion(int x, int y, t_win *win)
{
	if (win->lock == 0)
	{
		win->mouse_x = ft_linear_conversion(win->width_range, \
			win->x_range, (double)x);
		win->mouse_y = ft_linear_conversion(win->height_range, \
			win->y_range, (double)y);
		mlx_clear_window(win->mlx, win->win);
		execute_image(win);
	}
	return (0);
}

void	handle_power(t_win *win)
{
	win->power += 1;
	if (win->power == 10)
		win->power = -5;
	if (win->power == -1)
		win->power = 2;
	mlx_clear_window(win->mlx, win->win);
	execute_image(win);
}