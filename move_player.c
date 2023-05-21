/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:34:50 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/14 19:04:32 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	assign_y_moves(t_mlx *mlx, t_ink ink, t_pos pos_p, int nb)
{
	mlx_put_image_to_window(mlx->ptr, mlx->wnd,
		ink.player, pos_p.j * ink.d.w, (pos_p.i + nb) * ink.d.h);
	mlx_put_image_to_window(mlx->ptr, mlx->wnd,
		ink.e_space, pos_p.j * ink.d.w, pos_p.i * ink.d.h);
	mlx->map_code[pos_p.i][pos_p.j] = '0';
	mlx->map_code[pos_p.i + nb][pos_p.j] = 'P';
	ft_putnbr_fd(++mlx->moves, 1);
	ft_putstr_fd("\n", 1);
}

void	assign_x_moves(t_mlx *mlx, t_ink ink, t_pos pos_p, int nb)
{
	mlx_put_image_to_window(mlx->ptr, mlx->wnd,
		ink.player, (pos_p.j + nb) * ink.d.w, pos_p.i * ink.d.h);
	mlx_put_image_to_window(mlx->ptr, mlx->wnd,
		ink.e_space, pos_p.j * ink.d.w, pos_p.i * ink.d.h);
	mlx->map_code[pos_p.i][pos_p.j] = '0';
	mlx->map_code[pos_p.i][pos_p.j + nb] = 'P';
	ft_putnbr_fd(++mlx->moves, 1);
	ft_putstr_fd("\n", 1);
}

void	exit_game(int keycode, t_mlx *mlx, t_pos pos_p)
{
	if (keycode == 53)
	{
		lightweight_memory(mlx->map_code);
		exit(EXIT_SUCCESS);
	}
	if (count_cltbls(mlx->map_code) == 0
		&& ((mlx->map_code[pos_p.i - 1][pos_p.j] == 'E' && keycode == 13)
		|| (mlx->map_code[pos_p.i + 1][pos_p.j] == 'E' && keycode == 1)
		|| (mlx->map_code[pos_p.i][pos_p.j + 1] == 'E' && keycode == 2)
		|| (mlx->map_code[pos_p.i][pos_p.j - 1] == 'E' && keycode == 0)))
	{
		ft_putnbr_fd(++mlx->moves, 1);
		ft_putstr_fd("\n", 1);
		lightweight_memory(mlx->map_code);
		exit(EXIT_SUCCESS);
	}
}

int	move_player(int keycode, t_mlx *mlx)
{
	t_ink		ink;
	t_pos		pos_p;

	ink = ink_map(mlx);
	pos_p = get_char_position(mlx->map_code, 'P');
	if (keycode == 13 && (mlx->map_code[pos_p.i - 1][pos_p.j] == 'C'
		|| mlx->map_code[pos_p.i - 1][pos_p.j] == '0'))
		assign_y_moves(mlx, ink, pos_p, -1);
	if (keycode == 1 && (mlx->map_code[pos_p.i + 1][pos_p.j] == 'C'
		|| mlx->map_code[pos_p.i + 1][pos_p.j] == '0'))
		assign_y_moves(mlx, ink, pos_p, 1);
	if (keycode == 2 && (mlx->map_code[pos_p.i][pos_p.j + 1] == 'C'
		|| mlx->map_code[pos_p.i][pos_p.j + 1] == '0'))
		assign_x_moves(mlx, ink, pos_p, 1);
	if (keycode == 0 && (mlx->map_code[pos_p.i][pos_p.j - 1] == 'C'
		|| mlx->map_code[pos_p.i][pos_p.j - 1] == '0'))
		assign_x_moves(mlx, ink, pos_p, -1);
	exit_game(keycode, mlx, pos_p);
	return (0);
}
