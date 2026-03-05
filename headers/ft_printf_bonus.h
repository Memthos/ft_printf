/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:33:17 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/05 11:19:38 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_flags
{
	size_t	left;
	size_t	sign;
	size_t	space;
	size_t	zero;
	size_t	alt;
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

typedef enum e_codes
{
	SUCCESS,
	ERROR,
	CONVERSION,
}	t_codes;

int			ft_printf(const char *format, ...);

void		ft_putstr(char *s, t_ft_printf *data);
void		ft_putchar(char c, t_ft_printf *data);
void		ft_putnbr(int nb, t_ft_printf *data);
void		ft_putpointer(unsigned long int ptr, t_ft_printf *data);
void		ft_putnbr_unsigned(unsigned int nb, t_ft_printf *data);
void		ft_puthexa(unsigned int nb, int type, t_ft_printf *data);

#endif
