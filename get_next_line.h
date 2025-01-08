/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paulo <paulo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:46:14 by paulo             #+#    #+#             */
/*   Updated: 2025/01/08 13:24:28 by paulo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
int		create_list(t_node **root, int fd);
int		found_newline(char *buff);
char	*group_list(t_node **root, int len_line);
void	ft_free_mem(t_node **root);

#endif
