/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_str_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:46:55 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/03 23:36:23 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_bonus.h"

void	ft_putchar(char c, t_ft_printf *data)
{
	if (data->res)
		return ;
	if (write(1, &c, 1) == -1)
		data->res = 1;
	data->printed += 1;
}

void	ft_putstr(char *s, t_ft_printf *data)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", data);
		return ;
	}
	while (!data->res && s[i])
		ft_putchar(s[i++], data);
}
