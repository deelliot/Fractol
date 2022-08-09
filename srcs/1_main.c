/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:20:37 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/09 14:02:22 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_argument(t_win *win, char *argv)
{
	if (ft_strcmp(argv, "Julia") == 0)
		win->fractol_option = 0;
	else if (ft_strcmp(argv, "Mandelbrot") == 0)
		win->fractol_option = 1;
	else
		handle_errors(win, USAGE);
}

int	main(int argc, char** argv)
{
	int	i;
	t_win	win[argc];

	i = 0;
	if (argc == 1)
	{
		handle_errors(win, USAGE);
		return (0);
	}
	while (i < argc - 1)
	{
		check_argument(win, argv[i + 1]);
		initialise_window(&win[i], argv[i + 1]);
		mlx_hook(win[i].win, KEY_DOWN, 0, handle_input, &win[i]);
		plot_points(win);
		mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
		window_key(&win[i]);
 		mlx_loop(win->mlx);
		i++;
	}
	return (0);
}