/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:33:24 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/08 22:08:39 by mperrine         ###   ########.fr       */
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
	if (width_base(&s, 0, 1, data))
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
	if (width_base(&s, 0, ft_strlen(s), data))
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
	ft_strncpy(s, "0x", 2);
	set_hex_value(s, ptr, get_hex_size(ptr) + 1, data);
	if (width_base(&s, 2, ft_strlen(s), data))
		return ;
	ft_putstr(s, data);
	free(s);
}

void	nb_arg(long nb, t_ft_printf *data)
{
	char	*s;
	int		prefix;

	prefix = 0;
	if ((nb >= 0 && (data->flags.sign || data->flags.space)) || nb < 0)
		prefix++;
	s = ft_calloc(get_dec_size(nb) + prefix + 1, sizeof(char));
	if (!s)
	{
		data->res = 1;
		return ;
	}
	set_nb_prefix(s, nb, data);
	set_dec_value(s + prefix, nb, get_dec_size(nb) - 1, data);
	if (apply_precision_nb(&s, prefix, data))
		return ;
	if (width_base(&s, prefix, ft_strlen(s), data))
		return ;
	ft_putstr(s, data);
	free(s);
}

void	hex_arg(unsigned int nb, t_ft_printf *data)
{
	char	*s;
	int		size;

	size = 0;
	if (data->flags.alt && nb != 0)
		size += 2;
	s = ft_calloc(get_hex_size(nb) + size + 1, sizeof(char));
	if (!s)
	{
		data->res = 1;
		return ;
	}
	if (nb != 0)
		set_nb_prefix(s, 0, data);
	set_hex_value(s, (size_t)nb, get_hex_size(nb) + size - 1, data);
	if (apply_precision_nb(&s, size, data))
		return ;
	if (width_base(&s, size, ft_strlen(s), data))
		return ;
	ft_putstr(s, data);
	free(s);
}
