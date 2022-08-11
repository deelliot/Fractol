/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:20:37 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/11 17:32:14 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	check_argument(t_win *win, char *argv)
{
	if (ft_strcmp(argv, "Julia") == 0)
		win->fractol_option = 0;
	else if (ft_strcmp(argv, "Mandelbrot") == 0)
		win->fractol_option = 1;
	else
		return (-1);
	return (0);
}

void	execute_image(t_win *win)
{
	initialise_image(&win->img, win);
	initialise_colour(win);
	plot_points(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	window_key(win);
 	mlx_loop(win->mlx);
}

int	main(int argc, char** argv)
{
	t_win	win;
	if (argc != 2)
	{
		ft_putendl(USAGE);
		return (0);
	}
	if (check_argument(&win, argv[1]) == -1)
		ft_stderror(USAGE);
	initialise_window(&win, argv[1]);
	mlx_hook(win.win, KEY_DOWN, 0, handle_input, &win);
	execute_image(&win);
	return (0);
}

// int	main(int argc, char** argv)
// {
// 	int	i;
// 	t_win	win[argc - 1];

// 	i = 0;
// 	if (argc == 1)
// 	{
// 		ft_putendl(USAGE);
// 		return (0);
// 	}
// 	while (i < argc - 1)
// 	{
// 		if (check_argument(win, argv[i + 1]) == -1)
// 		{
// 			ft_stderror(USAGE);
// 			i++;
// 			continue;
// 		}
// 		initialise_window(&win[i], argv[i + 1]);
// 		mlx_hook(win[i].win, KEY_DOWN, 0, handle_input, &win[i]);
// 		execute_image(&win[i]);
// 		i++;
// 	}
// 	return (0);
// }