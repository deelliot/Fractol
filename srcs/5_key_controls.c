/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_key_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:47:17 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/11 17:31:52 by deelliot         ###   ########.fr       */
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
	double x;
	double y;

	if (key == ZOOM_IN)
		win->zoom = 1.0/1.01;
	else
		win->zoom = 1.01/1.0;
	x = ft_linear_conversion(win->width_range, win->x_range, win->x_range.median);
	y = ft_linear_conversion(win->height_range, win->y_range, win->y_range.median);
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
		if (win->max_iter >10)
			win->max_iter -=10;
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
		handle_zoom(key, win);
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

void	window_key(t_win *win)
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
