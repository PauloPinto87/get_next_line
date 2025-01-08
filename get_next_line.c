/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:29:20 by paulo             #+#    #+#             */
/*   Updated: 2025/01/08 13:30:12 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_node	*root_list = NULL;
	char			*buff;
	int				len_line;

	if (fd < 0 || read(fd, &buff, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len_line = create_list(&root_list, fd);
	printf("%s", group_list(&root_list, len_line));
	ft_free_mem(&root_list);
	return ("Fim do get next line");
}

int	main(void)
{
	int	fd;

	fd = open("texto.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
