/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:29:20 by paulo             #+#    #+#             */
/*   Updated: 2025/02/10 13:03:40 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line_return;
	int				bytes_read;
	static char		buff[BUFFER_SIZE + 1] = {'\0'};

	if (fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_return = malloc(1);
	if (!line_return)
		return (NULL);
	line_return[0] = '\0';
	bytes_read = 1;
	while (bytes_read > 0)
	{
		line_return = ft_mod_strcat(line_return, buff);
		if (verify_newline(line_return, buff) >= 0)
			return (line_return);
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = '\0';
	}
	if (bytes_read <= 0 && line_return[0] == '\0')
		return (free(line_return), NULL);
	return (line_return);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line_return;

// 	fd = open("texto.txt", O_RDONLY);

// 	while (line_return != NULL)
// 	{
// 		line_return = get_next_line(fd);
// 		if (line_return != NULL)
// 		{
// 			printf("%s", line_return);
// 			free(line_return);
// 		}

// 	}

// 	// line_return = get_next_line(fd);
// 	// if (line_return != NULL)
// 	// {
// 	// 	printf("%s", line_return);
// 	// 	free(line_return);
// 	// }
// 	// line_return = get_next_line(fd);
// 	// if (line_return != NULL)
// 	// {
// 	// 	printf("%s", line_return);
// 	// 	free(line_return);
// 	// }
// 	// line_return = get_next_line(fd);
// 	// if (line_return != NULL)
// 	// {
// 	// 	printf("%s", line_return);
// 	// 	free(line_return);
// 	// }

// 	close(fd);
// 	return (0);
// }