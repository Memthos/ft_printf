/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:33:24 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/16 13:13:57 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	set_nb_prefix(char *s, long nb, t_ft_printf *data)
{
	if (data->flags.sign || nb < 0)
	{
		if (nb < 0)
			s[0] = '-';
		else
			s[0] = '+';
	}
	else if (data->flags.space)
		s[0] = ' ';
	else if (data->flags.alt)
	{
		if (data->flags.conv == 'x')
			ft_strncpy(s, "0x", 2);
		else
			ft_strncpy(s, "0X", 2);
	}
}

int	get_hex_size(size_t nb)
{
	if (nb < 16)
		return (1);
	return (1 + get_hex_size(nb / 16));
}

int	get_dec_size(long nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb < 10)
		return (1);
	return (1 + get_dec_size(nb / 10));
}

void	set_dec_value(char *s, long nb, size_t cur, t_ft_printf *data)
{
	if (nb < 0)
		nb = -nb;
	if (nb > 9)
		set_dec_value(s, nb / 10, cur - 1, data);
	s[cur] = nb % 10 + '0';
}

void	set_hex_value(char *s, size_t nb, size_t cur, t_ft_printf *data)
{
	const char	lower[] = "0123456789abcdef";
	const char	upper[] = "0123456789ABCDEF";

	if (nb > 15)
		set_hex_value(s, nb / 16, cur - 1, data);
	if (data->flags.conv == 'X')
		s[cur] = upper[nb % 16];
	else
		s[cur] = lower[nb % 16];
}
