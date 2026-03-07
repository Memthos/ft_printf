/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:33:24 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/07 23:29:33 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	char_arg(char c, t_ft_printf *data)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	if (!s)
	{
		data->res = 1;
		return ;
	}
	s[0] = c;
	if (apply_width(&s, ' ', data))
		return ;
	ft_putstr(s, data);
	free(s);
}

void	str_arg(char *str, t_ft_printf *data)
{
	char	*s;

	if (!str)
	{
		ft_putstr("(null)", data);
		return ;
	}
	s = ft_strdup(str);
	if (!s)
	{
		data->res = 1;
		return ;
	}
	if (apply_precision_str(&s, data))
		return ;
	if (apply_width(&s, ' ', data))
		return ;
	ft_putstr(s, data);
	free(s);
}

void	pointer_arg(size_t ptr, t_ft_printf *data)
{
	char	*s;

	if (!ptr)
	{
		ft_putstr("(nil)", data);
		return ;
	}
	s = ft_calloc(get_hex_size(ptr) + 3, sizeof(char));
	if (!s)
	{
		data->res = 1;
		return ;
	}
	ft_strlcpy(s, "0x", 3);
	set_hex_value(s + 2, ptr, get_hex_size(ptr) + 1, data);
	if (apply_width(&s, ' ', data))
		return ;
	ft_putstr(s, data);
	free(s);
}
#include <stdio.h>
void	nb_arg(long nb, t_ft_printf *data)
{
	char	*s;
	char	fill;
	int		size;

	size = 0;
	if ((data->flags.sign && nb > 0) || data->flags.space)
		size++;
	s = ft_calloc(get_dec_size(nb) + size + 1, sizeof(char));
	if (!s)
	{
		data->res = 1;
		return ;
	}
	set_nb_prefix(s, &nb, data);
	set_dec_value(s + size, nb, get_dec_size(nb) + size - 1, data);
	if (apply_precision_nb(&s, data))
		return ;
	if (data->flags.zero)
		fill = '0';
	else
		fill = ' ';
	if (apply_width(&s, fill, data))
		return ;
	ft_putstr(s, data);
	free(s);
}

void	hex_arg(size_t nb, t_ft_printf *data)
{
	char	*s;
	char	fill;
	int		size;

	size = 0;
	if (data->flags.alt)
		size += 2;
	s = ft_calloc(get_hex_size(nb) + size + 1, sizeof(char));
	if (!s)
	{
		data->res = 1;
		return ;
	}
	set_nb_prefix(s, 0, data);
	set_hex_value(s + size, nb, get_hex_size(nb) + size - 1, data);
	if (apply_precision_nb(&s, data))
		return ;
	if (data->flags.zero)
		fill = '0';
	else
		fill = ' ';
	if (apply_width(&s, fill, data))
		return ;
	ft_putstr(s, data);
	free(s);
}
