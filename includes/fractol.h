/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:15:00 by deelliot          #+#    #+#             */
/*   Updated: 2022/08/08 14:49:05 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
// # include "mlx.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <pthread.h>

/* pthreads library is needed for multithreading */

/* screen height and width */
# define WIDTH 1080
# define HEIGHT 720

# define USAGE "Usage: ./fractol (Julia / Mandelbrot)"

/* key values */
# define KEY_DOWN 2
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ESC 53
# define ZOOM_IN 34
# define ZOOM_OUT 31
# define COLOUR 49
# define RESET 36

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}				t_img;

typedef struct	s_complex
{
	double	x;
	double	x0;
	double	y;
	double	y0;
}				t_complex;

typedef struct s_win
{
	t_img	img;
	void	*mlx;
	void	*win;
	int		max_iter;
	int		fractol_option;
	int		colour;
	t_complex	points;
}				t_win;

void	handle_errors(t_win	*win, char *str);
void	free_win(t_win *win);
void	initialise_window(t_win *win, char *argv);
int		handle_input(int key, t_win *win);
void	plot_points(t_win *win);
void	set_colour(t_win *win, double n);
void	img_pixel_put(t_img *img, int x, int y, int colour);
void	window_key(t_win *win);

#endif