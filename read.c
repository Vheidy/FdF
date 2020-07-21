/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:58:41 by vheidy            #+#    #+#             */
/*   Updated: 2019/12/09 17:58:47 by vheidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define BUF_SIZE 10

int		ft_count(char *line_read, t_fdf *fdf)
{
	int i;
	int count_str;
	int count_num;

	i = -1;
	count_str = 0;
	count_num = 0;
	while (line_read[++i] != '\0')
	{
		if (line_read[i] == '\n')
		{
			count_str++;
			if (count_num != fdf->length && fdf->length)
				error(3);
			if ((fdf->length = count_num) == 0)
				error(3);
			count_num = 0;
		}
		if (ft_isdigit(line_read[i]) && (!ft_isdigit(line_read[i + 1]) \
		|| !line_read[i + 1]))
			count_num++;
	}
	if (line_read[i] == '\0' && line_read[i - 1] != '\n')
		count_str++;
	return (count_str);
}

int		**ft_full(char **str, int **map)
{
	int i;
	int k;
	int p;
	int j;

	i = -1;
	k = 0;
	p = 0;
	while (str[++i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (j == 0 || str[i][j - 1] == '\n')
				map[k][p++] = ft_atoi(&str[i][j]);
			if (str[i][j] == '\n')
			{
				k++;
				p = 0;
			}
			j++;
		}
	}
	return (map);
}

void	ft_free(char ***tmp)
{
	int i;

	i = 0;
	while ((*tmp)[i] != NULL)
		ft_strdel(&(*tmp)[i++]);
	free(*tmp);
	*tmp = NULL;
}

int		ft_create_ms(char *line_read, t_fdf *fdf)
{
	char	**str;
	int		**map;
	int		a;

	a = -1;
	str = ft_strsplit(line_read, ' ');
	fdf->hieght = ft_count(line_read, fdf);
	if (!(map = (int**)malloc((fdf->hieght) * sizeof(int*))))
		error(1);
	while (++a < fdf->hieght)
		if (!(map[a] = (int*)malloc(sizeof(int) * fdf->length)))
			error(1);
	fdf->map = ft_full(str, map);
	ft_free(&str);
	return (1);
}

int		ft_read(int fd, t_fdf *map)
{
	char	buf[BUF_SIZE + 1];
	char	*line_read;
	int		red;

	line_read = NULL;
	while ((red = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[red] = '\0';
		line_read = ft_strjoin_free(line_read, buf, 1, 0);
	}
	if (red == -1)
		error(2);
	ft_create_ms(line_read, map);
	ft_strdel(&line_read);
	return (1);
}
