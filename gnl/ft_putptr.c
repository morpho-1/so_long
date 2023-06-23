/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:41:37 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/21 05:43:51 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putptr(unsigned long nb)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthexa(nb, 'x');
	return (len);
}
