/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:33:17 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/05 00:23:43 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	int		left;
	int		sign;
	int		space;
	int		zero;
	int		alt;
	size_t	wdt;
	size_t	prec;
}			t_flags;

typedef struct s_ft_printf
{
	va_list	*args;
	size_t	printed;
	int		res;
	t_flags	flags;
}			t_ft_printf;

int			ft_printf(const char *format, ...);

void		ft_putstr(char *s, t_ft_printf *data);
void		ft_putchar(char c, t_ft_printf *data);
void		ft_putnbr(int nb, t_ft_printf *data);
void		ft_putpointer(unsigned long int ptr, t_ft_printf *data);
void		ft_putnbr_unsigned(unsigned int nb, t_ft_printf *data);
void		ft_puthexa(unsigned int nb, int type, t_ft_printf *data);

#endif
