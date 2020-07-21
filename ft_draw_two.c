/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:52:08 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/28 19:52:10 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_isometric(float *x, float *y, int z)
{
	float prev_x;
	float prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5222);
	*y = (prev_x + prev_y) * sin(0.5222) - z;
}

void	ft_y_povorot(float *x, int z, t_fdf *fdf)
{
	float prev_x;

	prev_x = *x - (fdf->length / 2) * fdf->zoom;
	*x = prev_x * cos(fdf->angle_y) - z * sin(fdf->angle_y);
	z = z * cos(fdf->angle_y) - prev_x * sin(fdf->angle_y);
}

void	ft_x_povorot(float *y, int z, t_fdf *fdf)
{
	float prev_y;

	prev_y = *y - (fdf->hieght / 2) * fdf->zoom;
	*y = prev_y * cos(fdf->angle_x) - z * sin(fdf->angle_x);
	z = prev_y * cos(fdf->angle_x) + z * cos(fdf->angle_x);
}

void	ft_shift(t_coord *coord, t_fdf *fdf)
{
	coord->x0 += fdf->shift_x;
	coord->x1 += fdf->shift_x;
	coord->y0 += fdf->shift_y;
	coord->y1 += fdf->shift_y;
}

void	ft_zoom(t_coord *coord, t_fdf *fdf)
{
	coord->x0 *= fdf->zoom;
	coord->y0 *= fdf->zoom;
	coord->x1 *= fdf->zoom;
	coord->y1 *= fdf->zoom;
}
