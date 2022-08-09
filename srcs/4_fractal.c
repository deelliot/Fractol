/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_fractal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:03:23 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/09 14:35:49 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

//mandelbrot x scale (-2, 0.47)
//mandelbrot y scale (-1.12, 1.12)

// f[{x, y}] = {(a^2 - b^2) + c1}, {2xy + c2}

// double	mandelbrot(t_win *win, t_complex *points)
// {
// 	double	x;
// 	double	y;
// 	double	n;
// 	int		temp;

// 	x = 0;
// 	y = 0;
// 	n = 0;

// 	points->x0 = ft_linear_conversion(ft_create_range(0, WIDTH),\
// 	ft_create_range(-2.00, 0.47), points->x);
// 	points->y0 = ft_linear_conversion(ft_create_range(0, HEIGHT),\
// 	ft_create_range(-1.12, 1.12), points->y);

// 	while (((x * x) + (y * y)) <= 4 && \
// 		n < win->max_iter)
// 	{
// 		temp = ((x * x) - (y * y)) + points->x0;
// 		y = (2 * x * y) + points->y0;
// 		x = temp;
// 		n++;
// 	}
// 	return (n);
// }

// A complex number () can be represented on a complex plane.
// The real part of the complex number is represented by a displacement along
// the x-axis and the imaginary part by a displacement along the y-axis.

// void plot_points(t_win *win)
// {
// 	// double	m;

// 	win->points.y = 0;
// 	while (win->points.y < 10)
// 	{
// 		win->points.x = 0;
// 		while (win->points.x < 10)
// 		{
// 			// m = mandelbrot(win, &win->points);
// 			// set_colour(win, m);
// 			// printf("x: %f; y: %f, colour = %d\n", win->points.x, win->points.y, win->colour);
// 			if (win->points.x == 2)
// 				win->colour = 0xFF0000;
// 			else
// 				(win->colour = 0x000000);
// 			img_pixel_put(&win->img, win->points.x, win->points.y, 0xFF0000);
// 			win->points.x++;
// 		}
// 		win->points.y++;
// 	}
// 	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 360, 540);
// 	mlx_loop(win->mlx);
// }

void plot_points(t_win *win)
{
	t_complex points;

	int		n;

	points.y = 0;
	while (points.y < HEIGHT)
	{
		points.x = 0;
		while (points.x < WIDTH)
		{
			points.x0 = ft_linear_conversion(ft_create_range(0, WIDTH),\
				ft_create_range(-2.00, 2), points.x);
			points.y0 = ft_linear_conversion(ft_create_range(0, HEIGHT),\
				ft_create_range(-2.00, 2), points.y);
			points.a = points.x0;
			points.b = points.y0;
			n = 0;
			while (n < win->max_iter)
			{
				points.real = (points.x0 * points.x0) - (points.y0 * points.y0);
				points.imaginary = 2 * points.x0 * points.y0;
				points.x0 = points.real + points.a;
				points.y0 = points.imaginary + points.b;
				n++;
				if (ft_abs(points.x0 + points.y0) > 16)
					break;
			}
			win->colour = 0;
			if (n == win->max_iter)
				win->colour = 255;
			img_pixel_put(&win->img, points.x, points.y, win->colour);
			points.x++;
		}
		points.y++;
	}
}
