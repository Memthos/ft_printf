/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:22:55 by mperrine          #+#    #+#             */
/*   Updated: 2026/02/08 12:29:10 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_inset(char s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_getindex(char const *s, char const *set, int inc)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen((char *) s);
	if (inc < 0)
		i = slen - 1;
	while ((i < slen && inc == 1) || (i + 1 > 0 && inc == -1))
	{
		if (ft_inset(s[i], set) == 0)
		{
			if (inc == 1)
				return (i);
			return (i + 1);
		}
		i += inc;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_getindex(s1, set, 1);
	end = ft_getindex(s1, set, -1);
	s = (char *) malloc(((end - start) + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	i = 0;
	s[end - start] = '\0';
	while (start + i < end)
	{
		s[i] = s1[start + i];
		i++;
	}
	return (s);
}
