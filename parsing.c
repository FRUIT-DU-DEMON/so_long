/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 01:32:07 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/13 23:49:12 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_componentes(char **map_code)
{
	int	i;
	int	j;

	i = 0;
	while (map_code[i])
	{
		j = 0;
		while (map_code[i][j])
		{
			if (map_code[i][j] != '0' && map_code[i][j] != '1'
				&& map_code[i][j] != 'C' && map_code[i][j] != 'E'
				&& map_code[i][j] != 'P')
				display_errors2(4);
			j++;
		}
		i++;
	}
}

void	norm_struggles(int c, int flag)
{
	if (flag > 2)
		display_errors2(5);
	if (flag < 2)
		display_errors2(6);
	if (c < 1)
		display_errors3(7);
}

void	check_e_c_p(char **map_code)
{
	int	i;
	int	j;
	int	flag;
	int	c;

	i = 0;
	flag = 0;
	c = 0;
	while (map_code[i])
	{
		j = 0;
		while (map_code[i][j])
		{
			if (map_code[i][j] == 'E' || map_code[i][j] == 'P')
				flag++;
			if (map_code[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	norm_struggles(c, flag);
}
