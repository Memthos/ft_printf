/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_checks_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 14:23:49 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/07 20:59:45 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	conversion_check(t_ft_printf *data)
{
	if (data->flags.conv == 'c' && (data->flags.sign || data->flags.space
			|| data->flags.zero || data->flags.alt || data->flags.prec != -1))
		return (1);
	else if (data->flags.conv == 's' && (data->flags.sign || data->flags.space
			|| data->flags.zero || data->flags.alt))
		return (1);
	else if (data->flags.conv == 'p' && (data->flags.sign || data->flags.space
			|| data->flags.zero || data->flags.alt || data->flags.prec != -1))
		return (1);
	else if ((data->flags.conv == 'd' || data->flags.conv == 'i')
		&& ((data->flags.zero && (data->flags.left || data->flags.prec != -1))
			|| data->flags.alt || (data->flags.sign && data->flags.space)))
		return (1);
	else if (data->flags.conv == 'u' && (data->flags.sign || data->flags.space
			|| data->flags.alt || (data->flags.zero && data->flags.prec != -1)))
		return (1);
	else if ((data->flags.conv == 'x' || data->flags.conv == 'X')
		&& (data->flags.sign || data->flags.space
			|| (data->flags.zero && data->flags.prec != -1)))
		return (1);
	else if (data->flags.conv == '%' && (data->flags.left || data->flags.zero
			|| data->flags.prec != -1 || data->flags.alt || data->flags.sign
			|| data->flags.space || data->flags.wdt != -1))
		return (1);
	return (0);
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
