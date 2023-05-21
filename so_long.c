/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:05:49 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/15 18:49:57 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lightweight_memory(char **map_code)
{
	int	i;

	i = 0;
	while (map_code[i])
	{
		free(map_code[i]);
		i++;
	}
	free(map_code);
}

void	protections(int ac, int fd, int fd2)
{
	if (ac > 2)
		display_errors(404);
	if (ac < 2)
		display_errors(-404);
	if (fd < 0 || fd2 < 0)
		display_errors2(505);
}

void	check_window_size(t_mlx mlx)
{
	if ((ft_strlen(mlx.map_code[0]) * 100) > 5120
		|| (count_mc_lines(mlx.map_code) * 100 > 2880))
		display_errors3(707);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	int		fd;
	int		fd2;
	char	**mc_vp;

	mlx.moves = 0;
	fd = open(av[1], O_RDONLY);
	fd2 = open(av[1], O_RDONLY);
	protections(ac, fd, fd2);
	mc_vp = join_map_code(fd2);
	check_valid_path(av, mc_vp);
	lightweight_memory(mc_vp);
	mlx.map_code = join_map_code(fd);
	mlx.ptr = mlx_init();
	check_window_size(mlx);
	mlx.wnd = mlx_new_window(mlx.ptr, ft_strlen(mlx.map_code[0]) * 100,
			count_mc_lines(mlx.map_code) * 100, "so_long");
	ink_map(&mlx);
	mlx_hook(mlx.wnd, ON_KEYDOWN, 0, move_player, &mlx);
	mlx_hook(mlx.wnd, ON_DESTROY, 0, destroy_notify, &mlx);
	mlx_loop(mlx.ptr);
	lightweight_memory(mlx.map_code);
	return (0);
}
