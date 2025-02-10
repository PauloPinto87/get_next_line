/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:14:37 by paulo             #+#    #+#             */
/*   Updated: 2025/02/10 13:02:36 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	verify_newline(char *line_return, char *buff)
{
	int	newline_pos;

	newline_pos = 0;
	while (line_return[newline_pos] != '\0')
	{
		if (line_return[newline_pos] == '\n')
		{
			prepare_nex_call(buff);
			while (*line_return != '\n')
				line_return++;
			line_return++;
			*line_return = '\0';
			return (newline_pos);
		}
		newline_pos++;
	}
	return (-1);
}

void	prepare_nex_call(char *buff)
{
	int	start;
	int	end;

	if (!buff)
		return ;
	end = 0;
	while (buff[end] != '\n' && buff[end] != '\0')
		end++;
	start = 0;
	end++;
	if (buff[end] == '\0')
	{
		buff[0] = '\0';
		return ;
	}
	while (buff[end] != '\0' )
		buff[start++] = buff[end++];
	buff[start] = '\0';
}

char	*ft_mod_strcat(char *dst, const char *src)
{
	int		dst_len;
	int		src_len;
	int		i;
	char	*new_str;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	new_str = malloc(dst_len + src_len + 1);
	if (!new_str)
		return (free(dst), NULL);
	i = -1;
	while (i++ < dst_len)
		new_str[i] = dst[i];
	i = -1;
	while (i++ < src_len)
		new_str[i + dst_len] = src[i];
	new_str[dst_len + src_len] = '\0';
	if (dst)
		free(dst);
	return (new_str);
}
