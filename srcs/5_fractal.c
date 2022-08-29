/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_fractal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:03:23 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/29 14:01:24 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* f(z) = (z * z) + c, where c = a + bi.

 f[{x, y}] = {(a^2 - b^2) + c1}, {2xy + c2}

A complex number () can be represented on a complex plane.
The real part of the complex number is represented by a displacement along
the x-axis and the imaginary part by a displacement along the y-axis. */

static int	julia(t_win *win, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			n;

	z.real = ft_linear_conversion(win->width_range, win->x_range, \
		x + win->x_offset);
	z.imag = ft_linear_conversion(win->height_range, win->y_range, \
		y + win->y_offset);
	c.real = win->mouse_x;
	c.imag = win->mouse_y;
	n = 0;
	while (n < win->max_iter && (z.real * z.real) + \
		(z.imag * z.imag) < 4)
	{
		temp = (z.real * z.real) - (z.imag * z.imag);
		z.imag = (2 * z.real * z.imag) + c.imag;
		z.real = temp + c.real;
		n++;
	}
	return (n);
}

static int	mandelbrot(t_win *win, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			n;

	z.real = 0;
	z.imag = 0;
	c.real = ft_linear_conversion(win->width_range, win->x_range, \
		x + win->x_offset);
	c.imag = ft_linear_conversion(win->height_range, win->y_range, \
		y + win->y_offset);
	n = 0;
	while (n < win->max_iter && (z.real * z.real) + \
		(z.imag * z.imag) < 4)
	{
		temp = (z.real * z.real) - (z.imag * z.imag);
		z.imag = (2 * z.real * z.imag) + c.imag;
		z.real = temp + c.real;
		n++;
	}
	return (n);
}

// static int	mandelbrot_power(t_win *win, int x, int y)
// {
// 	t_complex	z;
// 	t_complex	c;
// 	double		temp;
// 	int			n;
// 	double		power;

// 	z.real = 0;
// 	z.imag = 0;
// 	power = 4;
// 	c.real = ft_linear_conversion(win->width_range, win->x_range, \
// 		x + win->x_offset);
// 	c.imag = ft_linear_conversion(win->height_range, win->y_range, \
// 		y + win->y_offset);
// 	n = 0;
// 	while (n < win->max_iter && (pow(z.real, 2)) + \
// 		(pow(z.imag, 2)) < 4)
// 	{
// 		temp = (z.real * z.real) - (z.imag * z.imag);
// 		z.imag = (2 * z.real * z.imag) + c.imag;
// 		z.real = temp + c.real;
// 		n++;
// 	}
// 	return (n);
// }

/* f(n) = z^(-2) + c */

static int	tricorn(t_win *win, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			n;

	z.real = ft_linear_conversion(win->width_range, win->x_range, \
		x + win->x_offset);
	z.imag = ft_linear_conversion(win->height_range, win->y_range, \
		y + win->y_offset);
	c.real = z.real;
	c.imag = z.imag;
	n = 0;
	while (n < win->max_iter && (z.real * z.real) + \
		(z.imag * z.imag) < 4)
	{
		temp = (z.real * z.real) - (z.imag * z.imag);
		z.imag = -3 * z.real * z.imag + c.imag;
		z.real = temp + c.real;
		n++;
	}
	return (n);
}
/* same as mandelbrot except real and imaginery component set to absolute
value before each iteration calculation */

static int	burningship(t_win *win, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			n;

	z.real = 0;
	z.imag = 0;
	c.real = ft_linear_conversion(win->width_range, win->x_range, \
		x + win->x_offset);
	c.imag = ft_linear_conversion(win->height_range, win->y_range, \
		y + win->y_offset);
	n = 0;
	while (n < win->max_iter && (z.real * z.real) + \
		(z.imag * z.imag) < 4)
	{
		z.real = fabs(z.real);
		z.imag = fabs(z.imag);
		temp = (z.real * z.real) - (z.imag * z.imag);
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp + c.real;
		n++;
	}
	return (n);
}

/* loops through each pixel of the window, passes coordinates to fractol fn,
which calculates whether that coordinate value remains bounded or not. Then
uses the return value to set colour and place pixel in image*/

void	*plot_points(void *thread_data)
{
	int			x;
	int			y;
	t_thread	*thread;
	int			n;

	thread = (t_thread *)thread_data;
	y = -1;
	while (++y < HEIGHT)
	{
		x = (thread->start) - 1;
		while (++x < thread->end)
		{
			if (thread->win->fractol_option == 0)
				n = julia(thread->win, x, y);
			else if (thread->win->fractol_option == 1)
				n = mandelbrot(thread->win, x, y);
			else if (thread->win->fractol_option == 2)
				n = tricorn(thread->win, x, y);
			else
				n = burningship(thread->win, x, y);
			img_pixel_put(n, x, y, thread->win);
		}
	}
	return (NULL);
}
