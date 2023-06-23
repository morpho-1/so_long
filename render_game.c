/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:37:37 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/22 08:58:51 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (vars->map[++y])
	{
		x = -1;
		while (vars->map[y][++x] && vars->map[y][x] != '\n')
		{
			ft_put_image(vars, x, y);
		}
	}
}

void	ft_move(t_vars *vars, int row, int col)
{
	static int	moves;

	if (vars->map[vars->px + row][vars->py + col] != '1')
	{
		if (vars->map[vars->px + row][vars->py + col] == 'C')
			vars->coins--;
		else if (vars->map[vars->px + row][vars->py + col] == 'E')
		{
			if (!vars->coins)
			{
				write (1, "Congratulations you have finished the game !!\n", 46);
				exit(0);
			}
			return ;
		}
		vars->map[vars->px + row][vars->py + col] = 'P';
		vars->map[vars->px][vars->py] = '0';
		vars->px += row;
		vars->py += col;
		ft_printf("Moves : %d\n", ++moves);
		render_map(vars);
	}
}

int	move_player(int key, t_vars *vars)
{
	int	row;
	int	col;

	if (key == ESC)
	{
		write (1, "GAME OVER\n", 10);
		exit(0);
	}
	row = (key == DW || key == 1) + (key == UP || key == 13) * (-1);
	col = (key == RT || key == 2) + (key == LF || key == 0) * (-1);
	if (!row && !col)
		return (1);
	ft_move(vars, row, col);
	return (1);
}

void	render_game(t_vars *vars)
{
	int	width;
	int	height;

	width = (vars->m_w - 1) * 50;
	height = (vars->m_h) * 50;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, width, height, "SO_LONG");
	init_images(vars);
	render_map(vars);
	mlx_hook(vars->win, 2, 0, move_player, vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_loop(vars->mlx);
}
