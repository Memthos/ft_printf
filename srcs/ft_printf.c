/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:34:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/16 13:16:38 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print(t_ft_printf *data)
{
	if (data->conv == 'c')
		ft_putchar(va_arg(*data->args, int), data);
	else if (data->conv == 's')
		str_arg(va_arg(*data->args, char *), data);
	else if (data->conv == 'p')
		pointer_arg((size_t)va_arg(*data->args, void *), data);
	else if (data->conv == 'd' || data->conv == 'i')
		nb_arg((long)va_arg(*data->args, int), data);
	else if (data->conv == 'u')
		nb_arg((long)va_arg(*data->args, unsigned int), data);
	else if (data->conv == 'x' || data->conv == 'X')
		hex_arg((unsigned int)va_arg(*data->args, int), data);
	else if (data->conv == '%')
		ft_putchar('%', data);
}

static int	is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	conversion(const char *s, t_ft_printf *data, size_t *i)
{
	data->conv = 0;
	if (!is_conversion(s[0]))
		return (1);
	data->conv = s[0];
	(*i)++;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_ft_printf	data;
	va_list		args;
	size_t		i;

	if (!format)
		return (-1);
	i = 0;
	va_start(args, format);
	data = (t_ft_printf){&args, 0, 0, 0};
	while (!data.res && format[i++])
	{
		if (format[i - 1] == '%')
		{
			if (!conversion(format + i, &data, &i))
			{
				print(&data);
				continue ;
			}
		}
		ft_putchar(format[i - 1], &data);
	}
	va_end(args);
	if (data.res)
		return (-1);
	return (data.printed);
}
