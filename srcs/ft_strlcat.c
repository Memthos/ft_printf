/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:54:55 by mperrine          #+#    #+#             */
/*   Updated: 2026/03/17 10:04:34 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	deslen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	deslen = ft_strlen(dest);
	if (deslen + 1 > size)
		return (srclen + size);
	i = 0;
	while (i < size - deslen - 1 && src[i])
	{
		dest[deslen + i] = src[i];
		i++;
	}
	dest[deslen + i] = '\0';
	return (srclen + deslen);
}
