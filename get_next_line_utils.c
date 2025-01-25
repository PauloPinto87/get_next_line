/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:14:37 by paulo             #+#    #+#             */
/*   Updated: 2025/01/25 11:19:08 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *buff)
{
	size_t	len;
	size_t	i;
	char	*dest;

	len = 0;
	while (buff[len] != '\0')
		len++;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (buff[i] != '\0')
	{
		dest[i] = buff[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	insert_end(t_node **root, char *buff)
{
	t_node	*new_node;
	t_node	*current_node;
	size_t	i;


	i = 1;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->next = NULL;
	new_node->str = ft_strdup(buff);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (0);
	}
	if (*root == NULL)
	{
		*root = new_node;
		//printf("current_node->str = %s", (*root)->str);
		return (i);
	}
	current_node = *root;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
		i++;
	}
	current_node->next = new_node;

	return (++i);
}

char	*create_line(t_node **root, size_t qnt_node, size_t qnt_char_newline)
{
	t_node	*current_node;
	size_t		i;
	size_t		j;
	char	*line_return;

	//printf("qnt_node = %ld and qnt_char_newline = %ld\n", qnt_node, qnt_char_newline);
	line_return = malloc(((qnt_node - 1) * BUFFER_SIZE) + qnt_char_newline + 1);
	if (!line_return)
		return (NULL);
	i = 0;
	current_node = *root;
	while (current_node != NULL)
	{
		j = 0;
		while (current_node->str[j] != '\0' && i < qnt_char_newline)
		{
			//printf("i = %dd - j = %d\n", i, j);
			line_return[i] = current_node->str[j];
			j++;
			i++;
		}
		current_node = current_node->next;
	}
	line_return[i] = '\0';
	//printf("Return line is %s\n", line_return);
	return (line_return);
}

void	prepare_newline(t_node **root, char *buff)
{
	t_node	*current_node;
	t_node	*aux;
	int		i;
	int		j;

	current_node = *root;
	while (current_node != NULL)
	{
		aux = current_node->next;
		free(current_node->str);
		free(current_node);
		current_node = aux;
	}
	*root = NULL;
	i = is_newline(buff) + 1;
	j = 0;
	while (buff[i] != '\0')
	{
		buff[j] = buff[i];
		i++;
		j++;
	}
	buff[j] = '\0';
	//printf("is_newline in prepare_newline %d\n", i);
	
}
