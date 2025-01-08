/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:29:20 by paulo             #+#    #+#             */
/*   Updated: 2025/01/08 16:43:01 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_node	*root_list = NULL;
	char			*buff;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &buff, 0) > 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			free(buff);
		buff[bytes_read] = '\0';
		insert_list(&root_list, buff);
		if (search_newline(&root_list, buff))
		{
			list_free(&root_list);
			return (search_newline(&root_list, buff));
		}
	}
	return ("End of get\n");
}

int	main(void)
{
	int	fd;

	fd = open("texto.txt", O_RDONLY);
	printf("RETURN OF GET_NEXT_LINE:\n%s", get_next_line(fd));
	return (0);
}
