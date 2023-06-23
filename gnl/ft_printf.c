/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylemrab <aylemrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 05:41:21 by aylemrab          #+#    #+#             */
/*   Updated: 2023/06/21 05:41:23 by aylemrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_put_format(va_list args, char c)
{
	int		len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		len += ft_puthexa(va_arg(args, unsigned int), c);
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'u')
		len += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'p')
		len += ft_putptr(va_arg(args, unsigned long));
	else if (c == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				len;
	int				i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (write(1, 0, 0) == -1)
			return (-1);
		if (format[i] == '%' && format[i + 1])
		{
			len += ft_put_format(args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			len += ft_putchar(format[i]);
		i++;
	}
	return (va_end(args), len);
}
