/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:29:20 by paulo             #+#    #+#             */
/*   Updated: 2025/02/14 00:02:56 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		buff[BUFFER_SIZE + 1] = {'\0'};
	int				bytes_read;
	int				newline_index;


	line = NULL;
	if (fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE <= 0)
	{
		buff[0] = '\0';
		//printf("DEU ERRO O BUFF = %s e o line = %s\n", buff, line);
		return (NULL);
	}
	bytes_read = 1;
	while (1)
	{
		if (buff[0] == '\0')
		{
			bytes_read = read(fd, buff, BUFFER_SIZE);
			if (bytes_read <= 0)
			{
				if (bytes_read == 0)
					break;

				break;
			}
			buff[bytes_read] = '\0';
		}
		newline_index = verify_newline(buff);
		if (newline_index >= 0)
		{
			line = ft_strljoin(line, buff, newline_index + 1);
			ft_strlcpy(buff, buff + newline_index + 1, BUFFER_SIZE);
			break;
		}
		line = ft_strljoin(line, buff, ft_strlen(buff));
		buff[0] = '\0';
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line_return;
// 	int		i;

// 	fd = open("texto.txt", O_RDONLY);

// 	i = 1;
// 	while (1)
// 	{
// 		if (i == 3)
// 		{
// 			printf(" O FD ESTA EM %d E VAI PARA ", fd);
// 			fd = -1;
// 			printf("%d\n", fd);
// 		}
// 		if (i == 4)
// 		{
// 			close(fd);
// 			fd = open("texto.txt", O_RDONLY);
// 			printf("COLOQUEI O FD EM %d\n", fd);
// 		}
// 		line_return = get_next_line(fd);
// 		if (line_return != NULL)
// 		{
// 			printf("%s", line_return);
// 			free(line_return);
// 		}
// 		if (i == 4)
// 			break;
// 		i++;
// 	}

// 	// line_return = get_next_line(fd);
// 	// if (line_return != NULL)
// 	// {
// 	// 	printf("RETURNED = %s", line_return);
// 	// 	free(line_return);
// 	// }

// 	// line_return = get_next_line(fd);
// 	// if (line_return != NULL)
// 	// {
// 	// 	printf("RETURNED = %s", line_return);
// 	// 	free(line_return);
// 	// }

// 	// line_return = get_next_line(fd);
// 	// if (line_return != NULL)
// 	// {
// 	// 	printf("RETURNED = %s", line_return);
// 	// 	free(line_return);
// 	// }

// 	// line_return = get_next_line(fd);
// 	// if (line_return != NULL)
// 	// {
// 	// 	printf("RETURNED = %s", line_return);
// 	// 	free(line_return);
// 	// }


// 	// line_return = get_next_line(fd);
// 	// if (line_return != NULL)
// 	// {
// 	// 	printf("RETURNED = %s", line_return);
// 	// 	free(line_return);
// 	// }

// 	close(fd);
// 	return (0);
// }