/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:01:04 by hlabouit          #+#    #+#             */
/*   Updated: 2023/05/17 20:55:03 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_errors(int signal)
{
	if (signal == 404)
	{
		ft_putstr_fd("Error\nargs overdose\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == -404)
	{
		ft_putstr_fd("Error\nlack of args\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 0)
	{
		ft_putstr_fd("Error\nunvalide map file extension\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 1)
	{
		ft_putstr_fd("Error\nmap.ber file is empty\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 2)
	{
		ft_putstr_fd("Error\nmap countains empty lines\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	display_errors2(int signal)
{
	if (signal == 505)
	{
		ft_putstr_fd("Error\nfile doesn't exist\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 3)
	{
		ft_putstr_fd("Error\nmap isn't rectangular\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 4)
	{
		ft_putstr_fd("Error\nunvalide map characters\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 5)
	{
		ft_putstr_fd("Error\nduplicates map characters\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 6)
	{
		ft_putstr_fd("Error\nthere must be a player or an exit\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	display_errors3(int signal)
{
	if (signal == 7)
	{
		ft_putstr_fd("Error\nmap doesn't countain collectibles\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 8)
	{
		ft_putstr_fd("Error\nmap isn't surrounded by walls\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 9)
	{
		ft_putstr_fd("Error\nplayer has unvalide path\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 10)
	{
		ft_putstr_fd("Error\ncollectibles have unvalide path\n", 1);
		exit(EXIT_FAILURE);
	}
	if (signal == 707)
	{
		ft_putstr_fd("Error\nwindow can't be displayed through borders \n", 1);
		exit(EXIT_FAILURE);
	}
}
