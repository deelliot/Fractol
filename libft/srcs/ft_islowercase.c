/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islowercase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:28:42 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/18 10:30:56 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_islowercase(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}