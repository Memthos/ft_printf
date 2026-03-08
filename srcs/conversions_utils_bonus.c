/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 13:23:28 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/08 22:49:49 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

static void	apply_width(char *dest, char *src, int lens[2], t_ft_printf *data)
{
	if (data->flags.left)
	{
		ft_strncpy(dest, src, lens[1]);
		ft_memset(dest + lens[1], ' ', data->flags.wdt - lens[1]);
	}
	else
	{
		if (data->flags.zero && data->flags.prec == -1)
		{
			ft_strncpy(dest, src, lens[0]);
			ft_memset(dest + lens[0], '0', data->flags.wdt - lens[1]);
		}
		else
		{
			ft_memset(dest, ' ', data->flags.wdt - lens[1]);
			ft_strlcat(dest, src, data->flags.wdt - lens[1] + 1);
		}
		ft_strlcat(dest, src + lens[0], data->flags.wdt + 1);
	}
}

int	width_base(char **src, int prefix, int srclen, t_ft_printf *data)
{
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
	apply_width(dest, *src, (int [2]){prefix, srclen}, data);
	free(*src);
	*src = dest;
	return (0);
}

int	apply_precision_nb(char **src, int prefix, t_ft_printf *data)
{
	char	*dest;
	int		srclen;

	srclen = (int)ft_strlen(*src);
	if (data->flags.prec == -1 || data->flags.prec <= srclen - prefix)
		return (0);
	dest = calloc(data->flags.prec + prefix + 1, sizeof(char));
	if (!dest)
	{
		free(*src);
		data->res = 1;
		return (1);
	}
	ft_strncpy(dest, *src, prefix);
	ft_memset(dest + prefix, '0', data->flags.prec - srclen + prefix);
	ft_strlcat(dest, *src + prefix, data->flags.prec + prefix + 1);
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
