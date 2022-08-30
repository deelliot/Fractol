/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:27:49 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/30 12:39:24 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// int	multibrot(t_win *win, int x, int y)
// {
// 	t_complex	z;
// 	t_complex	c;
// 	double		temp;
// 	int			n;

// 	z.real = 0;
// 	z.imag = 0;
// 	c.real = ft_linear_conversion(win->width_range, win->x_range, \
// 		x + win->x_offset);
// 	c.imag = ft_linear_conversion(win->height_range, win->y_range, \
// 		y + win->y_offset);
// 	n = 0;
// 	while (n < win->max_iter && (z.real * z.real) + \
// 		(z.imag * z.imag) < 4)
// 	{
// 		temp = pow(z.real, 3) - 3 * z.real * pow(z.imag, 2) + c.real;
// 		z.imag = 3 * pow(z.real, 2) * z.imag - pow(z.imag, 3) + c.imag;
// 		z.real = temp;
// 		n++;
// 	}
// 	return (n);
// }

int	multibrot(t_win *win, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	double		x_temp;
	double		num;
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
		temp = z.real * z.real + z.imag * z.imag;
		num = win->power * atan2(z.imag, z.real);
		x_temp = pow(temp, (win->power / 2)) * cos(num) + c.real;
		z.imag = pow(temp, (win->power / 2)) * sin(num) + c.imag;
		z.real = x_temp;
		n++;
	}
	return (n);
}

void	handle_power(t_win *win)
{
	win->power += 1;
	if (win->power == 10)
		win->power = -5;
	if (win->power == -1)
		win->power = 2;
	mlx_clear_window(win->mlx, win->win);
	execute_image(win);
}