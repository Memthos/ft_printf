/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:33:17 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/07 14:26:15 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "../libs/libft_tools/includes/libft.h"

typedef struct s_flags
{
	char	conv;
	int		left;
	int		sign;
	int		space;
	int		zero;
	int		alt;
	int		wdt;
	int		prec;
}			t_flags;

typedef struct s_ft_printf
{
	va_list	*args;
	size_t	printed;
	int		res;
	t_flags	flags;
}			t_ft_printf;

int		ft_printf(const char *format, ...);

void	set_nb_prefix(char *s, long *nb, t_ft_printf *data);
size_t	get_hex_size(size_t nb);
size_t	get_dec_size(long nb);
void	set_hex_value(char *s, size_t nb, size_t cur, t_ft_printf *data);
void	set_dec_value(char *s, long nb, size_t cur, t_ft_printf *data);

void	char_arg(char c, t_ft_printf *data);
void	str_arg(char *str, t_ft_printf *data);
void	pointer_arg(size_t ptr, t_ft_printf *data);
void	nb_arg(long nb, t_ft_printf *data);
void	hex_arg(size_t nb, t_ft_printf *data);

void	ft_putchar(char c, t_ft_printf *data);
void	ft_putstr(char *s, t_ft_printf *data);
int		get_number(const char *format, int *i);

int		apply_width(char **src, char fill, t_ft_printf *data);
int		apply_precision_nb(char **src, t_ft_printf *data);
int		apply_precision_str(char **src, t_ft_printf *data);

int		conversion_check(t_ft_printf *data);
int		is_flag(char c);
int		is_length(char c);
int		is_conversion(char c);

#endif
