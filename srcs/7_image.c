/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_image.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:34:31 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/09 12:59:46 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int colour)
{
	int pix;
	if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGHT - 1)
		return ;
	pix = (y * img->length) + (x * 4);

	img->addr[pix] = colour;
	img->addr[pix + 1] = (colour >> 24) & 0xFF;
	img->addr[pix + 2] = (colour >> 16) & 0xFF;
	img->addr[pix + 3] = (colour >> 8) & 0xFF;
}