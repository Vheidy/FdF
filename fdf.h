/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:49:39 by vheidy            #+#    #+#             */
/*   Updated: 2019/10/18 15:51:06 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

typedef struct		s_coord
{
	float			x0;
	float			x1;
	float			y0;
	float			y1;
}					t_coord;

typedef struct		s_fdf
{
	float			angle_x;
	float			angle_y;
	int				hieght;
	int				length;
	int				**map;
	float			ugol;
	float			zoom;
	float			koef_z;
	int				color;
	int				proek;
	int				center[2];
	int				shift_x;
	int				shift_y;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_fdf;

void				ft_povorot_event(int key, t_fdf *fdf);
void				ft_change_proek(int key, t_fdf *fdf);
void				ft_string_put(t_fdf *fdf);
int					ft_read(int fd, t_fdf *map);
void				ft_x_povorot(float *y, int z, t_fdf *fdf);
void				ft_y_povorot(float *x, int z, t_fdf *fdf);
void				error(int i);
void				ft_zoom(t_coord *coord, t_fdf *fdf);
int					ft_key(int key, t_fdf *fdf);
void				ft_draw(t_fdf *map);
void				ft_shift(t_coord *coord, t_fdf *fdf);
void				error(int i);
int					ft_create_ms(char *line, t_fdf *map);
void				ft_isometric(float *x, float *y, int z);

#endif
