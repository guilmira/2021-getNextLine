/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:50:17 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/07 11:07:51 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*writer(char *string, char **line)
{
	size_t	i;
	char	*aux;
	//char 	*tmp;

	i = 0;
	aux = string;
	while(string[i] != '\n' && string[i])
	{
		i++;
		aux++;
	}
	aux++;
	*line = ft_substr(string, 0, i);

/* 	tmp = ft_strdup(aux);
	free(string);
	string = tmp; //esta liena mas adleeante no sera necesaria return (tmp); */
	//free(string);
	string = aux;
	return(string);
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
			return (-1);
		}
		buffer[signal] = '\0';
		if (!string[fd])
		{
			string[fd] = ft_strdup(buffer); //ptr con memoria reservada 1
		}
		else
		{
			string[fd] = ft_strjoin_freebuffer(string[fd], buffer); //ptr con mem reservada 2 AQUI HAY QUE HACER FREE
		}
		if (ft_strchr(string[fd], '\n'))
			break;
	}
	if (signal < BUFFER_SIZE && !(ft_strchr(string[fd], '\n')))
		return (0);
	return (1);

}

int	get_next_line(int fd, char **line)
{
	static char	*string[FD_SETSIZE];
	int			result;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	result = reader(fd, string);
	if (result > -1)
		string[fd] = writer(string[fd], line);
	if (result == 0)
	{
		/* if (string[fd])
			free(string[fd]); */
		return (0);
	}
	if (result == -1)
	{
		//line[fd] = NULL;
		return (-1);
	}
	/* if (string[fd])
			free(string[fd]); */
	return (1);
}

