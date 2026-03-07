/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:34:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/07 23:30:02 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	set_flag(const char *format, t_ft_printf *data, size_t *i)
{
	if (format[*i] == '-' && !data->flags.left)
		data->flags.left = 1;
	else if (format[*i] == '+' && !data->flags.sign)
		data->flags.sign = 1;
	else if (format[*i] == ' ' && !data->flags.space)
		data->flags.space = 1;
	else if (format[*i] == '#' && !data->flags.alt)
		data->flags.alt = 1;
	else if (format[*i] == '0' && !data->flags.zero)
		data->flags.zero = 1;
	else
		return (1);
	return (0);
}

static int	set_length(const char *format, t_ft_printf *data, size_t *i)
{
	if (format[*i] == '.' && data->flags.prec == -1)
	{
		(*i)++;
		data->flags.prec = get_number(format, i);
	}
	else if (format[*i] == '*' && data->flags.wdt == -1)
		data->flags.wdt = va_arg(*(data->args), int);
	else if (ft_isdigit(format[*i]) && data->flags.wdt == -1)
		data->flags.wdt = get_number(format, i);
	else
		return (1);
	return (0);
}

static int	conversion(const char *s, t_ft_printf *data, size_t *i)
{
	data->flags = (t_flags){0, 0, 0, 0, 0, 0, -1, -1};
	while (s[*i] && (is_flag(s[*i])))
	{
		if (set_flag(s, data, i))
			return (1);
		(*i)++;
	}
	while (s[*i] && is_length(s[*i]))
	{
		if (set_length(s, data, i))
			return (1);
		(*i)++;
	}
	if (!is_conversion(s[*i]))
		return (1);
	data->flags.conv = s[(*i)++];
	if (conversion_check(data))
		return (1);
	return (0);
}

int	check_input(const char *format, va_list list)
{
	t_ft_printf	data;
	va_list		copy;
	size_t		i;

	va_copy(copy, list);
	data = (t_ft_printf){&copy, 0, 0, {0, 0, 0, 0, 0, 0, -1, -1}};
	i = 0;
	while (format[i++])
	{
		if (format[i - 1] == '%')
		{
			if (conversion(format, &data, &i))
			{
				va_end(copy);
				return (1);
			}
			dummy_print(&data);
		}
	}
	va_end(copy);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_ft_printf	data;
	va_list		args;
	size_t		i;

	if (!format)
		return (0);
	i = 0;
	va_start(args, format);
	data = (t_ft_printf){&args, 0, 0, {0, 0, 0, 0, 0, 0, -1, -1}};
	if (check_input(format, args))
		return (-1);
	while (!data.res && format[i++])
	{
		if (format[i - 1] == '%')
		{
			conversion(format, &data, &i);
			print(&data);
		}
		else
			ft_putchar(format[i - 1], &data);
	}
	va_end(args);
	return (data.printed);
}
