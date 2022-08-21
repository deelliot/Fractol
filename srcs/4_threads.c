/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_threads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:45:17 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/21 13:23:21 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	create_threads(t_win *win)
{
	int			i;
	pthread_t	thread_num[MAX_THREADS];
	t_thread	thread[MAX_THREADS];
	int			increment;

	i = -1;
	increment = WIDTH / MAX_THREADS;
	while (++i < MAX_THREADS)
	{
		thread[i].start = increment * i;
		thread[i].end = increment * (i + 1);
		thread[i].win = win;
	}
	i = -1;
	while (++i < MAX_THREADS)
		pthread_create(&(thread_num[i]), NULL, plot_points, &(thread[i]));
	i = -1;
	while (++i < MAX_THREADS)
		pthread_join(thread_num[i], NULL);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
}
