/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:20:37 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/29 11:34:44 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/* checks arguments match available fractals */

static void	check_argument(t_win *win, char *argv)
{
	if (ft_strcmp(argv, "julia") == 0 || ft_strcmp(argv, "J") == 0)
		win->fractol_option = 0;
	else if (ft_strcmp(argv, "mandelbrot") == 0 || ft_strcmp(argv, "M") == 0)
		win->fractol_option = 1;
	else if (ft_strcmp(argv, "tricorn") == 0 || ft_strcmp(argv, "T") == 0)
		win->fractol_option = 2;
	else if (ft_strcmp(argv, "burningship") == 0 || ft_strcmp(argv, "B") == 0)
		win->fractol_option = 3;
	else if (ft_strcmp(argv, "barnsleyfern") == 0 || \
		ft_strcmp(argv, "BF") == 0)
			win->fractol_option = 4;
	else
	{
		ft_putendl(USAGE);
		exit (1);
	}
}

/* initalises image, sets colour, creates thread and calls loop function */

void	execute_image(t_win *win)
{
	initialise_image(&win->img, win);
	initialise_colour(win);
	if (win->fractol_option == 4)
		barnsley_fern(win);
	else
		initialise_threads(win);
	window_menu(win);
	mlx_loop(win->mlx);
}

int	main(int argc, char **argv)
{
	t_win	win;

	if (argc != 2)
	{
		ft_putendl(USAGE);
		return (0);
	}
	check_argument(&win, argv[1]);
	initialise_window(&win, argv[1]);
	mlx_hook(win.win, KEY_DOWN, 0, handle_input, &win);
	mlx_hook(win.win, 4, 0, mouse_input, &win);
	mlx_hook(win.win, 6, 0, mouse_motion, &win);
	execute_image(&win);
	return (0);
}
