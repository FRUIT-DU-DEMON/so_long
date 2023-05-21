/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 02:16:26 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/14 20:19:49 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h>

# define ON_KEYDOWN 2
# define ON_DESTROY 17

typedef struct t_mlx
{
	void	*ptr;
	void	*wnd;
	char	**map_code;
	int		moves;
}t_mlx;

typedef struct t_vars
{
	int		mc_lines;
	int		len;
	int		flag;
	int		i;
	int		j;
}t_vars;

typedef struct t_pos
{
	int	i;
	int	j;
}t_pos;

typedef struct t_dimention
{
	int		x;
	int		y;
	int		w;
	int		h;
}t_dimention;

typedef struct t_ink
{
	void		*wall;
	void		*wall2;
	void		*e_space;
	void		*player;
	void		*collectibles;
	void		*exit;
	t_dimention	d;
}t_ink;

void	check_map_extension(char **av);
char	**join_map_code(int fd);
int		count_mc_lines(char **map_code);
void	check_map_shape(char **map_code);
void	check_map_componentes(char **map_code);
void	check_e_c_p(char **map_code);
void	check_map_floors(char **map_code);
void	check_map_corners(char **map_code);
void	check_map_walls(char **map_code);
t_pos	get_char_position(char **map_code, char c);
void	set_changes(char **map_code, int i, int j, int *flag);
char	**trace_map(char **map_code);
char	**check_vp_for_e_p(char **map_code);
int		count_cltbls(char **map_code);
void	check_vp_for_cltbls(char **map_code);
void	check_valid_path(char **av, char **map_code);
void	display_errors(int signal);
void	display_errors2(int signal);
void	display_errors3(int signal);
void	set_changes2(t_mlx *mlx, t_ink ink, t_dimention d);
void	stick_images(t_mlx *mlx, t_ink ink);
t_ink	ink_map(t_mlx *mlx);
void	assign_y_moves(t_mlx *mlx, t_ink ink, t_pos pos_p, int nb);
void	assign_x_moves(t_mlx *mlx, t_ink ink, t_pos pos_p, int nb);
void	exit_game(int keycode, t_mlx *mlx, t_pos pos_p);
int		destroy_notify(t_mlx *mlx);
int		move_player(int keycode, t_mlx *mlx);
void	lightweight_memory(char **map_code);

#endif