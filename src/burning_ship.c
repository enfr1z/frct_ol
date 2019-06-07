/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:06:22 by pdiedra           #+#    #+#             */
/*   Updated: 2019/06/07 13:12:51 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_cmplx	ft_get_real(t_frctl *frctl)
{
	t_cmplx z;

	z = ft_map(frctl->mtrx->x, frctl->mtrx->y, frctl);
	frctl->cmplx->ca = z.re;
	frctl->cmplx->cb = z.im;
	return (z);
}

static t_cmplx	calc_frac(t_frctl *frctl, t_cmplx z)
{
	frctl->cmplx->aa = z.re * z.re - z.im * z.im + frctl->cmplx->ca;
	z.im = fabs(2 * z.re * z.im) + frctl->cmplx->cb;
	z.re = frctl->cmplx->aa;
	return (z);
}

int				burning_ship_draw(t_frctl *frctl)
{
	t_cmplx z;
	int		iter;

	frctl->mtrx->y = -1;
	while (++frctl->mtrx->y < HG)
	{
		frctl->mtrx->x = -1;
		while (++frctl->mtrx->x < WD)
		{
			// z = ft_map(frctl->mtrx->x, frctl->mtrx->y, frctl);
			z = ft_get_real(frctl);
			iter = -1;
			while (++iter < frctl->mtrx->max_i)
			{
				z = calc_frac(frctl, z);
				z.re = fabs(z.re);
				z.im = z.im * -1;
				if (z.re * z.re + z.im * z.im > 16)
					break ;
			}
			frctl->mlx->img[PIX] = (iter == frctl->mtrx->max_i) ? 0 :
				ft_color(frctl->mtrx->color, (iter * 4), iter * 8, iter * 16);
		}
	}
	return (0);
}

int				burning_ship(t_frctl *frctl)
{
	frctl->mtrx->max_i = 25;
	frctl->mtrx->color = 1;
	frctl->mtrx->flag = 'b';
	frctl->mtrx->offset_x = 0;
	frctl->mtrx->offset_y = 0;
	// frctl->cmplx->ca = -1.762;
	// frctl->cmplx->cb = -0.028;
	frctl->mtrx->scale = 1;
	frctl->mtrx->max_x = 2;
	frctl->mtrx->min_x = -2;
	frctl->mtrx->max_y = 2;
	frctl->mtrx->min_y = -2;
	burning_ship_draw(frctl);
	return (0);
}
