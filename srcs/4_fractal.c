/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_fractal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:03:23 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/08 16:45:13 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

//mandelbrot x scale (-2, 0.47)
//mandelbrot y scale (-1.12, 1.12)

// f[{x, y}] = {(a^2 - b^2) + c1}, {2xy + c2}

double	mandelbrot(t_win *win, t_complex *points)
{
	double	x;
	double	y;
	double	n;
	int		temp;

	x = 0;
	y = 0;
	n = 0;

	points->x0 = ft_linear_conversion(ft_create_range(0, WIDTH),\
	ft_create_range(-2.00, 0.47), points->x);
	points->y0 = ft_linear_conversion(ft_create_range(0, HEIGHT),\
	ft_create_range(-1.12, 1.12), points->y);

	while (((x * x) + (y * y)) <= 4 && \
		n < win->max_iter)
	{
		temp = ((x * x) - (y * y)) + points->x0;
		y = (2 * x * y) + points->y0;
		x = temp;
		n++;
	}
	return (n);
}

// A complex number () can be represented on a complex plane.
// The real part of the complex number is represented by a displacement along
// the x-axis and the imaginary part by a displacement along the y-axis.

void plot_points(t_win *win)
{
	double	m;

	win->points.y = 0;
	while (win->points.y < HEIGHT)
	{
		win->points.x = 0;
		while (win->points.x < WIDTH)
		{
			m = mandelbrot(win, &win->points);
			set_colour(win, m);
			// printf("x: %f; y: %f, colour = %d\n", win->points.x, win->points.y, win->colour);
			img_pixel_put(&win->img, win->points.x, win->points.y, win->colour);
			win->points.x++;
		}
		win->points.y++;
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	mlx_loop(win->mlx);
}
