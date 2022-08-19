/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_fractal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:03:23 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/19 17:26:04 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

// f[{x, y}] = {(a^2 - b^2) + c1}, {2xy + c2}

// A complex number () can be represented on a complex plane.
// The real part of the complex number is represented by a displacement along
// the x-axis and the imaginary part by a displacement along the y-axis.

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
	while (n < win->max_iter && ft_abs((points.x0 * points.x0) + \
		(points.y0 * points.y0)) < 4)
	{
		points.real = (points.x0 * points.x0) - (points.y0 * points.y0);
		points.imaginary = 2 * points.x0 * points.y0;
		points.x0 = points.real + x;
		points.y0 = points.imaginary + y;
		n++;
	}
	return (n);
}

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
	while (n < win->max_iter && ft_abs((points.x0 * points.x0) + \
		(points.y0 * points.y0)) < 4)
	{
		points.real = (points.x0 * points.x0) - (points.y0 * points.y0);
		points.imaginary = 2 * points.x0 * points.y0;
		points.x0 = points.real + points.a;
		points.y0 = points.imaginary + points.b;
		n++;
	}
	return (n);
}

int	tricorn(t_win *win, t_complex points)
{
	int	n;

	points.x0 = ft_linear_conversion(win->width_range, \
		win->x_range, (points.x + win->x_offset));
	points.y0 = ft_linear_conversion(win->height_range, \
			win->y_range, (points.y + win->y_offset));
	points.a = points.x0;
	points.b = points.y0;
	n = 0;
	while (n < win->max_iter && ft_abs((points.x0 * points.x0) + \
		(points.y0 * points.y0)) < 4)
	{
		points.real = (points.x0 * points.x0) - (points.y0 * points.y0);
		points.imaginary = 2 * points.x0 * points.y0;
		points.x0 = points.real + points.a;
		points.y0 = -points.imaginary + points.b;
		n++;
	}
	return (n);
}

int	burning_ship(t_win *win, t_complex points)
{
	int	n;

	points.x0 = ft_linear_conversion(win->width_range, \
		win->x_range, (points.x + win->x_offset));
	points.y0 = ft_linear_conversion(win->height_range, \
			win->y_range, (points.y + win->y_offset));
	points.a = points.x0;
	points.b = points.y0;
	n = 0;
	while (n < win->max_iter && points.x0 * points.x0 + \
		points.y0 * points.y0 < 4)
	{
		points.real = (points.x0 * points.x0) - (points.y0 * points.y0);
		points.imaginary = ft_abs(2 * points.x0 * points.y0);
		points.x0 = (points.real + points.a);
		points.y0 = points.imaginary + points.b;
		n++;
	}
	return (n);
}

void	*plot_points(void *thread_data)
{
	t_complex	points;
	t_thread	*thread;
	int			n;

	thread = (t_thread *)thread_data;
	points.y = 0;
	while (points.y < HEIGHT)
	{
		points.x = thread->start;
		while (points.x < thread->end)
		{
			if (thread->win->fractol_option == 0)
				n = julia(thread->win, thread->win->mouse_x, thread->win->mouse_y, points);
			else if (thread->win->fractol_option == 1)
				n = mandelbrot(thread->win, points);
			else if (thread->win->fractol_option == 2)
				n = tricorn(thread->win, points);
			else
				n = burning_ship(thread->win, points);
			set_colour(thread->win, n);
			img_pixel_put(&thread->win->img, points.x, points.y, &thread->win->col_finish);
			points.x++;
		}
		points.y++;
	}
	pthread_exit(NULL);
}

