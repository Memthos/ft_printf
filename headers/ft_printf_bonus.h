/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:33:17 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/03 23:35:07 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_ft_printf
{
	va_list	*args;
	size_t	printed;
	int		res;
}			t_ft_printf;

int			ft_printf(const char *format, ...);

void		ft_putstr(char *s, t_ft_printf *data);
void		ft_putchar(char c, t_ft_printf *data);
void		ft_putnbr(int nb, t_ft_printf *data);
void		ft_putpointer(unsigned long int ptr, t_ft_printf *data);
void		ft_putnbr_unsigned(unsigned int nb, t_ft_printf *data);
void		ft_puthexa(unsigned int nb, int type, t_ft_printf *data);

#endif
