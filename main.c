#include "get_next_line.h"
#include <stdio.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*linea;
	//FICHERO ABRIR
	char *a = "41_no_nl";


	int fd = open(a, O_RDONLY);
/* 	while (++i < lineas)
	{
		j = get_next_line(fd, &linea);
		printf("resultado: %s\n", linea);
		printf("%i\n", j);
		free(linea);
	} */
	get_next_line(fd, &linea);
	free(linea);
	//free(linea);

	printf("resultado: %s\n", linea);
	//get_next_line(fd, &linea);
	//free(linea);
	//system ("leaks a.out");
}

//esto con char *a = "41_no_nl"; impide los root leaks, que se generan al crear nuevo espacio en linea
//cada vez
/* 	get_next_line(fd, &linea);
	free(linea);
	get_next_line(fd, &linea);
	free(linea);
	get_next_line(fd, &linea); */
