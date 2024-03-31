/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micabrer <micabrer@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 00:52:37 by micabrer          #+#    #+#             */
/*   Updated: 2024/02/13 03:10:09 by micabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>

# if defined(unix) || defined(__unix__) || defined(__unix)
#  define LINUX
# else
#  define MAC
# endif

# ifdef LINUX
#  include "minilibx_linux/mlx.h"
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define ESC 65307
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
# else
#  include "minilibx_opengl/mlx.h"
#  define SCROLL_UP 4
#  define SCROLL_DOWN 5
#  define ESC 53
#  define UP 126
#  define DOWN 125
#  define LEFT 123
#  define RIGHT 124
# endif

# define JUL_CODE 1
# define MAND_CODE 2
# define JUL_NAME "Julia"
# define MAND_NAME "Mandelbrot"
# define ITERS 100

# define JULIA_DEFAULT_RE -0.8
# define JULIA_DEFAULT_IM 0.15
# define MANDELBROT_DEFAULT_RE 0
# define MANDELBROT_DEFAULT_IM 0

# define WIDTH 1000
# define HEIGHT 1000
# define MOVE_DELTA 10
# define SCALE_DELTA 1.25

typedef struct s_vars {
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}		t_vars;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		fract_code;
	int		vert;
	int		horiz;
	double	scale;
	double	x;
	double	y;
}			t_data;

void		clean_and_exit(int exit_code, t_data *data);
int			cmp_strings(char *s1, char *s2);
int			is_number(char *s);
double		atod(char *s);

typedef struct s_complex
{
	double	re;
	double	im;
	double	value;
}			t_complex;

t_complex	*complex_sum(t_complex *left, t_complex *right);
t_complex	*complex_multi(t_complex *left, t_complex *right);
t_complex	*complex_power_2(t_complex	*number);
t_complex	*init_complex(double re, double im);

void		draw_fractal(t_data *data);
void		set_up_window(char *name, int code, double def_re, double def_im);

#endif