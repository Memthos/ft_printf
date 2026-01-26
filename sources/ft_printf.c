/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:34:05 by mperrine          #+#    #+#             */
/*   Updated: 2025/12/01 12:03:28 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_parse_specifiers(const char c, va_list args, int *size, int *i)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_putchar(va_arg(args, int), size);
	else if (c == 's')
		res = ft_putstr(va_arg(args, char *), size);
	else if (c == 'p')
		res = ft_putpointer((unsigned long int)va_arg(args, void *), size);
	else if (c == 'd' || c == 'i')
		res = ft_putnbr(va_arg(args, int), size);
	else if (c == 'u')
		res = ft_putnbr_unsigned(va_arg(args, unsigned int), size);
	else if (c == 'x')
		res = ft_puthexa((unsigned int)va_arg(args, int),
				"0123456789abcdef", size);
	else if (c == 'X')
		res = ft_puthexa((unsigned int)va_arg(args, int),
				"0123456789ABCDEF", size);
	else if (c == '%')
		res = ft_putchar('%', size);
	*i += 2;
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		size;

	if (!format)
		return (0);
	i = 0;
	size = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (ft_parse_specifiers(format[i + 1], args, &size, &i) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(format[i], &size) == -1)
				return (-1);
			i++;
		}
	}
	va_end(args);
	return (size);
}
