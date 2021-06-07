#include "get_next_line.h"

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
	system ("leaks a.out");
}

