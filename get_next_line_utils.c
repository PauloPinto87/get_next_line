/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:14:37 by paulo             #+#    #+#             */
/*   Updated: 2025/02/05 16:41:40 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*create_node(char *buff)
{
	t_node	*new_node;
	char	*new_str;
	size_t	i;
	size_t	j;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	i = 0;
	while (buff[i] != '\0')
		i++;
	new_str = malloc(i + 1);
	if (!new_str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_str[j] = buff[j];
		j++;
	}
	new_str[j] = '\0';
	new_node->str = new_str;
	return (new_node);	
}


int	verify_buff(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{	
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	insert_end(t_node **root, char *buff)
{
	t_node	*new_node;
	t_node	*current_node;
	int		qnt_node;

	new_node = create_node(buff);
	if (!new_node)
		return (-1);
	new_node->next = NULL;
	if (*root == NULL)
	{
		*root = new_node;
		return (1);
	}
	current_node = *root;
	qnt_node = 1;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
		qnt_node++;
	}
	current_node->next = new_node;
	return (++qnt_node);
}

void	prepare_next_call(t_node **root, char *buff)
{
	t_node	*current_node;
	t_node	*aux;
	int		len_str;

	if (!root || !*root)
		return ;
	current_node = *root;
	while (current_node != NULL)
	{
		aux = current_node->next;
		free(current_node->str);
		free(current_node);
		current_node = aux;
	}
	*root = NULL;
	len_str = 0;
	while (buff[len_str])
		len_str++;
	if ((len_str - 1) != verify_buff(buff) && verify_buff(buff) >= 0)
		printf("Ainda existe conteudo no buff\n");
	else
		*buff = '\0';
	printf("buff content = %s\n", buff);
	printf("verify = %d and len_str = %d\n", verify_buff(buff), len_str - 1);
}

char	*create_return_line(t_node **root, int qnt_node, char *buff)
{
	t_node	*current_node;
	char	*line_return;
	int		i;
	int		j;

	line_return = malloc(qnt_node * BUFFER_SIZE + 1);
	if (!line_return)
		return (NULL);
	i = 0;
	current_node = *root;
	while (current_node != NULL)
	{
		j = 0;
		while(current_node->str[j] != '\0' && current_node->str[j] != '\n')
			line_return[i++] = current_node->str[j++];
		if (current_node->str[j])
			line_return[i++] = '\n';
		current_node = current_node->next;
	}
	line_return[i] = '\0';
	prepare_next_call(root, buff);
	return (line_return);
}
