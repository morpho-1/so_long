/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:45:09 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/21 05:45:32 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_puthexa(unsigned long nb, char c)
{
	int		len;
	char	*str;

	len = 0;
	if (c == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	if (nb < 16)
		len += ft_putchar(str[nb]);
	else
	{
		len += ft_puthexa(nb / 16, c);
		len += ft_puthexa(nb % 16, c);
	}
	return (len);
}
