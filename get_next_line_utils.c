/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:14:37 by paulo             #+#    #+#             */
/*   Updated: 2025/02/16 13:54:02 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	verify_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strljoin(char *line, char *buff, size_t len)
{
	char	*new_line;
	size_t	line_len;

	line_len = 0;
	if (line)
		line_len = ft_strlen(line);
	new_line = malloc(line_len + len + 1);
	if (!new_line)
		return (NULL);
	if (line)
	{
		ft_strlcpy(new_line, line, line_len + 1);
		free(line);
	}
	ft_strlcpy(new_line + line_len, buff, len + 1);
	return (new_line);
}

char	*append_line(char *buff, char **line, int newline_index)
{
	char	*new_str;

	if (newline_index >= 0)
	{
		new_str = ft_strljoin(*line, buff, newline_index + 1);
		ft_strlcpy(buff, buff + newline_index + 1, BUFFER_SIZE);
	}
	else
	{
		new_str = ft_strljoin(*line, buff, ft_strlen(buff));
		buff[0] = '\0';
	}
	return (new_str);
}
