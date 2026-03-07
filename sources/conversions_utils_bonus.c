/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:23:28 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/07 14:24:15 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	apply_width(char **src, char fill, t_ft_printf *data)
{
	size_t	i;
	size_t	srclen;
	char	*dest;

	srclen = ft_strlen(*src);
	if (data->flags.wdt <= srclen)
		return (0);
	dest = calloc(data->flags.wdt + 1, sizeof(char));
	if (!dest)
	{
		free(*src);
		data->res = 1;
		return (1);
	}
	i = 0;
	while (i < data->flags.wdt)
		dest[i++] = fill;
	if (data->flags.left)
		ft_strlcpy(dest, *src, srclen + 1);
	else
		ft_strlcpy(dest + (data->flags.wdt - srclen), *src, srclen + 1);
	free(*src);
	*src = dest;
	return (0);
}

int	apply_precision_nb(char **src, t_ft_printf *data)
{
	char	*dest;
	size_t	size;
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(*src);
	if (data->flags.prec == -1 || data->flags.prec <= srclen)
		return (0);
	size = srclen;
	if (data->flags.prec > srclen)
		size = data->flags.prec;
	dest = calloc(size + 1, sizeof(char));
	if (!dest)
	{
		free(*src);
		data->res = 1;
		return (1);
	}
	i = 0;
	while (i < size)
		dest[i++] = '0';
	ft_strlcpy(dest, *src + (size - srclen), srclen + 1);
	free(*src);
	*src = dest;
	return (0);
}

int	apply_precision_str(char **src, t_ft_printf *data)
{
	char	*dest;

	if (data->flags.prec == -1 || data->flags.prec >= ft_strlen(*src))
		return (0);
	dest = calloc(data->flags.prec + 1, sizeof(char));
	if (!dest)
	{
		free(*src);
		data->res = 1;
		return (1);
	}
	ft_strlcpy(dest, *src, data->flags.prec + 1);
	free(*src);
	*src = dest;
	return (0);
}
