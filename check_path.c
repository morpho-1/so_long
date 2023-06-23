/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:17:04 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/23 03:21:37 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pos_filled(char **map, int x, int y)
{
	int	res;

	res = 0;
	if (map[x - 1][y] == '0' || map[x - 1][y] == 'C')
	{
		map[x - 1][y] = 'P';
		res++;
	}
	if (map[x + 1][y] == '0' || map[x + 1][y] == 'C')
	{
		map[x + 1][y] = 'P';
		res++;
	}
	if (map[x][y - 1] == '0' || map[x][y - 1] == 'C')
	{
		map[x][y - 1] = 'P';
		res++;
	}
	if (map[x][y + 1] == '0' || map[x][y + 1] == 'C')
	{
		map[x][y + 1] = 'P';
		res++;
	}
	return (res);
}

void	check_exit(t_vars *vars, int x, int y)
{
	int	tr;

	x = -1;
	tr = 0;
	while (vars->mapcopy[++x])
	{
		y = -1;
		while (vars->mapcopy[x][++y])
		{
			if (vars->mapcopy[x][y] == 'E')
			{
				if (vars->mapcopy[x - 1][y] != 'P'
				&& vars->mapcopy[x + 1][y] != 'P'
				&& vars->mapcopy[x][y - 1] != 'P'
				&& vars->mapcopy[x][y + 1] != 'P')
					tr++;
			}
			if (vars->mapcopy[x][y] == 'C')
				tr++;
		}
	}
	free_map(vars->mapcopy);
	if (tr != 0)
		ft_perror("invalid path\n");
}

void	check_path(t_vars *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = -1;
	while (vars->mapcopy[++x])
	{
		y = -1;
		while (vars->mapcopy[x][++y])
		{
			if (vars->mapcopy[x][y] == 'P')
			{
				if (pos_filled(vars->mapcopy, x, y))
				{
					x = 0;
					y = 0;
				}
			}
		}
	}
	check_exit(vars, i, j);
}
