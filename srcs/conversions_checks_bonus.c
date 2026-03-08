/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_checks_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:23:49 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/08 22:52:17 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static int	is_unsigned(char c)
{
	if (c == 'x' || c == 'X' || c == 'u')
		return (1);
	return (0);
}

void	conversion_check(t_ft_printf *data)
{
	if (data->flags.conv == 'c' || data->flags.conv == 's'
		|| data->flags.conv == 'p')
	{
		data->flags.sign = 0;
		data->flags.space = 0;
		data->flags.zero = 0;
		data->flags.alt = 0;
	}
	if (data->flags.conv == 'c' || data->flags.conv == 'p')
		data->flags.prec = -1;
	if (data->flags.conv == 'd' || data->flags.conv == 'i'
		|| data->flags.conv == 'u')
		data->flags.alt = 0;
	if (is_unsigned(data->flags.conv))
	{
		data->flags.sign = 0;
		data->flags.space = 0;
	}
	if ((data->flags.conv == 'd' || data->flags.conv == 'i'
			|| is_unsigned(data->flags.conv))
		&& (data->flags.zero && (data->flags.prec != -1 || data->flags.left)))
		data->flags.zero = 0;
	if ((data->flags.conv == 'd' || data->flags.conv == 'i')
		&& data->flags.sign && data->flags.space)
		data->flags.space = 0;
}

int	is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int	is_length(char c)
{
	if (c == '.' || ft_isdigit(c))
		return (1);
	return (0);
}

int	is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
