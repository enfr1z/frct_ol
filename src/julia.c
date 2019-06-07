/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:42:43 by pdiedra           #+#    #+#             */
/*   Updated: 2019/06/03 20:57:20 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	t_cmplx	calc_frac(t_frctl *frctl, t_cmplx z)
{
	frctl->cmplx->aa = z.re * z.re - z.im * z.im;
	frctl->cmplx->twoab = 2 * z.re * z.im;
	z.re = frctl->cmplx->aa + frctl->cmplx->ca;
	z.im = frctl->cmplx->twoab + frctl->cmplx->cb;
	return (z);
}

int				julia_draw(t_frctl *frctl)
{
	t_cmplx	z;
	int		iter;

	frctl->mtrx->y = -1;
	while (++frctl->mtrx->y < HG)
	{
		frctl->mtrx->x = -1;
		while (++frctl->mtrx->x < WD)
		{
			z = ft_map(frctl->mtrx->x, frctl->mtrx->y, frctl);
			iter = -1;
			while (++iter < frctl->mtrx->max_i)
			{
				z = calc_frac(frctl, z);
				if (z.re * z.re + z.im * z.im > 16)
					break ;
			}
			frctl->mlx->img[PIX] = (iter == frctl->mtrx->max_i) ? 0 :
			ft_color(frctl->mtrx->color, (iter * 4) / 9, iter * 8, iter * 16);
		}
	}
	return (0);
}

int				julia(t_frctl *frctl)
{
	frctl->mtrx->max_i = 25;
	frctl->mtrx->color = 1;
	frctl->mtrx->offset_x = 0;
	frctl->mtrx->offset_y = 0;
	frctl->mtrx->flag = 'j';
	frctl->cmplx->ca = 0;
	frctl->cmplx->cb = -0.8;
	frctl->mtrx->scale = 1;
	frctl->mtrx->max_x = 2;
	frctl->mtrx->min_x = -2;
	frctl->mtrx->max_y = 2;
	frctl->mtrx->min_y = -2;
	julia_draw(frctl);
	return (0);
}
