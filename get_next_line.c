/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:29:20 by paulo             #+#    #+#             */
/*   Updated: 2025/01/25 11:59:15 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1] = {'\0'};
	int			bytes_read;
	t_node		*root;
	size_t		qnt_node;
	int			qnt_char_newline;
	char		*line_return;

	qnt_node = 0;
	qnt_char_newline = 0;
	qnt_char_newline = 0;
	root = NULL;
	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && qnt_char_newline >= 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[bytes_read] = '\0';
		qnt_node = insert_end(&root, buff);
		//printf("qnt_node = %ld\n", qnt_node);
		qnt_char_newline = is_newline(buff);
		//printf("qnt_char_newline = %d\n", qnt_char_newline);
	}
	//printf("buff before end = %s, bytes_read = %d\n", buff, bytes_read);
	line_return = create_line(&root, qnt_node, qnt_char_newline + qnt_node);
	prepare_newline(&root, buff);
	return (line_return);
}

int	main(void)
{
	int		fd;
	char	*line_return;

	fd = open("texto.txt", O_RDONLY);
	line_return = NULL;
	while (1)
	{
		line_return = get_next_line(fd);
		if (!line_return)
			break;
		printf("%s", line_return);
		free(line_return);
	}
	close(fd);
	return (0);
}
