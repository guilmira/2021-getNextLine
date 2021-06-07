#include "get_next_line.h"

int	main(void)
{
	char	*linea;
	//system ("leaks a.out");
	//FICHERO ABRIR
	//char *a = "1.txt";
	//char *a = "41_no_nl";
	char *a = "big_line_no_nl";

	int fd = open(a, O_RDONLY);
/* 	while (++i < lineas)
	{
		j = get_next_line(fd, &linea);
		printf("resultado: %s\n", linea);
		printf("%i\n", j);
		free(linea);
	} */
	get_next_line(fd, &linea);
	//get_next_line(fd, &linea);
	//printf("resultado: %s\n", linea);
	//get_next_line(fd, &linea);
	//free(linea);
	//system ("leaks a.out");
}
