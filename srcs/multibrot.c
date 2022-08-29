/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:27:49 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/29 16:42:53 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double atan(double x, double y)
{
	double	result;

	if (x > 0)
		result = arctan(x/y);
	else if (x < 0 && y >= 0)
		result = arctan(y/x) + PI;
	else if (x < 0 && y < 0)
		result = arctan(y/x) - PI;
	else if (x == 0 && y > 0)
		result = PI / 2;
	else if (x == 0 && y < 0)
		result = -PI / 2;
	else
		result = 1/0;
}

static int	multibrot(t_win *win, int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		temp;
	int			n;
	int			power;

	z.real = 0;
	z.imag = 0;
	c.real = ft_linear_conversion(win->width_range, win->x_range, \
		x + win->x_offset);
	c.imag = ft_linear_conversion(win->height_range, win->y_range, \
		y + win->y_offset);
	n = 0;
	power = 3;
	while (n < win->max_iter && (pow(z.real, 2)) + \
		(pow(z.imag, 2)) < 4)
	{
		temp = pow((pow(z.real, 2)+ pow(z.imag, 2)), power / 2) * \
		cos(power * atan(z.real, z.imag)) + c.real;
		z.imag = pow((pow(z.real, 2)+ pow(z.imag, 2)), power / 2) * \
		sin(power * atan(z.real, z.imag)) + c.imag;
		z.real = temp;
		n++;
	}
	return (n);
}