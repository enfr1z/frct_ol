/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:37:25 by pdiedra           #+#    #+#             */
/*   Updated: 2019/06/06 13:25:46 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_cmplx	ft_map(int x, int y, t_frctl *frctl)
{
	t_cmplx z;

	z.re = ((4 * (float)x / WD - 2));
	z.im = ((-4 * (float)y / HG + 2));
	z.re /= frctl->mtrx->scale;
	z.im /= frctl->mtrx->scale;
	z.re += frctl->mtrx->offset_x;
	z.im += frctl->mtrx->offset_y;
	return (z);
}

void	ft_hook(t_frctl *frctl)
{
	mlx_hook(frctl->mlx->window, 17, 0, ft_exit, frctl);
	mlx_hook(frctl->mlx->window, 2, 0, keyboard, frctl);
	mlx_hook(frctl->mlx->window, 4, 0, mouse, frctl);
	mlx_hook(frctl->mlx->window, 6, 0, mouse_move, frctl);
}

int		ft_color(int flag, int r, int g, int b)
{
	if (flag == 1)
		return (r << 16 | g << 8 | b);
	else if (flag == 2)
		return (r << 8 | g << 16 | b << 2);
	else if (flag == 3)
		return (r >> 8 | g << 4 | b);
	return (0);
}
