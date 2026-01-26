/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:46:55 by mperrine          #+#    #+#             */
/*   Updated: 2025/12/01 12:03:33 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_putchar(char c, int *size)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	*size += 1;
	return (1);
}

int	ft_putstr(char *s, int *size)
{
	int	i;

	i = 0;
	if (!s)
	{
		if (ft_putstr("(null)", size) == -1)
			return (-1);
		return (6);
	}
	while (s[i])
	{
		if (ft_putchar(s[i], size) == -1)
			return (-1);
		i++;
	}
	return (1);
}
