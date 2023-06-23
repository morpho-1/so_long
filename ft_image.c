/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:36:45 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/22 08:55:39 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_vars *vars)
{
	int	w;
	int	h;

	vars->img.player = mlx_xpm_file_to_image(vars->mlx, PL, &w, &h);
	vars->img.coin = mlx_xpm_file_to_image(vars->mlx, C, &w, &h);
	vars->img.door = mlx_xpm_file_to_image(vars->mlx, D, &w, &h);
	vars->img.road = mlx_xpm_file_to_image(vars->mlx, B, &w, &h);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx, W, &w, &h);
	if (!vars->img.player || !vars->img.coin
		|| !vars->img.road || !vars->img.wall || !vars->img.door)
		ft_perror("Error\n");
}

void	ft_put_image(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->img.coin, x * 50, y * 50);
	else if (vars->map[y][x] == 'P')
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->img.player, x * 50, y * 50);
	else if (vars->map[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->img.wall, x * 50, y * 50);
	else if (vars->map[y][x] == '0')
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->img.road, x * 50, y * 50);
	else
		mlx_put_image_to_window(vars->mlx, \
		vars->win, vars->img.door, x * 50, y * 50);
}
