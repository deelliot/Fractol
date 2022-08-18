/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_initialise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:36:08 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/18 17:05:39 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	initialise_image(t_img *img, t_win *win)
{
	img->img = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	if (!img->img)
		handle_errors(win);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->length, \
	&img->endian);
}

void	initialise_window(t_win *win, char *str)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		handle_errors(win);
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, str);
	if (!win->win)
		handle_errors(win);
	initialise_image(&win->img, win);
	win->max_iter = 300;
	win->zoom = 0.0;
	win->x_offset = 0.0;
	win->y_offset = 0.0;
	win->colour = 0;
	win->x_range = ft_create_range(-2.00, 0.47);
	win->width_range = ft_create_range(0, WIDTH);
	win->y_range = ft_create_range(-1.12, 1.12);
	win->height_range = ft_create_range(0, HEIGHT);
	win->mouse_x = -0.7269;
	win->mouse_y = 0.1889;
	win->lock = 1;
	if (win->fractol_option == 0)
	{
		win->x_offset = 320;
		win->x_range.min = -2.47;
		win->x_range.max = 0.63;
		win->y_range.min = -1.38;
		win->y_range.max = 1.43;
	}
	if (win->fractol_option == 2)
	{
		win->x_offset = 210;
		win->x_range.min = -4.4;
		win->x_range.max = 1.4;
		win->y_range.min = -1.6;
		win->y_range.max = 1.76;
	}
}
