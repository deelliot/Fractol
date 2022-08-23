/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_image.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:34:31 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/23 11:57:43 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_img *img, int x, int y, t_rgb *colour)
{
	int	pix;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		pix = (y * img->length) + (x * img->bpp / 8);
		img->addr[pix] = (int)colour->r;
		img->addr[pix + 1] = (int)colour->g;
		img->addr[pix + 2] = (int)colour->b;
		// printf("post: r: %d, g: %d, b: %d || ", (int)colour->r, (int)colour->g, (int)colour->b);
	}
}
