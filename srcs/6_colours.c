/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_colours.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:45:05 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/10 09:54:38 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_colour(t_win *win, double n)
{
		double	r;
		double	g;
		double	b;

		if (n == win->max_iter)
			win->colour = 0x000000;
		else
		{
			r = 6 * n;
			b = 12 * n;
			g = 15 * n;
			win->colour = rgb_to_hex(r, g, b);
		}


		// r = ft_linear_conversion(ft_create_range(0, win->max_iter), \
		// 	ft_create_range (0, 255), n);
		// g = ft_linear_conversion(ft_create_range(0, win->max_iter), \
		// 	ft_create_range (0, 255), n);
		// b = ft_linear_conversion(ft_create_range(0, win->max_iter), \
		// 	ft_create_range (0, 255), n);
		// win->colour = rgb_to_hex(r, g, b);
}
