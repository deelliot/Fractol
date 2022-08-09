/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_image.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:34:31 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/09 23:54:57 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int colour)
{

	char *pixel;
	int pix;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		pix = (y * img->length) + (x * img->bpp / 8);
		pixel = img->addr + pix;
		*(unsigned int *)pixel = colour;
	}

	// img->addr[pix + 1] = (colour >> 24) & 0xFF;
	// img->addr[pix + 2] = (colour >> 16) & 0xFF;
	// img->addr[pix + 3] = (colour >> 8) & 0xFF;
	// char *pixel;
}
