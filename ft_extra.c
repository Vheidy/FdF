/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:06:39 by vheidy            #+#    #+#             */
/*   Updated: 2019/12/09 18:06:42 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_change_proek(int key, t_fdf *fdf)
{
	float	x;
	float	y;

	if (key == 34)
	{
		fdf->proek = 1;
		y = (fdf->hieght / 2) * fdf->zoom;
		x = (fdf->length / 2) * fdf->zoom;
		ft_isometric(&x, &y, 0);
		fdf->shift_y = fdf->center[1] - y;
		fdf->shift_x = fdf->center[0] - x;
		fdf->ugol = 0;
	}
	if (key == 35)
	{
		fdf->shift_x = fdf->center[0];
		fdf->shift_y = fdf->center[1];
		fdf->proek = 2;
		fdf->angle_x = 0;
		fdf->angle_y = 0;
		fdf->ugol = 0;
	}
}
