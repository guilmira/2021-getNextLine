/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guilmira <guilmira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 08:50:17 by guilmira          #+#    #+#             */
/*   Updated: 2021/06/07 10:17:00 by guilmira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*writer(char *string, char **line)
{
	size_t	i;
	char	*aux;

	i = 0;
	aux = string;
	while(string[i] != '\n' && string[i])
	{
		i++;
		aux++;
	}
	aux++;
	*line = ft_substr(string, 0, i); //maloc en linea, el definitvio hola
	//free(string); PARA MI QUE CASI SEGURO NO PEUDES HACER FREE STRING AQUI. TE CARGARAS ESE BLOQUE, Y AUX APUNTA AHI.
	// la duda es, habra que liberar string[fd] solo cuando lleguemos al final de fichero? o ni siquiera
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
		//if (signal < 0)
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
	string[fd] = writer(string[fd], line);
	if (result == 0)
		return (0);
	return (1);
}

int main(void)
{
	char *linea;
	//system ("leaks a.out");

	//FICHERO ABRIR
	char *a = "1.txt";
	int fd = open(a, O_RDONLY);

	int lineas = 3;
	int i = -1;
	int j;
	while (++i < lineas)
	{
		j = get_next_line(fd, &linea);

		//get_next_line(file, tabla);
		//printf("resultadoA: %s\n", *tabla);
		/* get_next_line(fileb, tabla);
		printf("resultadoB: %s\n", *tabla); */
		//get_next_line(generic, tabla);
		printf("resultado: %s\n", linea);
		printf("%i\n", j);
	}
	free(linea);
}
