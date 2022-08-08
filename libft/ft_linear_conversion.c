/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:45:05 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/05 15:09:43 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_range *swop(t_range *range)
{
	double	temp;

	temp = range->min;
	range->min = range->max;
	range->max = temp;
	return(range);
}

double	ft_linear_conversion(t_range old, t_range new, double x)
{
	double	old_range;
	double	new_range;
	double	temp;

	if (old.min > old.max)
		swop(&old);
	if (new.min > new.max)
		swop(&new);
	old_range = old.max - old.min;
	new_range = new.max - new.min;
	temp = ((x - old.min) / old_range) * new_range;
	return (temp);
}