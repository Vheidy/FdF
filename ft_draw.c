/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 19:36:38 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/28 19:36:40 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_max(float x_step, float y_step)
{
	if (x_step < 0)
		x_step = -x_step;
	if (y_step < 0)
		y_step = -y_step;
	if (x_step > y_step)
		return (x_step);
	else
		return (y_step);
}

void	ft_povorot(t_coord *coord, t_fdf *fdf)
{
	float x0;
	float y0;
	float x1;
	float y1;

	x0 = coord->x0;
	y0 = coord->y0;
	x1 = coord->x1;
	y1 = coord->y1;
	if (fdf->ugol)
	{
		coord->x0 = fdf->center[0] + (x0 - fdf->center[0]) * cos(fdf->ugol) -
		(y0 - fdf->center[1]) * sin(fdf->ugol);
		coord->y0 = fdf->center[1] + (y0 - fdf->center[1]) * cos(fdf->ugol) +
		(x0 - fdf->center[0]) * sin(fdf->ugol);
		coord->x1 = fdf->center[0] + (x1 - fdf->center[0]) * cos(fdf->ugol) -
		(y1 - fdf->center[1]) * sin(fdf->ugol);
		coord->y1 = fdf->center[1] + (y1 - fdf->center[1]) * cos(fdf->ugol) +
		(x1 - fdf->center[0]) * sin(fdf->ugol);
	}
}

void	ft_change(t_coord *coord, int z0, int z1, t_fdf *fdf)
{
	fdf->color = (z0 || z1) ? 0xFF8061 : 0x21FFF5;
	ft_zoom(coord, fdf);
	if (fdf->proek == 1)
	{
		ft_isometric(&coord->x0, &coord->y0, z0);
		ft_isometric(&coord->x1, &coord->y1, z1);
	}
	if (fdf->proek == 2)
	{
		ft_x_povorot(&coord->y0, z0, fdf);
		ft_x_povorot(&coord->y1, z1, fdf);
		ft_y_povorot(&coord->x0, z0, fdf);
		ft_y_povorot(&coord->x1, z1, fdf);
	}
	ft_shift(coord, fdf);
	ft_povorot(coord, fdf);
}

void	ft_line(t_coord coord, t_fdf *fdf)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z0;
	int		z1;

	z0 = fdf->map[(int)coord.y0][(int)coord.x0] * fdf->koef_z;
	z1 = fdf->map[(int)coord.y1][(int)coord.x1] * fdf->koef_z;
	ft_change(&coord, z0, z1, fdf);
	x_step = coord.x1 - coord.x0;
	y_step = coord.y1 - coord.y0;
	max = ft_max(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(coord.x1 - coord.x0) || (int)(coord.y1 - coord.y0))
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, coord.x0,\
		coord.y0, fdf->color);
		coord.x0 += x_step;
		coord.y0 += y_step;
	}
}

void	ft_draw(t_fdf *map)
{
	t_coord coord;

	coord.y0 = 0;
	while (coord.y0 < map->hieght)
	{
		coord.x0 = 0;
		while (coord.x0 < map->length)
		{
			if (coord.x0 < map->length - 1)
			{
				coord.x1 = coord.x0 + 1;
				coord.y1 = coord.y0;
				ft_line(coord, map);
			}
			if (coord.y0 < map->hieght - 1)
			{
				coord.x1 = coord.x0;
				coord.y1 = coord.y0 + 1;
				ft_line(coord, map);
			}
			coord.x0++;
		}
		coord.y0++;
	}
}
