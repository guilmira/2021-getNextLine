/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:12:24 by guilmira          #+#    #+#             */
/*   Updated: 2021/09/22 12:27:50 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 100

int		get_next_line(int fd, char **line);
char	*ft_strjoin_free_dup(char *s1, char *s2);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnl_strdup(const char *s1);

#endif
