/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:44:00 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/21 05:44:22 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putnbr(int nb)
{
	int		len;
	long	a;

	len = 0;
	a = nb;
	if (nb < 0)
	{
		a = -a;
		len += ft_putchar('-');
	}
	if (a < 10)
		len += ft_putchar(a + '0');
	else
	{
		len += ft_putnbr(a / 10);
		len += ft_putnbr(a % 10);
	}
	return (len);
}
