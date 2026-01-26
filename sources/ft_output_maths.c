/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:33:24 by mperrine          #+#    #+#             */
/*   Updated: 2025/12/01 12:03:39 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putpointer_address(unsigned long int ptr, int *size)
{
	const char			base[] = "0123456789abcdef";

	if (ptr > 15)
	{
		if (ft_putpointer_address(ptr / 16, size) == -1)
			return (-1);
	}
	if (ft_putchar(base[ptr % 16], size) == -1)
		return (-1);
	return (1);
}

int	ft_putpointer(unsigned long int ptr, int *size)
{
	if (!ptr)
	{
		if (ft_putstr("(nil)", size) == -1)
			return (-1);
		return (1);
	}
	if (ft_putstr("0x", size) == -1)
		return (-1);
	if (ft_putpointer_address(ptr, size) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr_unsigned(unsigned int nb, int *size)
{
	if (nb > 9)
	{
		if (ft_putnbr_unsigned(nb / 10, size) == -1)
			return (-1);
	}
	if (ft_putchar(nb % 10 + 48, size) == -1)
		return (-1);
	return (1);
}

int	ft_puthexa(unsigned int nb, const char *base, int *size)
{
	if (nb > 15)
	{
		if (ft_puthexa(nb / 16, base, size) == -1)
			return (-1);
	}
	if (ft_putchar(base[nb % 16], size) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr(int n, int *size)
{
	if (n == -2147483648)
	{
		if (ft_putstr("-2147483648", size) == -1)
			return (-1);
		return (11);
	}
	if (n < 0)
	{
		if (ft_putchar('-', size) == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		if (ft_putnbr(n / 10, size) == -1)
			return (-1);
	}
	if (ft_putchar(n % 10 + 48, size) == -1)
		return (-1);
	return (1);
}
