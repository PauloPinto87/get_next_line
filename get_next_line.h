/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:46:14 by paulo             #+#    #+#             */
/*   Updated: 2025/01/25 09:18:18 by paulo            ###   ########.fr       */
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
int		is_newline(char *buff);
size_t	insert_end(t_node **root, char *buff);
char	*ft_strdup(const char *buff);
char	*create_line(t_node **root, size_t qnt_node, size_t qnt_char_newline);
void	prepare_newline(t_node **root, char *buff);

#endif
