/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_maths_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:33:24 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/03 23:36:18 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

static void	ft_putpointer_address(unsigned long int ptr, t_ft_printf *data)
{
	const char			base[] = "0123456789abcdef";

	if (data->res)
		return ;
	if (ptr > 15)
		ft_putpointer_address(ptr / 16, data);
	ft_putchar(base[ptr % 16], data);
}

void	ft_putpointer(unsigned long int ptr, t_ft_printf *data)
{
	if (!ptr)
	{
		ft_putstr("(nil)", data);
		return ;
	}
	ft_putstr("0x", data);
	ft_putpointer_address(ptr, data);
}

void	ft_putnbr(int nb, t_ft_printf *data)
{
	long	nb_long;

	if (data->res)
		return ;
	nb_long = nb;
	if (nb_long < 0)
	{
		ft_putchar('-', data);
		nb_long = -nb_long;
	}
	if (nb_long > 9)
		ft_putnbr(nb_long / 10, data);
	ft_putchar(nb_long % 10 + 48, data);
}

void	ft_putnbr_unsigned(unsigned int nb, t_ft_printf *data)
{
	if (data->res)
		return ;
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10, data);
	ft_putchar(nb % 10 + 48, data);
}

void	ft_puthexa(unsigned int nb, int type, t_ft_printf *data)
{
	const char			lower[] = "0123456789abcdef";
	const char			upper[] = "0123456789ABCDEF";

	if (data->res)
		return ;
	if (nb > 15)
		ft_puthexa(nb / 16, type, data);
	if (type == 0)
		ft_putchar(lower[nb % 16], data);
	else
		ft_putchar(upper[nb % 16], data);
}
