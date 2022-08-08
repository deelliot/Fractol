/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalise_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:37:05 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/05 13:38:45 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* normalises data to between 0 - 1 */

double	normalise_data(double min, double max, double num)
{
	double	temp;

	temp = (num - min) / (max - min);
	return (temp);
}
