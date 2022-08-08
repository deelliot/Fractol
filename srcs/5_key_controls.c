/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_key_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 10:47:17 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/08 14:39:49 by deelliot         ###   ########.fr       */
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
	// if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	// 	handle_translation(key, win);
	// if (key == ZOOM_IN || key == ZOOM_OUT)
	// 	handle_zoom(key, win);
	// if (key == COLOUR)
	// 	handle_colour(win);
	// if (key == RESET)
	// 	handle_reset(win);
	if (key == ESC)
		esc_program(win);
	return (0);
}

void	window_key(t_win *win)
{
	char	*str[5];
	int		i;

	str[0] = "MOVE:          W, S, A, D";
	str[1] = "ZOOM:          I and O";
	str[2] = "COLOUR:        SPACE";
	str[3] = "RESET:         ENTER";
	str[4] = "QUIT:          ESC";
	i = 0;
	while (i < 5)
	{
		mlx_string_put(win->mlx, win->win, 20, 20 + (i * 15), 0xFFFFFF, str[i]);
		i++;
	}
}
