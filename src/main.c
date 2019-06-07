/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:23:35 by pdiedra           #+#    #+#             */
/*   Updated: 2019/06/06 15:13:59 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_puterror(char *str, t_frctl *frctl)
{
	if (frctl != NULL)
	{
		if (frctl->cmplx != NULL)
			free(frctl->cmplx);
		if (frctl->mlx != NULL)
			free(frctl->mlx);
		if (frctl->mtrx != NULL)
			free(frctl->mtrx);
		free(frctl);
	}
	ft_putendl(str);
	exit(1);
}

void		ft_put_image(t_frctl *frctl)
{
	char *str;

	str = ft_itoa(frctl->mtrx->max_i);
	if (frctl->mtrx->flag == 'j')
		julia_draw(frctl);
	else if (frctl->mtrx->flag == 'm')
		mandelbrot_draw(frctl);
	else if (frctl->mtrx->flag == 'b')
		burning_ship_draw(frctl);
	mlx_put_image_to_window(frctl->mlx->connect, frctl->mlx->window,
			frctl->mlx->img_ptr, 0, 0);
	mlx_string_put(frctl->mlx->connect,
			frctl->mlx->window, 460, 10, 0xFFFFFF, "max_iter: ");
	mlx_string_put(frctl->mlx->connect,
	frctl->mlx->window, 560, 10, 0xFFFFFF, str);
	free(str);
}

static int	ft_init(t_mlx *mlx)
{
	if (!(mlx->connect = mlx_init()))
		return (1);
	if (!(mlx->window = mlx_new_window(mlx->connect, WD, HG, "fract_ol")))
		return (1);
	if (!(mlx->img_ptr = mlx_new_image(mlx->connect, WD, HG)))
		return (1);
	if (!(mlx->img = (int*)mlx_get_data_addr(mlx->img_ptr,
					&mlx->bpp, &mlx->size_line, &mlx->endian)))
		return (1);
	return (0);
}

static void	ft_init_struct(t_frctl *frctl)
{
	if (!(frctl->mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		ft_puterror("error!", frctl);
	if (!(frctl->mtrx = (t_mtrx*)malloc(sizeof(t_mtrx))))
		ft_puterror("error!", frctl);
	if (!(frctl->cmplx = (t_cmplx*)malloc(sizeof(t_cmplx))))
		ft_puterror("error!", frctl);
}

int			main(int ac, char **av)
{
	t_frctl *frctl;

	frctl = NULL;
	if (ac == 2)
	{
		if (!(frctl = (t_frctl*)malloc(sizeof(*frctl))))
			ft_puterror("error!", frctl);
		ft_init_struct(frctl);
		if (ft_init(frctl->mlx))
			ft_puterror("error!", frctl);
		if (ft_strcmp("julia", av[1]) == 0)
			julia(frctl);
		else if (ft_strcmp("mandelbrot", av[1]) == 0)
			mandelbrot(frctl);
		else if (ft_strcmp("burning_ship", av[1]) == 0)
			burning_ship(frctl);
		else
			ft_puterror("./fractol: mandelbrot, julia or burning_ship", frctl);
		ft_hook(frctl);
		ft_put_image(frctl);
		mlx_loop(frctl->mlx->connect);
	}
	else
		ft_puterror("./fractol: mandelbrot, julia or burning_ship", frctl);
	return (0);
}
