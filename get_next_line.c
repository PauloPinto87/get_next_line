/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pahenri2 <pahenri2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:29:20 by paulo             #+#    #+#             */
/*   Updated: 2025/03/03 16:01:37 by pahenri2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	char			*line;
	static char		buff[BUFFER_SIZE + 1];
	int				bytes_read;
	int				newline_index;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (buff[0] = '\0', NULL);
	bytes_read = 1;
	while (1)
	{
		if (buff[0] == '\0')
		{
			bytes_read = read(fd, buff, BUFFER_SIZE);
			if (bytes_read < 0)
			{
				if (line != NULL)
					free(line);
				return (NULL);
			}
			else if (bytes_read == 0)
				break ;
			buff[bytes_read] = '\0';
		}
		newline_index = verify_newline(buff);
		line = append_line(buff, &line, newline_index);
		if (newline_index >= 0)
			break ;
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line_return;

// 	fd = open("texto.txt", O_RDONLY);

// 	//fd = 0;
// 	while (1)
// 	{

// 		line_return = get_next_line(fd);
// 		if (line_return != NULL)
// 		{
// 			printf("%s", line_return);
// 			free(line_return);
// 		}
// 		else
// 			break;
// 	}

// 	close(fd);
// 	return (0);
// }
