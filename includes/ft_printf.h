/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:33:17 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/17 10:30:10 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "utils.h"

typedef struct s_ft_printf
{
	va_list	*args;
	size_t	printed;
	int		res;
	char	conv;
}			t_ft_printf;

int		ft_printf(const char *format, ...);

void	str_arg(char *str, t_ft_printf *data);
void	pointer_arg(size_t ptr, t_ft_printf *data);
void	nb_arg(long nb, t_ft_printf *data);
void	hex_arg(unsigned int nb, t_ft_printf *data);

void	ft_putchar(char c, t_ft_printf *data);
void	ft_putstr(char *s, t_ft_printf *data);

#endif
