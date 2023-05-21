/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:01:16 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/14 17:44:49 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_extension(char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (av[1] && av[1][i] != '.')
		i++;
	i++;
	j = i + 1;
	k = j + 1;
	while (av[1] && av[1][k + 1] == '\0')
	{
		if (av[1][i] != 'b' || av[1][j] != 'e' || av[1][k] != 'r')
			display_errors(0);
		else
			break ;
	}
	if (av[1][k + 1] != '\0')
		display_errors(0);
}

void	check_map_shape(char **map_code)
{
	int	i;
	int	lines;
	int	fixed_len;

	i = 1;
	lines = count_mc_lines(map_code) - 1;
	fixed_len = ft_strlen(map_code[0]);
	while (lines)
	{
		if (fixed_len != ft_strlen(map_code[i]))
			display_errors2(3);
		i++;
		lines--;
	}
}

void	check_map_floors(char **map_code)
{
	int	i;
	int	j;

	i = 0;
	while (map_code[i])
	{
		j = 0;
		while (map_code[i][j])
		{
			if ((i == 0 || i == count_mc_lines(map_code) - 1)
				&& map_code[i][j] != '1')
				display_errors3(8);
			j++;
		}
		i++;
	}
}

void	check_map_corners(char **map_code)
{
	int	i;

	i = 1;
	while (map_code[i] && i != count_mc_lines(map_code) - 1)
	{
		if (map_code[i][0] != '1'
			|| map_code[i][ft_strlen(map_code[i]) - 1] != '1')
			display_errors3(8);
		i++;
	}
}

void	check_map_walls(char **map_code)
{
	check_map_floors(map_code);
	check_map_corners(map_code);
}
