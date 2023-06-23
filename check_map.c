/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:17:55 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/23 03:23:50 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_vars *vars)
{
	int	x;
	int	res;

	x = 0;
	if (!ft_match('1', vars->map[0])
		|| !ft_match('1', vars->map[vars->m_h - 1]))
		return (0);
	while (vars->map[x])
	{
		if (x == (vars->m_h - 1))
			res = ((size_t)vars->m_w - 1 == ft_strlen(vars->map[x]));
		else
			res = ((size_t)vars->m_w == (ft_strlen(vars->map[x])));
		if (!res)
			return (0);
		x++;
	}
	return (1);
}

int	ft_check_e(t_vars *vars, int x, int y)
{
	int	e;

	x = 0;
	e = 0;
	while (x < vars->m_h)
	{
		while (y < vars->m_w)
		{
			if (vars->map[x][y] == 'E')
				e++;
			y++;
		}
		y = 0;
		x++;
	}
	if (e == 1)
		return (1);
	return (0);
}

int	check_character(t_vars *vars, int x, int y)
{
	x = -1;
	while (++x < vars->m_h)
	{
		if (x + 1 == vars->m_h)
		{
			if (vars->map[x][0] != '1' || vars->map[x][vars->m_w - 3] != '1')
				return (0);
		}
		else
			if (vars->map[x][0] != '1' || vars->map[x][vars->m_w - 2] != '1')
				return (0);
		y = -1;
		while (vars->map[x][++y])
		{
			if (!is_token(vars->map[x][y]))
				return (0);
			if (vars->map[x][y] == 'P')
			{
				vars->px = x;
				vars->py = y;
			}
		}
	}
	return (1);
}

void	check_map(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	vars->m_w = ft_strlen(vars->map[0]);
	if (!check_walls(vars) || !check_character(vars, x, y)
		|| !ft_check_e(vars, x, y))
		ft_perror("Error\n");
	vars->coins = is_token('C') - 1;
	if (vars->coins == 0)
		ft_perror("Error\n");
}
