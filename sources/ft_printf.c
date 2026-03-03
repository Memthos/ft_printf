/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:34:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/03 23:29:42 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	ft_parse_specifiers(const char c, t_ft_printf *data)
{
	if (c == 'c')
		ft_putchar(va_arg(*(data->args), int), data);
	else if (c == 's')
		ft_putstr(va_arg(*(data->args), char *), data);
	else if (c == 'p')
		ft_putpointer((unsigned long int)va_arg(*(data->args), void *), data);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*(data->args), int), data);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(*(data->args), unsigned int), data);
	else if (c == 'x')
		ft_puthexa((unsigned int)va_arg(*(data->args), int), 0, data);
	else if (c == 'X')
		ft_puthexa((unsigned int)va_arg(*(data->args), int), 1, data);
	else if (c == '%')
		ft_putchar('%', data);
	else
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_ft_printf	data;
	va_list		args_list;
	int			i;

	if (!format)
		return (0);
	i = 0;
	va_start(args_list, format);
	data = (t_ft_printf){&args_list, 0, 0};
	while (!data.res && format[i])
	{
		if (format[i] == '%')
		{
			if (!ft_parse_specifiers(format[++i], &data))
				i++;
		}
		else
			ft_putchar(format[i++], &data);
	}
	va_end(args_list);
	return (data.printed);
}
