/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:34:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/05 13:32:18 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

static int	is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '#' || c == ' ' || c == '+')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	set_flag(size_t	*param, int value, size_t *idx)
{
	*param = (size_t)value;
	(*idx)++;
}

int	ft_atoi(const char *format, int *i)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (format[*i] == '+' || format[*i] == '-')
		sign = ((format[(*i)++] % 43) * -1) + 1;
	while (format[*i] && (format[*i] >= '0' && format[*i] <= '9'))
		res = (res * 10) + (format[(*i)++]) - '0';
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		return (0);
	return (res * sign);
}

static t_codes	parse_flags(const char *format, t_ft_printf *data, size_t *i)
{
	if (format[*i] == '-')
		set_flag(&data->flags.left, 1, i);
	else if (format[*i] == '0')
		set_flag(&data->flags.zero, 1, i);
	else if (format[*i] == '.')
		data->flags.prec = ft_atoi(format, ++(*i));
	else if (format[*i] == '#')
		set_flag(&data->flags.alt, 1, i);
	else if (format[*i] == '+')
		set_flag(&data->flags.sign, 1, i);
	else if (format[*i] == ' ')
		set_flag(&data->flags.space, 1, i);
	else if (format[*i] == '*')
		set_flag(&data->flags.wdt, va_arg(*(data->args), int), i);
	else if (ft_is_digit(format[*i]))
	{
		if (data->flags.wdt != 0)
			return (CONVERSION);
		data->flags.wdt = ft_atoi(format, i);
	}
	if (is_flag(format[*i]) || (data->flags.left && data->flags.zero)
			|| (data->flags.sign && data->flags.space))
		return (CONVERSION);
	return (SUCCESS);
}

static int	ft_parse_specifiers(const char *s, t_ft_printf *data, size_t *i)
{
	data->flags = (t_flags){0, 0, 0, 0, 0, 0, 0};
	while (s[*i] && is_flag(s[*i]))
	{
		if (parse_flags(s, data, i))
			return (CONVERSION);
	}
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
		return (CONVERSION);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_ft_printf	data;
	va_list		args_list;
	size_t		i;

	if (!format)
		return (0);
	i = 0;
	va_start(args_list, format);
	data = (t_ft_printf){&args_list, 0, 0, {0, 0, 0, 0, 0, 0, 0}};
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
