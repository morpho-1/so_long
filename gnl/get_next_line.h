/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:15:55 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/22 00:51:48 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr2(char *s, int c);
int		ft_printf(const char *format, ...);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_puthexa(unsigned long nb, char c);
int		ft_putunbr(unsigned int nb);
int		ft_putptr(unsigned long nb);

#endif