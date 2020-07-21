/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:51:23 by vheidy            #+#    #+#             */
/*   Updated: 2019/12/09 17:53:58 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define BUF_SIZE 10

void		error(int i)
{
	if (i == 1)
		write(1, "Error: Memory allocation\n", 25);
	if (i == 2)
		write(1, "Error: File cannot be read\n", 27);
	if (i == 3)
		write(1, "Error: Not equal number of items in rows\n", 41);
	if (i == 4)
		write(1, "Error: Too many arguments\n", 26);
	exit(1);
}

void		ft_string_two(t_fdf *fdf, int x, int y)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0x21FFF5, "TURN in 2D");
	y += 20;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFF8061, "Q and E");
	y += 40;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0x21FFF5, "X AXIS\
	ROTATION");
	y += 20;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFF8061, "M and N");
	y += 40;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0x21FFF5, "Y AXIS\
	ROTATION ");
	y += 20;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFF8061, "K and L");
	y += 40;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0x21FFF5, "2D and \
	3D projection");
	y += 20;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFF8061, "P and I");
}

void		ft_string_put(t_fdf *fdf)
{
	int		x;
	int		y;

	x = 10;
	y = 10;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0x21FFF5, "MOVE");
	y += 20;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFF8061, "Up, down, \
	right, left arrows");
	y += 40;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0x21FFF5, "ZOOM");
	y += 20;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFF8061, "Z and X");
	y += 40;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0x21FFF5, "Height change");
	y += 20;
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xFF8061, "H and J");
	y += 40;
	ft_string_two(fdf, x, y);
}

void		ft_create_map(t_fdf *map)
{
	float	x;
	float	y;

	map->koef_z = 1;
	map->zoom = 20;
	map->proek = 1;
	map->angle_x = 0;
	map->angle_y = 0;
	map->ugol = 0;
	y = (map->hieght / 2) * map->zoom;
	x = (map->length / 2) * map->zoom;
	ft_isometric(&x, &y, 0);
	map->shift_y = 500 - y;
	map->shift_x = 500 - x;
	map->center[0] = 500;
	map->center[1] = 500;
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "fdf");
}

int			main(int ac, char **av)
{
	int		fd;
	t_fdf	*map;

	if (ac != 2)
		error(4);
	fd = open(av[1], O_RDONLY);
	if (!(map = (t_fdf*)malloc(sizeof(t_fdf))))
		error(1);
	map->length = 0;
	map->hieght = 0;
	ft_read(fd, map);
	ft_create_map(map);
	ft_string_put(map);
	ft_draw(map);
	mlx_hook(map->win_ptr, 2, 1L << 0, ft_key, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
