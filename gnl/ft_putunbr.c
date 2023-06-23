/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:45:53 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/21 05:46:06 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putunbr(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb < 10)
		len += ft_putchar(nb + '0');
	else if (nb > 9)
	{
		len += ft_putunbr(nb / 10);
		len += ft_putunbr(nb % 10);
	}
	return (len);
}
