/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 03:02:56 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/14 13:29:17 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_changes(char **map_code, int i, int j, int *flag)
{
	if (map_code[i - 1][j] == 'C' || map_code[i - 1][j] == '0')
	{
		map_code[i - 1][j] = 'P';
		(*flag)++;
	}
	if (map_code[i + 1][j] == 'C' || map_code[i + 1][j] == '0')
	{
		map_code[i + 1][j] = 'P';
		(*flag)++;
	}
	if (map_code[i][j + 1] == 'C' || map_code[i][j + 1] == '0')
	{
		map_code[i][j + 1] = 'P';
		(*flag)++;
	}
	if (map_code[i][j - 1] == 'C' || map_code[i][j - 1] == '0')
	{
		map_code[i][j - 1] = 'P';
		(*flag)++;
	}
}

char	**trace_map(char **map_code)
{
	t_vars	vars;

	vars.mc_lines = count_mc_lines(map_code);
	vars.len = ft_strlen(map_code[0]);
	vars.flag = 0;
	vars.i = 0;
	while (vars.i < vars.mc_lines)
	{
		vars.j = 0;
		while (vars.j < vars.len)
		{
			if (map_code[vars.i][vars.j] == 'P')
				set_changes(map_code, vars.i, vars.j, &vars.flag);
			if (vars.flag != 0)
			{
				vars.i = 0;
				vars.j = 0;
				vars.flag = 0;
				break ;
			}
			vars.j++;
		}
		vars.i++;
	}
	return (map_code);
}

char	**check_vp_for_e_p(char **map_code)
{
	char	**new_mc;
	t_pos	pos;
	int		i;
	int		j;

	pos = get_char_position(map_code, 'E');
	i = 0;
	new_mc = trace_map(map_code);
	while (new_mc[i])
	{
		j = 0;
		while (new_mc[i][j])
		{
			if (new_mc[i][j] == '0')
				new_mc[i][j] = '1';
			j++;
		}
		i++;
	}
	if (new_mc[pos.i - 1][pos.j] == '1' && new_mc[pos.i + 1][pos.j] == '1'
		&& new_mc[pos.i][pos.j + 1] == '1' && new_mc[pos.i][pos.j - 1] == '1')
		display_errors3(9);
	return (new_mc);
}

void	check_vp_for_cltbls(char **map_code)
{
	int		cltbls;
	char	**new_mc;

	new_mc = check_vp_for_e_p(map_code);
	cltbls = count_cltbls(new_mc);
	if (cltbls > 0)
		display_errors3(10);
}

void	check_valid_path(char **av, char **map_code)
{
	check_map_extension(av);
	check_map_shape(map_code);
	check_map_componentes(map_code);
	check_e_c_p(map_code);
	check_map_walls(map_code);
	check_vp_for_e_p(map_code);
	check_vp_for_cltbls(map_code);
}
