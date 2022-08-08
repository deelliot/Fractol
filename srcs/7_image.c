/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_image.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:34:31 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/08 16:50:03 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_img *img, int x, int y, int colour)
{
	char *pixel;

	pixel = img->addr + (((y * img->length) + x) * (img->bpp / 8));
	*(int *)pixel = colour;
}