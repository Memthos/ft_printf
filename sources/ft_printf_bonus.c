/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:34:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/03 23:48:40 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int	is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

static void	parse_flags(char *format, t_ft_printf *data, int *i)
{
}

static int	ft_parse_specifiers(char *s, t_ft_printf *data, int *i)
{
	while (s[*i] && is_flag(s[*i]))
		parse_flags(s, data, i++);
	if (s[*i] == 'c')
		ft_putchar(va_arg(*(data->args), int), data);
	else if (s[*i] == 's')
		ft_putstr(va_arg(*(data->args), char *), data);
	else if (s[*i] == 'p')
		ft_putpointer((unsigned long int)va_arg(*(data->args), void *), data);
	else if (s[*i] == 'd' || s[*i] == 'i')
		ft_putnbr(va_arg(*(data->args), int), data);
	else if (s[*i] == 'u')
		ft_putnbr_unsigned(va_arg(*(data->args), unsigned int), data);
	else if (s[*i] == 'x')
		ft_puthexa((unsigned int)va_arg(*(data->args), int), 0, data);
	else if (s[*i] == 'X')
		ft_puthexa((unsigned int)va_arg(*(data->args), int), 1, data);
	else if (s[*i] == '%')
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
			i++;
			if (!ft_parse_specifiers(format, &data, &i))
				i++;
		}
		else
			ft_putchar(format[i++], &data);
	}
	va_end(args_list);
	return (data.printed);
}
