/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:36:48 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/28 19:36:49 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_one(int key, t_fdf *fdf)
{
	float	x;
	float	y;

	if (key == 6 || key == 7)
	{
		if (key == 6)
			fdf->zoom *= 1.5;
		else
			fdf->zoom /= 1.5;
		y = (fdf->hieght / 2) * fdf->zoom;
		x = (fdf->length / 2) * fdf->zoom;
		if (fdf->proek == 1)
			ft_isometric(&x, &y, 0);
		if (fdf->proek == 2)
		{
			ft_x_povorot(&y, 0, fdf);
			ft_y_povorot(&x, 0, fdf);
		}
		fdf->shift_y = fdf->center[1] - y;
		fdf->shift_x = fdf->center[0] - x;
	}
}

void	ft_move(int key, t_fdf *fdf)
{
	if (key == 123)
	{
		fdf->shift_x -= 5;
		fdf->center[0] -= 5;
	}
	else if (key == 126)
	{
		fdf->shift_y -= 5;
		fdf->center[1] -= 5;
	}
	else if (key == 124)
	{
		fdf->shift_x += 5;
		fdf->center[0] += 5;
	}
	else if (key == 125)
	{
		fdf->shift_y += 5;
		fdf->center[1] += 5;
	}
}

void	ft_hight(int key, t_fdf *fdf)
{
	if (key == 4)
		fdf->koef_z += 0.8;
	else if (key == 38)
		fdf->koef_z -= 0.8;
	else if (key == 12)
		fdf->ugol += 0.02;
	else if (key == 14)
		fdf->ugol -= 0.02;
}

void	ft_povorot_event(int key, t_fdf *fdf)
{
	fdf->shift_x = fdf->center[0];
	fdf->shift_y = fdf->center[1];
	if (key == 37 || key == 40)
	{
		fdf->proek = 2;
		if (key == 37)
			fdf->angle_x += 0.05;
		else
			fdf->angle_x -= 0.05;
	}
	if (key == 46 || key == 45)
	{
		fdf->proek = 2;
		if (key == 46)
			fdf->angle_y += 0.05;
		else
			fdf->angle_y -= 0.05;
	}
}

int		ft_key(int key, t_fdf *fdf)
{
	if (key == 123 || key == 126 || key == 124 || key == 125)
		ft_move(key, fdf);
	else if (key == 6 || key == 7)
		ft_zoom_one(key, fdf);
	else if (key == 38 || key == 4 || key == 12 || key == 14)
		ft_hight(key, fdf);
	else if (key == 46 || key == 45 || key == 37 || key == 40)
		ft_povorot_event(key, fdf);
	else if (key == 34 || key == 35)
		ft_change_proek(key, fdf);
	else if (key == 53)
		exit(1);
	else
		return (0);
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	ft_string_put(fdf);
	ft_draw(fdf);
	return (1);
}
