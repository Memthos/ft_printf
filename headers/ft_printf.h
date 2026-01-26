/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 23:33:17 by mperrine          #+#    #+#             */
/*   Updated: 2025/11/03 10:24:36 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_parse_specifiers(const char c, va_list args, int *size, int *i);
int		ft_putnbr_unsigned(unsigned int nb, int *size);
int		ft_puthexa(unsigned int nb, const char *base, int *size);
int		ft_putpointer(unsigned long int ptr, int *size);
int		ft_putpointer_address(unsigned long int ptr, int *size);
int		ft_putnbr(int n, int *size);
int		ft_putstr(char *s, int *size);
int		ft_putchar(char c, int *size);

#endif
