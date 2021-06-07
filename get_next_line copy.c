/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 09:11:36 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/07 09:27:21 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*writer(char *string, char **line)
{
	char		*aux;

	size_t z = 0;
	aux = string;
	while (string[z] && string[z] != '\n')
	{
		z++;
		aux++;
	}
	*line = ft_substr(string, 0, z);
	//free(string);
	string = ++aux;
	return (string);
}

int	reader(int fd, char **string)
{
	int		signal;
	char	*buffer;

	signal = 1;
	while (signal != 0)
	{
		buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
		if (!buffer)
			return (-1);
		signal = read(fd, buffer, BUFFER_SIZE);
		if (signal < 0)
		{
			free(buffer);
			free(string[fd]);
			return (-1);
		}
		buffer[signal] = '\0';
		string[fd] = ft_strjoin_freebuffer(string[fd], buffer);
		if (ft_strchr(string[fd], '\n'))
			break;
	}
	if (signal == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char		*string[FD_SETSIZE];
	int				f;
	if (!line && fd <= -1 && BUFFER_SIZE <= 0)
		return (-1);
	else
	{
		f = reader(fd, string);
		if (f == -1)
			return (-1);
		if (!string[fd])
			return (-1);
		if (f == 0)
		{
			string[fd] = writer(string[fd], line);
			/* if (g == -1)
				return (-1); */
			return (0);
		}
		else
		{
			string[fd] = writer(string[fd], line);
			/* if (g == -1)
				return (-1); */
		}
		return (1);
	}
}

int main(void)
{
	char	*tabla;

	char *a = "a.txt";
	int file = open(a, O_RDONLY);
	if (file == -1)
		return (-1);
	char *ab = "file.txt";
	int fileb = open(ab, O_RDONLY);
	if (fileb == -1)
		return (-1);
	//system ("leaks a.out");
	char *gen = "1.txt";
	int generic = open(gen, O_RDONLY);

	int n = 3;
	int i = -1;
	int j;
	while (++i < n)
	{
		j = get_next_line(generic, &tabla);

		//get_next_line(file, tabla);
		//printf("resultadoA: %s\n", *tabla);
		/* get_next_line(fileb, tabla);
		printf("resultadoB: %s\n", *tabla); */
		//get_next_line(generic, tabla);
		printf("resultado: %s\n", tabla);
		printf("%i\n", j);
	}
	free(tabla);

	file = close(file);
	if (file == -1)
		return (-1);

	fileb = close(file);
	if (fileb == -1)
		return (-1);
		//system ("leaks a.out");
}
