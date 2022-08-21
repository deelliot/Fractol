/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:45:05 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/21 14:21:18 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static t_range	*swop(t_range *range)
{
	double	temp;

	temp = range->min;
	range->min = range->max;
	range->max = temp;
	return (range);
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
	temp = (((x - old.min) * new_range) / old_range) + new.min;
	return (temp);
}

// int main(void)
// {
// 	t_range new_range;
// 	t_range old_range;
// 	double x;
// 	double temp;

// 	x = 120;
// 	new_range = ft_create_range(-2.00, 0.47);
// 	old_range = ft_create_range(0, 1920);
// 	temp = ft_linear_conversion(old_range, new_range, x);
// 	printf("temp = %f\n", temp);

// 	temp = x / (1920 / (new_range.max - new_range.min)) + new_range.min;
// 	printf("temp = %f\n", temp);

// 	return (0);

// }
