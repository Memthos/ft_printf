/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:33:24 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/16 13:13:57 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_arg(char *str, t_ft_printf *data)
{
	if (!str)
	{
		ft_putstr("(null)", data);
		return ;
	}
	ft_putstr(str, data);
}

static void	print_pointer(size_t ptr, t_ft_printf *data)
{
	const char	base[] = "0123456789abcdef";

	if (data->res)
		return ;
	if (ptr > 15)
		print_pointer(ptr / 16, data);
	ft_putchar(base[ptr % 16], data);
}

void	pointer_arg(size_t ptr, t_ft_printf *data)
{
	if (!ptr)
	{
		ft_putstr("(nil)", data);
		return ;
	}
	ft_putstr("0x", data);
	print_pointer(ptr, data);
}

void	nb_arg(long nb, t_ft_printf *data)
{
	if (data->res)
		return ;
	if (nb < 0)
	{
		ft_putchar('-', data);
		if (data->res)
			return ;
		nb = -nb;
	}
	if (nb > 9)
		nb_arg(nb / 10, data);
	ft_putchar(nb % 10 + '0', data);
}

void	hex_arg(unsigned int nb, t_ft_printf *data)
{
	const char	lower[] = "0123456789abcdef";
	const char	upper[] = "0123456789ABCDEF";

	if (data->res)
		return ;
	if (nb > 15)
		hex_arg(nb / 16, data);
	if (data->conv == 'x')
		ft_putchar(lower[nb % 16], data);
	else
		ft_putchar(upper[nb % 16], data);
}
