/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:13:13 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/22 02:16:54 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map, int len)
{
	char	**map2;
	int		x;

	map2 = malloc(sizeof(char *) * len + 1);
	if (!map2)
		return (NULL);
	x = -1;
	while (map[++x])
		map2[x] = ft_strdup(map[x]);
	map2[x] = NULL;
	return (map2);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac != 2 || !valid_extention(av[1]))
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_memset(&vars, 0, sizeof(t_vars));
	parse_map(&vars, av[1]);
	if (!vars.map)
		return (ft_putstr_fd("Error\n", 2), 1);
	check_map(&vars);
	vars.mapcopy = copy_map(vars.map, vars.m_h);
	if (!vars.mapcopy)
		ft_perror("Error\n");
	check_path(&vars);
	render_game(&vars);
	return (0);
}
