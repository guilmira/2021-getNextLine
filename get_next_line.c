/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:50:17 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/08 09:52:51 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* The use of ft_substring to allocate memory for line means everytime
 * we call the function GNL line is reserved a new space in memory,
 * therfore is adviced to free line after each call. */
char	*writer(char *string, char **line)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = string;
	while (string[i] != '\n' && string[i])
	{
		tmp++;
		i++;
	}
	*line = ft_substr(string, 0, i);
	if (string[i] == '\n')
	{
		if (string[i + 1])
			tmp = ft_strdup(++tmp);
		else
			tmp = NULL;
	}
	else
		tmp = NULL;
	free(string);
	return (tmp);
}

int	reader(int fd, char **string)
{
	char	buffer[BUFFER_SIZE + 1];
	int		signal;

	signal = BUFFER_SIZE;
	while (signal == BUFFER_SIZE)
	{
		signal = read(fd, buffer, BUFFER_SIZE);
		if (signal < 0)
		{
			if (string[fd])
				free (string[fd]);
			return (-1);
		}
		buffer[signal] = '\0';
		if (!string[fd])
			string[fd] = ft_strdup(buffer);
		else
			string[fd] = ft_strjoin_free_dup(string[fd], buffer);
		if (ft_strchr(string[fd], '\n'))
			break ;
	}
	if (signal < BUFFER_SIZE && !(ft_strchr(string[fd], '\n')))
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*string[FD_SETSIZE];
	int			result;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd > FD_SETSIZE)
		return (-1);
	result = reader(fd, string);
	if (result > -1)
		string[fd] = writer(string[fd], line);
	if (result == 0)
	{
		if (string[fd])
			free(string[fd]);
		return (0);
	}
	if (result == -1)
		return (-1);
	return (1);
}
