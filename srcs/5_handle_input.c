/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_handle_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 17:09:59 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/18 15:16:53 by deelliot         ###   ########.fr       */
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

void	window_menu(t_win *win)
{
	char	*str[6];
	int		i;
	char	*iterations;

	str[0] = "MOVE:          W, S, A, D";
	str[1] = "ZOOM:          I and O";
	str[2] = "COLOUR:        SPACE";
	str[3] = "RESET:         ENTER";
	str[4] = "ITERATIONS:    ARROW UP & DOWN";
	str[5] = "QUIT:          ESC";
	i = 0;
	iterations = ft_itoa(win->max_iter);
	while (i < 6)
	{
		mlx_string_put(win->mlx, win->win, 20, 20 + (i * 15), 0xFFFFFF, str[i]);
		i++;
	}
	mlx_string_put(win->mlx, win->win, 1040, 20, 0xFFFFFF, iterations);
}
