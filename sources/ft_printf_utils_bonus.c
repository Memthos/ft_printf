/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:35:14 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/07 13:24:06 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	ft_putchar(char c, t_ft_printf *data)
{
	if (write(1, &c, 1) == -1)
	{
		data->res = 1;
		return ;
	}
	data->printed += 1;
}

void	ft_putstr(char *s, t_ft_printf *data)
{
	int	i;

	i = 0;
	while (s[i] && !data->res)
		ft_putchar(s[i++], data);
}

int	get_number(const char *format, int *i)
{
	long	res;

	res = 0;
	while (format[*i] && (format[*i] >= '0' && format[*i] <= '9'))
		res = (res * 10) + (format[(*i)++]) - '0';
	if (res > INT_MAX)
		return (0);
	return (res);
}
