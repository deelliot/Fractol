/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_colours.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:45:05 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/23 12:37:32 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_colour(t_win *win, double n)
{
	if (n == win->max_iter)
	{
		win->col_finish.r = 00;
		win->col_finish.g = 00;
		win->col_finish.b = 00;
	}
	else
	{
		win->col_finish.r = win->col_start.r * n;
		win->col_finish.g = win->col_start.g * n;
		win->col_finish.b = win->col_start.b * n;
	}
}

t_rgb	hex_to_rgb(int colour)
{
	t_rgb	col;

	col.r = (colour >> 16) & 0xFF;
	col.g = (colour >> 8) & 0xFF;
	col.b = colour & 0xFF;
	return (col);
}

void	initialise_colour(t_win *win)
{
	if (win->colour == 0)
		win->col_start = hex_to_rgb(0x0F0406);
	if (win->colour == 1)
		win->col_start = hex_to_rgb(0x060F04);
	if (win->colour == 2)
		win->col_start = hex_to_rgb(0x04060F);
	if (win->colour == 3)
		win->col_start = hex_to_rgb(0xBDEB0A);
	if (win->colour == 4)
		win->col_start = hex_to_rgb(0xB2488C);
}
