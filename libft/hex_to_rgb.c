/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:35:10 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/29 15:41:53 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_rgb	hex_to_rgb(int colour)
{
	t_rgb	col;

	col.r = (colour >> 16) & 0xFF;
	col.g = (colour >> 8) & 0xFF;
	col.b = colour & 0xFF;
	return (col);
}