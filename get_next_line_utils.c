/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:14:37 by paulo             #+#    #+#             */
/*   Updated: 2025/01/08 13:26:51 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	insert_list(t_node **root, char *buff)
{
	t_node	*new_node;
	t_node	*current_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->str = buff;
	new_node->next = NULL;
	if (*root == NULL)
	{
		*root = new_node;
		return ;
	}
	current_node = *root;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new_node;
}

int	found_newline(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (++i);
		i++;
	}
	return (i);
}

char	*group_list(t_node **root, int len_line)
{
	t_node	*current;
	char	*line;
	int		total_chars;
	int		j;

	line = malloc(len_line + 1);
	current = *root;
	total_chars = 0;
	while (current != NULL)
	{
		if (current->str != NULL)
		{
			j = 0;
			while (current->str[j] != '\0' && current->str[j - 1] != '\n')
			{
				line[total_chars] = current->str[j];
				total_chars++;
				j++;
			}
		}
		current = current->next;
	}
	line[len_line] = '\0';
	return (line);
}

void	ft_free_mem(t_node **root)
{
	t_node	*temp;
	t_node	*current;
	int		i;
	int		j;

	current = *root;
	while (current->next != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*root = current;
	i = 0;
	while (current->str[i - 1] != '\n')
		i++;
	j = 0;
	while (current->str[i] != '\0')
	{
		current->str[j] = current->str[i];
		i++;
		j++;
	}
	current->str[j] = '\0';
}

int	create_list(t_node **root, int fd)
{
	char	*buff;
	int		bytes_read;
	int		len_line;

	(void)root;
	bytes_read = 1;
	len_line = 0;
	while (bytes_read)
	{
		buff = malloc(BUFFER_SIZE + 1);
		bytes_read = read (fd, buff, BUFFER_SIZE);
		if (!bytes_read)
			return (len_line);
		if (bytes_read <= 0)
		{
			free(buff);
			return (len_line);
		}
		buff[bytes_read] = '\0';
		insert_list(&*root, buff);
		len_line += found_newline(buff);
		if (found_newline(buff) != BUFFER_SIZE)
			return (len_line);
	}
	return (len_line);
}
