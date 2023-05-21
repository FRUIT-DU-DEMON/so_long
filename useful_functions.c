/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:02:22 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/14 20:28:35 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**join_map_code(int fd)
{
	char	**map_code;
	char	*mc_1d;
	char	buf[2];
	int		i;
	int		j;

	i = read(fd, buf, 1);
	if (i == 0)
		display_errors(1);
	j = 0;
	buf[i] = 0;
	mc_1d = ft_strdup("");
	while (i)
	{
		mc_1d = ft_strjoin(mc_1d, buf);
		i = read(fd, buf, 1);
		buf[i] = 0;
		if (mc_1d[0] == '\n'
			|| (mc_1d[ft_strlen(mc_1d) - 1] == '\n' && buf[0] == '\n'))
			display_errors(2);
	}
	if (mc_1d[ft_strlen(mc_1d) - 1] == '\n')
		display_errors(2);
	map_code = ft_split(mc_1d, '\n');
	return (free(mc_1d), map_code);
}

int	count_mc_lines(char **map_code)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (map_code[i])
	{
		i++;
		lines++;
	}
	return (lines);
}

int	count_cltbls(char **map_code)
{
	int	i;
	int	j;
	int	cltbls;

	i = 0;
	cltbls = 0;
	while (map_code[i])
	{
		j = 0;
		while (map_code[i][j])
		{	
			if (map_code[i][j] == 'C')
				cltbls++;
			j++;
		}
		i++;
	}
	return (cltbls);
}

t_pos	get_char_position(char **map_code, char c)
{
	t_pos	pos;

	pos.i = 0;
	while (map_code[pos.i])
	{
		pos.j = 0;
		while (map_code[pos.i][pos.j])
		{
			if (map_code[pos.i][pos.j] == c)
				return (pos);
			pos.j++;
		}
		pos.i++;
	}
	pos.i = -1;
	pos.j = -1;
	return (pos);
}

int	destroy_notify(t_mlx *mlx)
{
	lightweight_memory(mlx->map_code);
	exit(EXIT_SUCCESS);
}
