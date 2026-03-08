/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:23:28 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/08 01:02:21 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	apply_width(char **src, char fill, int srclen, t_ft_printf *data)
{
	int		i;
	char	*dest;

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
		ft_strncpy(dest, *src, srclen);
	else
		ft_strncpy(dest + (data->flags.wdt - srclen), *src, srclen);
	free(*src);
	*src = dest;
	return (0);
}

int	apply_precision_nb(char **src, t_ft_printf *data)
{
	char	*dest;
	int		size;
	int		srclen;
	int		i;

	srclen = (int)ft_strlen(*src);
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
	ft_strncpy(dest, *src + (size - srclen), srclen);
	free(*src);
	*src = dest;
	return (0);
}

int	apply_precision_str(char **src, t_ft_printf *data)
{
	char	*dest;

	if (data->flags.prec == -1 || data->flags.prec >= (int)ft_strlen(*src))
		return (0);
	dest = calloc(data->flags.prec + 1, sizeof(char));
	if (!dest)
	{
		free(*src);
		data->res = 1;
		return (1);
	}
	ft_strncpy(dest, *src, data->flags.prec);
	free(*src);
	*src = dest;
	return (0);
}
