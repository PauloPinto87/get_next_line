/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:46:14 by paulo             #+#    #+#             */
/*   Updated: 2025/02/05 12:21:04 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
t_node	*create_node(char *buff);
int		verify_buff(char *str);
int		insert_end(t_node **root, char *buff);
char	*create_return_line(t_node **root, int qnt_node, char *buff);
void	prepare_next_call(t_node **root, char *buff);

#endif
