/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_colours.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:45:05 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/08 17:03:09 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_colour(t_win *win, double n)
{
		double	r;
		double	g;
		double	b;

		r = 255 - (int)(n * 255 / win->max_iter);
		g = 255 - (int)(n * 255 / win->max_iter);
		b = 255 - (int)(n * 255 / win->max_iter);
		win->colour = rgb_to_hex(r, g, b);
}
