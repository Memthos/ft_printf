/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:49:15 by mperrine          #+#    #+#             */
/*   Updated: 2026/02/08 12:29:10 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	int		o;

	i = 0;
	o = 1;
	if (dest > src)
	{
		i = n - 1;
		o = -1;
	}
	while (!(src == NULL && dest == NULL)
		&& ((i < n && o == 1) || (i + 1 > 0 && o == -1)))
	{
		((char *)dest)[i] = ((char *)src)[i];
		i += o;
	}
	return (dest);
}
