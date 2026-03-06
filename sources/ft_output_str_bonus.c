/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:46:55 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/06 15:26:58 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

void	char_arg(char c, t_ft_printf *data)
{
	char	*s;

	if (data->flags.sign || data->flags.space || data->flags.zero
		|| data->flags.alt || data->flags.prec != 0)
	{
		data->res = CONVERSION;
		return ;
	}
	s = malloc(sizeof(char) * (data->flags.wdt + 1));
	if (!s)
	{
		data->res = 1;
		return ;
	}
	if (data->flags.left)
		s[0] = c;
	else
		s[data->flags.wdt] = c;
	ft_putstr(s, data);
}

void	str_arg(char *str, t_ft_printf *data)
{
	char	*s;
	int		i;
	int		j;

	if (!s)
	{
		ft_putstr("(null)", data);
		return ;
	}
	if (data->flags.sign || data->flags.space || data->flags.zero
		|| data->flags.alt)
	{
		data->res = CONVERSION;
		return ;
	}
	if (data->flags.wdt > data->flags.prec)
		s = malloc(sizeof(char) * (data->flags.wdt + 1));
	else if (data->flags.prec != 0)
		s = malloc(sizeof(char) * (data->flags.prec + 1));
	else
		s = str;
	if (!s)
	{
		data->res = 1;
		return ;
	}
	i = 0;
	while (data->flags.wdt - i != 0 && data->flags.wdt - i > data->flags.prec)
		s[i++] = ' ';
	j = 0;
	while (data->flags.prec - j != 0)
		s[i++] = str[j++];
	ft_putstr(s, data);
}
