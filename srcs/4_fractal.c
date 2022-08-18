/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_fractal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:03:23 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/18 14:57:14 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

// f[{x, y}] = {(a^2 - b^2) + c1}, {2xy + c2}

// A complex number () can be represented on a complex plane.
// The real part of the complex number is represented by a displacement along
// the x-axis and the imaginary part by a displacement along the y-axis.

int	mandelbrot(t_win *win, t_complex points)
{
	int	n;

	points.x0 = ft_linear_conversion(win->width_range, \
		win->x_range, (points.x + win->x_offset));
	points.y0 = ft_linear_conversion(win->height_range, \
			win->y_range, (points.y + win->y_offset));
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

int	julia(t_win *win, double x, double y, t_complex points)
{
	int	n;

	points.x0 = ft_linear_conversion(win->width_range, \
		win->x_range, (points.x + win->x_offset));
	points.y0 = ft_linear_conversion(win->height_range, \
			win->y_range, (points.y + win->y_offset));
	points.a = points.x0;
	points.b = points.y0;
	n = 0;
	while (n < win->max_iter && ft_abs(points.x0 + points.y0) < 4)
	{
		points.real = (points.x0 * points.x0) - (points.y0 * points.y0);
		points.imaginary = 2 * points.x0 * points.y0;
		points.x0 = points.real + x;
		points.y0 = points.imaginary + y;
		n++;
	}
	return (n);
}

void	plot_points(t_win *win)
{
	t_complex	points;
	int			n;

	points.y = 0;
	while (points.y < HEIGHT)
	{
		points.x = 0;
		while (points.x < WIDTH)
		{
			if (win->fractol_option == 0)
				n = julia(win, win->mouse_x, win->mouse_y, points);
			else
				n = mandelbrot(win, points);
			set_colour(win, n);
			img_pixel_put(&win->img, points.x, points.y, &win->col_finish);
			points.x++;
		}
		points.y++;
	}
}
