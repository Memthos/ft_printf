/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:34:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/16 15:12:35 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	print(t_ft_printf *data)
{
	if (data->flags.conv == 'c')
		char_arg(va_arg(*data->args, int), data);
	else if (data->flags.conv == 's')
		str_arg(va_arg(*data->args, char *), data);
	else if (data->flags.conv == 'p')
		pointer_arg((size_t)va_arg(*data->args, void *), data);
	else if (data->flags.conv == 'd' || data->flags.conv == 'i')
		nb_arg((long)va_arg(*data->args, int), data);
	else if (data->flags.conv == 'u')
		nb_arg((long)va_arg(*data->args, unsigned int), data);
	else if (data->flags.conv == 'x' || data->flags.conv == 'X')
		hex_arg((unsigned int)va_arg(*data->args, int), data);
	else if (data->flags.conv == '%')
		ft_putchar('%', data);
}

static int	set_flag(const char c, t_ft_printf *data)
{
	if (c == '-')
		data->flags.left = 1;
	else if (c == '+')
		data->flags.sign = 1;
	else if (c == ' ')
		data->flags.space = 1;
	else if (c == '#')
		data->flags.alt = 1;
	else if (c == '0')
		data->flags.zero = 1;
	else
		return (1);
	return (0);
}

static int	set_length(const char *format, t_ft_printf *data, size_t *add)
{
	if (format[*add] == '.' && data->flags.prec == -1)
	{
		(*add)++;
		if (format[*add] == '*')
		{
			data->flags.prec = va_arg(*(data->args), int);
			(*add)++;
		}
		else
			data->flags.prec = get_number(format, add);
	}
	else if (format[*add] == '*' && data->flags.wdt == -1)
	{
		data->flags.wdt = va_arg(*(data->args), int);
		(*add)++;
	}
	else if (ft_isdigit(format[*add]) && data->flags.wdt == -1)
		data->flags.wdt = get_number(format, add);
	else
		return (1);
	return (0);
}

static int	conversion(const char *s, t_ft_printf *data, size_t *i)
{
	size_t	add;

	data->flags = (t_flags){0, 0, 0, 0, 0, 0, -1, -1};
	add = 0;
	while (s[add] && (is_flag(s[add])))
	{
		if (set_flag(s[add], data))
			return (1);
		add++;
	}
	while (s[add] && is_length(s[add]))
	{
		if (set_length(s, data, &add))
			return (1);
	}
	if (!is_conversion(s[add]))
		return (1);
	data->flags.conv = s[add++];
	*i += add;
	conversion_check(data);
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
	data = (t_ft_printf){&args, 0, 0, {0, 0, 0, 0, 0, 0, -1, -1}};
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
