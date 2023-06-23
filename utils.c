/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:29:27 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/22 08:28:15 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_match(char c, char *s)
{
	while (*s && *s != '\n')
	{
		if (*s != c)
			return (0);
		s++;
	}
	return (1);
}

int	is_token(char c)
{
	static int	e;
	static int	p;
	static int	coin;

	if (c == '0' || c == '1' || c == '\n')
		return (1);
	else if (c == 'P' && p == 0)
		return (++p, 1);
	else if (c == 'E' && e == 0)
		return (++e, 1);
	else if (c == 'C')
		return (++coin);
	return (0);
}

int	valid_extention(char *file)
{
	char	*ret;

	ret = ft_strchr(file, '.');
	if (!ret || ft_strncmp(ret, ".ber", 4))
		return (0);
	return (1);
}

void	ft_perror(char *err)
{
	while (*err)
		write(2, err++, 1);
	exit(1);
}

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	write (1, "GAME OVER\n", 10);
	exit(0);
}
