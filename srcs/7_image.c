/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_image.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:34:31 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/11 16:58:13 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_img *img, int x, int y, t_rgb *colour)
{
	// char *pixel;
	int pix;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		pix = (y * img->length) + (x * img->bpp / 8);
	// 	pixel = img->addr + pix;
	// 	*(unsigned int *)pixel = colour;
	// }

	img->addr[pix] = colour->r;
	img->addr[pix + 1] = colour->g;
	img->addr[pix + 2] = colour->b;
	}
}
