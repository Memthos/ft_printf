/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:21:42 by mperrine          #+#    #+#             */
/*   Updated: 2026/02/08 12:29:10 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nbrsubs(char const *s, char c)
{
	int	i;
	int	res;
	int	b;

	i = 0;
	b = 1;
	res = 0;
	while (s[i])
	{
		if (s[i] == c)
			b = 1;
		else if (s[i] != c && b == 1)
		{
			b = 0;
			res++;
		}
		i++;
	}
	return (res);
}

static int	ft_sizesubs(char const *s, char c, int nbsubs)
{
	int	i;
	int	count;
	int	size;

	i = 0;
	count = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c)
			size++;
		if ((s[i] == c || s[i + 1] == '\0') && size > 0)
		{
			if (nbsubs <= count)
			{
				return (size);
			}
			size = 0;
			count++;
		}
		i++;
	}
	return (0);
}

static void	ft_free(char	**subs, int i)
{
	while (i >= 0)
	{
		free(subs[i]);
		i--;
	}
	free(subs);
}

static void	ft_fillsubs(char *subs, char const *s, char c, int nbsubs)
{
	int	i;
	int	j;
	int	count;
	int	b;

	i = 0;
	j = 0;
	count = 0;
	b = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (count == nbsubs)
				subs[j++] = s[i];
			b = 1;
		}
		if (s[i] == c && b == 1)
		{
			b = 0;
			count++;
		}
		i++;
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**substrings;
	int		i;
	int		nbsubs;

	if (s == NULL || s[0] == '\0')
		return (NULL);
	nbsubs = ft_nbrsubs(s, c);
	substrings = (char **) malloc((nbsubs + 1) * sizeof(char *));
	if (substrings == NULL)
		return (NULL);
	substrings[nbsubs] = NULL;
	i = 0;
	while (i < nbsubs)
	{
		substrings[i] = malloc((ft_sizesubs(s, c, i) + 1) * sizeof(char));
		if (substrings[i] == NULL)
		{
			ft_free(substrings, i - 1);
			return (NULL);
		}
		substrings[i][ft_sizesubs(s, c, i)] = '\0';
		ft_fillsubs(substrings[i], s, c, i);
		i++;
	}
	return (substrings);
}
