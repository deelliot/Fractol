/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_initialise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:36:08 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/29 11:36:59 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	initialise_colour(t_win *win)
{
	if (win->colour == 0)
		win->col_start = hex_to_rgb(0x0F0406);
	if (win->colour == 1)
		win->col_start = hex_to_rgb(0x060F04);
	if (win->colour == 2)
		win->col_start = hex_to_rgb(0x04060F);
	if (win->colour == 3)
		win->col_start = hex_to_rgb(0x00D9FF);
	if (win->colour == 4)
		win->col_start = hex_to_rgb(0xBDEB0A);
}

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
	win->max_iter = 300;
	win->zoom = 0.0;
	win->x_offset = 0.0;
	win->y_offset = 0.0;
	win->colour = 0;
	win->width_range = ft_create_range(0, WIDTH);
	win->height_range = ft_create_range(0, HEIGHT);
	win->mouse_x = -0.7269;
	win->mouse_y = 0.1889;
	win->lock = 1;
	fractal_positions(win);
}

/* sets x and y scale for each fractal */

static void	reset_range(t_win *win)
{
	if (win->fractol_option == 0)
	{
		win->x_range = ft_create_range(-2.47, 0.63);
		win->y_range = ft_create_range(-1.38, 1.43);
	}
	else if (win->fractol_option == 1)
	{
		win->x_range = ft_create_range(-2.00, 0.47);
		win->y_range = ft_create_range(-1.12, 1.12);
	}
	else if (win->fractol_option == 2)
	{
		win->x_range = ft_create_range(-4.4, 1.4);
		win->y_range = ft_create_range(-1.6, 1.76);
	}
	else if (win->fractol_option == 3)
	{
		win->x_range = ft_create_range(-2.5, 1);
		win->y_range = ft_create_range(-1.0, 1.0);
	}
	else
	{
		win->x_range = ft_create_range(-2.182, 2.6558);
		win->y_range = ft_create_range(0, 9.9983);
	}
}

/* positions fractal to centre of window and sets iterations*/

void	fractal_positions(t_win *win)
{
	if (win->fractol_option == 0)
	{
		win->max_iter = 300;
		win->x_offset = 320;
	}
	else if (win->fractol_option == 1)
		win->x_offset = 0;
	else if (win->fractol_option == 2)
		win->x_offset = 210;
	else if (win->fractol_option == 3)
	{
		win->max_iter = 100;
		win->x_offset = 110;
		win->y_offset = -170;
	}
	else
	{
		win->x_offset = 0;
		win->y_offset = 0;
		win->max_iter = 1000000;
	}
	reset_range(win);
}
