/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:35:14 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/16 13:13:57 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int	size;

	i = 0;
	size = ft_strlen(s);
	while (i < size && !data->res)
		ft_putchar(s[i++], data);
}
