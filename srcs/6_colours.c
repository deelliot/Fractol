/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_colours.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:45:05 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/08 16:38:46 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_colour(t_win *win, double n)
{
		win->colour = 255 - (int)(n * 255 / win->max_iter);
}
