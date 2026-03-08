/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:31:12 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/07 23:48:13 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print(t_ft_printf *data)
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
		hex_arg((size_t)va_arg(*data->args, int), data);
	else if (data->flags.conv == '%')
		ft_putchar('%', data);
}

void	dummy_print(t_ft_printf *data)
{
	if (data->flags.conv == 'c')
		va_arg(*data->args, int);
	else if (data->flags.conv == 's')
		va_arg(*data->args, char *);
	else if (data->flags.conv == 'p')
		va_arg(*data->args, void *);
	else if (data->flags.conv == 'd' || data->flags.conv == 'i')
		va_arg(*data->args, int);
	else if (data->flags.conv == 'u')
		va_arg(*data->args, unsigned int);
	else if (data->flags.conv == 'x' || data->flags.conv == 'X')
		va_arg(*data->args, int);
}
