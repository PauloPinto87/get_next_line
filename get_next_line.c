/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:29:20 by paulo             #+#    #+#             */
/*   Updated: 2025/02/05 16:51:18 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_node		*root;
	static char	buff[BUFFER_SIZE + 1] = {'\0'};
	int			bytes_read;
	int			qnt_node;

	if (fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	root = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (*buff != '\0')
		{
			printf("Ha algo dentro do buff antes mesmo de nova leitura\n");
			return (NULL);
		}
		else
		{
			bytes_read = read(fd, buff, BUFFER_SIZE);
			if (bytes_read > 0)
			{
				buff[bytes_read] = '\0';
				qnt_node = insert_end(&root, buff);
				if (verify_buff(buff) >= 0)
					return (create_return_line(&root, qnt_node, buff));
			}
			else if (bytes_read == 0 && root != NULL)
			{
				printf("bytes read == 0 mas o root != NULL");
				return (create_return_line(&root, qnt_node, buff));
			}
		}
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line_return;

	fd = open("texto.txt", O_RDONLY);
	line_return = NULL;

	// while ((line_return = get_next_line(fd)) != NULL)
	// {
	// 	printf("\nreturn line:\n%s", line_return);
	// 	line_return = get_next_line(fd);
	// 	free(line_return);
	// }


	line_return = get_next_line(fd);
	printf("\nreturn line:\n%s", line_return);
	free(line_return);

	line_return = get_next_line(fd);
	printf("\nreturn line:\n%s", line_return);
	free(line_return);

	close(fd);
	return (0);
}
