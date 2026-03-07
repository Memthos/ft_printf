/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:04:35 by mperrine          #+#    #+#             */
/*   Updated: 2025/12/03 12:39:01 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	free_memory(char **str)
{
	if (*str)
		free(*str);
	*str = NULL;
}

int	get_line(char **str, char **buffer, const int break_pos)
{
	int		i;

	*str = malloc(sizeof(char) * (break_pos + 1));
	if (!*str)
		return (0);
	i = 0;
	while (i < break_pos)
	{
		(*str)[i] = (*buffer)[i];
		i++;
	}
	(*str)[i] = '\0';
	if (break_pos == (int) ft_strlen(*buffer))
	{
		free_memory(buffer);
		return (1);
	}
	if (!clean_buffer(buffer, *str))
	{
		free_memory(str);
		return (0);
	}
	return (1);
}

int	read_more(const int fd, char **buffer, int *read_res)
{
	char	*read_str;

	read_str = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!read_str)
	{
		free_memory(buffer);
		return (0);
	}
	*read_res = (int) read(fd, read_str, BUFFER_SIZE);
	if (*read_res < 1)
	{
		free(read_str);
		if (*read_res == 0 && (*buffer)[0] != '\0')
			return (1);
		free_memory(buffer);
		return (0);
	}
	if (!buffer_update(buffer, &read_str, *read_res))
	{
		free_memory(buffer);
		free_memory(&read_str);
		return (0);
	}
	return (1);
}

int	init_buffer(char **buffer)
{
	if (!*buffer)
	{
		*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!*buffer)
		{
			*buffer = NULL;
			return (0);
		}
		(*buffer)[0] = '\0';
		return (1);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*str;
	int			break_pos;
	int			read_res;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	if (!init_buffer(&buffer))
		return (NULL);
	while (1)
	{
		if (!read_more(fd, &buffer, &read_res))
			return (NULL);
		if (check_linebreak(buffer, &break_pos, read_res))
		{
			if (!get_line(&str, &buffer, break_pos))
			{
				free_memory(&buffer);
				return (NULL);
			}
			break ;
		}
	}
	return (str);
}
