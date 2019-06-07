/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiedra <pdiedra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:19:15 by pdiedra           #+#    #+#             */
/*   Updated: 2019/06/03 20:58:23 by pdiedra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	move(int keycode, t_frctl *frctl)
{
	if (keycode == LEFT || keycode == A)
		frctl->mtrx->offset_x += 0.5 / frctl->mtrx->scale;
	if (keycode == RIGHT || keycode == D)
		frctl->mtrx->offset_x -= 0.5 / frctl->mtrx->scale;
	if (keycode == UP || keycode == W)
		frctl->mtrx->offset_y -= 0.5 / frctl->mtrx->scale;
	if (keycode == DOWN || keycode == S)
		frctl->mtrx->offset_y += 0.5 / frctl->mtrx->scale;
	return (0);
}

static	int	zoom(int keycode, t_frctl *frctl)
{
	if (keycode == N_PLUS)
		frctl->mtrx->scale *= 1.1;
	if (keycode == N_MINUS)
		frctl->mtrx->scale /= 1.1;
	return (0);
}

static int	ft_other(int keycode, t_frctl *frctl)
{
	if (keycode == X)
		frctl->mlx->flag = frctl->mlx->flag == 0 ? 1 : 0;
	if (keycode == SPACE)
	{
		frctl->mtrx->max_i = 25;
		frctl->mtrx->offset_x = 0;
		frctl->mtrx->offset_y = 0;
		frctl->mtrx->scale = 1;
		frctl->mlx->flag = 0;
		if (frctl->mtrx->flag == 'j')
		{
			frctl->cmplx->ca = 0;
			frctl->cmplx->cb = -0.8;
		}
		else if (frctl->mtrx->flag == 'b')
		{
			frctl->cmplx->ca = -1.762;
			frctl->cmplx->cb = -0.028;
		}
	}
	return (0);
}

int			ft_exit(t_frctl *frctl)
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
	exit(0);
	return (0);
}

int			keyboard(int keycode, t_frctl *frctl)
{
	if (keycode == ESC)
		ft_exit(frctl);
	if (keycode == A || keycode == W || keycode == D || keycode == S ||
	keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
		move(keycode, frctl);
	if (keycode == N_PLUS || keycode == N_MINUS)
		zoom(keycode, frctl);
	if (keycode == X || keycode == SPACE)
		ft_other(keycode, frctl);
	if (keycode == M)
	{
		if (frctl->mtrx->color < 3)
			frctl->mtrx->color++;
		else
			frctl->mtrx->color = 1;
	}
	if (keycode == C)
		if (frctl->mtrx->max_i <= 400)
			frctl->mtrx->max_i++;
	if (keycode == V)
		if (frctl->mtrx->max_i >= 25)
			frctl->mtrx->max_i--;
	mlx_clear_window(frctl->mlx->connect, frctl->mlx->window);
	ft_put_image(frctl);
	return (0);
}
