/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:13:20 by pdiedra           #+#    #+#             */
/*   Updated: 2019/06/03 20:52:50 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "keys.h"
# include <math.h>
# include <pthread.h>

# define WD 600
# define HG 600

# define PIX (frctl->mtrx->y * WD + frctl->mtrx->x)

# define MAX_ITER 100

# define MAX_X 2
# define MIN_X -2
# define MAX_Y 2
# define MIN_Y -2

# define COMPLEX_ABS(re, im) re * re + im * im

typedef struct	s_cmplx
{
	float		re;
	float		im;
	float		aa;
	float		twoab;
	float		ca;
	float		cb;
}				t_cmplx;

typedef struct	s_mtrx
{
	float		max_x;
	float		min_x;
	float		max_y;
	float		min_y;
	float		scale;
	float		offset_x;
	float		offset_y;
	int			max_i;
	int			x;
	int			y;
	int			iter;
	int			color;
	char		flag;
	t_cmplx		z;
	t_cmplx		c;
}				t_mtrx;

typedef struct	s_mlx
{
	int			*img;
	int			*img_info;
	int			bpp;
	int			size_line;
	int			endian;
	int			flag;
	void		*connect;
	void		*window;
	void		*img_ptr;
	void		*img_ptr_info;
}				t_mlx;

typedef struct	s_frctl
{
	t_mlx		*mlx;
	t_mtrx		*mtrx;
	t_cmplx		*cmplx;
}				t_frctl;

int				burning_ship(t_frctl *frctl);
int				burning_ship_draw(t_frctl *frctl);
int				julia(t_frctl *frctl);
int				julia_draw(t_frctl *frctl);
int				mandelbrot(t_frctl *frctl);
int				mandelbrot_draw(t_frctl *frctl);
int				ft_color(int flag, int r, int g, int b);
int				keyboard(int keycode, t_frctl *frctl);
int				mouse(int button, int x, int y, t_frctl *frctl);
int				mouse_move(int x, int y, t_frctl *frctl);
int				ft_exit(t_frctl *frctl);
void			ft_puterror(char *str, t_frctl *frctl);
void			ft_put_image(t_frctl *frctl);
void			ft_hook(t_frctl *frctl);
t_cmplx			ft_map(int x, int y, t_frctl *frctl);

#endif
