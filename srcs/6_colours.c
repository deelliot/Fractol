/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_colours.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:45:05 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/09 23:33:03 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_colour(t_win *win, double x)
{
		double	r;
		double	g;
		double	b;

		double	n;

		n = 255 - x;

		r = ft_linear_conversion(ft_create_range(0, win->max_iter), \
			ft_create_range (0, 255), n);
		g = ft_linear_conversion(ft_create_range(0, win->max_iter), \
			ft_create_range (0, 255), n);
		b = ft_linear_conversion(ft_create_range(0, win->max_iter), \
			ft_create_range (0, 255), n);
		win->colour = rgb_to_hex(r, g, b);
}
