/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ink_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:55:29 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/17 20:17:42 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_changes2(t_mlx *mlx, t_ink ink, t_dimention d)
{
	if (((d.y == 0 || d.y == count_mc_lines(mlx->map_code) - 1)
			|| (d.x == 0 || d.x == ft_strlen(mlx->map_code[0]) - 1))
		&& mlx->map_code[d.y][d.x] == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->wnd,
			ink.wall2, d.x * ink.d.w, d.y * ink.d.h);
	else if (mlx->map_code[d.y][d.x] == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->wnd,
			ink.wall, d.x * ink.d.w, d.y * ink.d.h);
	if (mlx->map_code[d.y][d.x] == '0')
		mlx_put_image_to_window(mlx->ptr, mlx->wnd,
			ink.e_space, d.x * ink.d.w, d.y * ink.d.h);
	if (mlx->map_code[d.y][d.x] == 'P')
		mlx_put_image_to_window(mlx->ptr, mlx->wnd,
			ink.player, d.x * ink.d.w, d.y * ink.d.h);
	if (mlx->map_code[d.y][d.x] == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->wnd,
			ink.collectibles, d.x * ink.d.w, d.y * ink.d.h);
	if (mlx->map_code[d.y][d.x] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->wnd,
			ink.exit, d.x * ink.d.w, d.y * ink.d.h);
}

void	stick_images(t_mlx *mlx, t_ink ink)
{
	t_dimention	d;

	d.y = 0;
	while (d.y < count_mc_lines(mlx->map_code))
	{
		d.x = 0;
		while (d.x < ft_strlen(mlx->map_code[0]))
		{
			set_changes2(mlx, ink, d);
			d.x++;
		}
		d.y++;
	}
}

t_ink	ink_map(t_mlx *mlx)
{
	t_ink		ink;
	t_dimention	d;

	ink.wall = mlx_xpm_file_to_image(mlx->ptr, "clouds.xpm", &d.w, &d.h);
	ink.wall2 = mlx_xpm_file_to_image(mlx->ptr, "clouds_pynk.xpm", &d.w, &d.h);
	ink.e_space = mlx_xpm_file_to_image(mlx->ptr, "jaya.xpm", &d.w, &d.h);
	ink.player = mlx_xpm_file_to_image(mlx->ptr, "luffy.xpm", &d.w, &d.h);
	ink.collectibles = mlx_xpm_file_to_image(mlx->ptr, "fdd.xpm", &d.w, &d.h);
	ink.exit = mlx_xpm_file_to_image(mlx->ptr, "going_merry.xpm", &d.w, &d.h);
	ink.d = d;
	if (!ink.wall || !ink.wall2 || !ink.e_space || !ink.player
		|| !ink.collectibles || !ink.exit)
	{
		lightweight_memory(mlx->map_code);
		ft_putstr_fd("Error\nempty xpm file\n", 1);
		exit(EXIT_FAILURE);
	}
	stick_images(mlx, ink);
	return (ink);
}
