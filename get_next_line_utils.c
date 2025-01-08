/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:14:37 by paulo             #+#    #+#             */
/*   Updated: 2025/01/08 16:47:44 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	insert_list(t_node **root_list, char *buff)
{
	t_node	*new_node;
	t_node	*current_node;

	new_node = malloc(sizeof(t_node));
	new_node->str = buff;
	new_node->next = NULL; 
	if (*root_list == NULL)
	{		
		*root_list = new_node;
		return ;
	}
	current_node = *root_list;
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new_node;
}

char	*get_line(t_node	**root_list, int len_line)
{
	t_node *current_node;
	char	*line;
	int		i;

	if (*root_list == NULL)
		return (NULL);
	current_node = *root_list;
	while(current_node != NULL)
	{
		i = 0;
		while (current_node->str[i] != '\0')
		{
			if (current_node->str[i] == '\n')
				return (line);
			i++;
		}
		current_node = current_node->next;
	}
	return (NULL)
}

char	*search_newline(t_node **root_list, char *buff)
{
	static int	len_line = 0;
	int			aux;
	int			i;
	
	if (!buff)
		return (0);
	i = 0;
	while (buff[i] != '\0')
	{
		len_line++;
		if (buff[i] == '\n')
		{
			aux = len_line;
			len_line = 0;
			return (take_line(&root_list, aux));
		}
		i++;
	}
	return (NULL);
}

void list_free(t_node **root_list)
{
	t_node	*current_node;
	t_node	*aux;
	
	if (*root_list == NULL)
		return ;
	current_node = *root_list;
	while (current_node != NULL)
	{
		aux = current_node->next;
		free(current_node->str);
		free(current_node);
		current_node = aux;
	}
}