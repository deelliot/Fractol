/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_fractal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:03:23 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/09 23:31:17 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

// f[{x, y}] = {(a^2 - b^2) + c1}, {2xy + c2}

// A complex number () can be represented on a complex plane.
// The real part of the complex number is represented by a displacement along
// the x-axis and the imaginary part by a displacement along the y-axis.

int mandelbrot(t_win *win, t_complex points)
{
	int n;

	points.x0 = ft_linear_conversion(ft_create_range(0, WIDTH),\
			ft_create_range(-2.00, 2), points.x);
	points.y0 = ft_linear_conversion(ft_create_range(0, HEIGHT),\
			ft_create_range(-2, 2), points.y);
	points.a = points.x0;
	points.b = points.y0;
	n = 0;
	while (n < win->max_iter && ft_abs(points.x0 + points.y0) < 4)
	{
		points.real = (points.x0 * points.x0) - (points.y0 * points.y0);
		points.imaginary = 2 * points.x0 * points.y0;
		points.x0 = points.real + points.a;
		points.y0 = points.imaginary + points.b;
		n++;
	}
	return (n);
}

void	plot_points(t_win *win)
{
	t_complex points;

	int		n;

	points.y = 0;
	while (points.y < HEIGHT)
	{
		points.x = 0;
		while (points.x < WIDTH)
		{
			n = mandelbrot(win, points);
			// win->colour = 255;
			// if (n == win->max_iter)
			// 	win->colour = 0;
			set_colour(win, n);
			img_pixel_put(&win->img, points.x, points.y, win->colour);
			points.x++;
		}
		points.y++;
	}
}
