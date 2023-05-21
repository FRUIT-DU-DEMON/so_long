/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlabouit <hlabouit@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:23:13 by hlabouit          #+#    #+#             */
/*   Updated: 2023/04/08 18:34:54 by hlabouit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s01;
	unsigned char	*s02;

	i = 0;
	s01 = (unsigned char *)s1;
	s02 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s01[i] && s02[i] && i < n - 1)
	{
		if (s01[i] != s02[i])
			break ;
		i++;
	}
	return (s01[i] - s02[i]);
}
