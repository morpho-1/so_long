/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:26:47 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/22 08:14:11 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_norme(t_vars *vars, int i, int fd)
{
	while (1)
	{
		vars->map[i] = get_next_line(fd);
		if (!vars->map[i])
			break ;
		i++;
	}
}

void	parse_map(t_vars *vars, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY | O_CREAT);
	if (fd < 0)
		ft_perror("Error\n");
	line = get_next_line(fd);
	if (!line)
		ft_perror("Error\n");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		vars->m_h++;
	}
	close (fd);
	vars->map = malloc(sizeof(char *) * vars->m_h + 1);
	if (!vars->map)
		ft_perror("malloc failed\n");
	fd = open(file, O_RDONLY | O_CREAT);
	i = 0;
	ft_norme(vars, i, fd);
	close(fd);
}
