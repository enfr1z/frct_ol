/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:51:37 by pdiedra           #+#    #+#             */
/*   Updated: 2019/06/07 12:54:51 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, t_frctl *frctl)
{
	t_cmplx z;

	if (frctl->mlx->flag == 1)
	{
		z = ft_map(x, y, frctl);
		frctl->cmplx->ca = z.re;
		frctl->cmplx->cb = z.im;
		mlx_clear_window(frctl->mlx->connect, frctl->mlx->window);
		ft_put_image(frctl);
	}
	return (0);
}

int		mouse(int button, int x, int y, t_frctl *frctl)
{
	if (button == SCRL_DWN)
	{
		frctl->mtrx->scale *= 1.1;
		frctl->mtrx->offset_x += (x - WD / 2) / (frctl->mtrx->scale * WD);
		frctl->mtrx->offset_y -= (y - HG / 2) / (frctl->mtrx->scale * HG);
	}
	if (button == SCRL_UP)
		frctl->mtrx->scale /= 1.1;
	mlx_clear_window(frctl->mlx->connect, frctl->mlx->window);
	ft_put_image(frctl);
	return (0);
}
