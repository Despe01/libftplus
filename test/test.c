#include "../libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
	char *ligne;
	int fd;
	int status;
	char buffer[11];
/*
	fd = open("file4", O_RDONLY);
	status = 1;
	while (status > 0)
	{
		status = read(fd, buffer, 10);
		buffer[10] = '\0';
		printf("%d, %s\n", status, buffer);
	}
}
*/
/*
	status = get_next_line(42, &ligne);
	if (status == 1) {
		printf("get_next_line(fd, &ligne) : 1 : Une ligne a été lue\n");
		printf("ligne = %s\n\n", ligne);
	}
	else if (status == 0) {
		printf("get_next_line(fd, &ligne) : 0 : La fin de fichier a été atteinte\n");
		return 0;
	}
	else if (status == -1) {
		printf("get_next_line(fd, &ligne) : -1 : Une erreur est survenue\n");
		return 0;
	}
	else {
		printf("get_next_line(fd, &ligne) return %d\n\n", status);
		return 0;
	}
*/


	if (argc < 2) {
		printf("chemin du fichier en parametre stp\n");
		return 0;
	}

	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		status = get_next_line(fd, &ligne);
		if (status == 1) {
			printf("get_next_line(fd, &ligne) : 1 : Une ligne a été lue\n");
			printf("ligne = %s\n\n", ligne);
		}
		else if (status == 0) {
			printf("get_next_line(fd, &ligne) : 0 : La fin de fichier a été atteinte\n");
			printf("ligne = %s\n\n", ligne);
			return 0;
		}
		else if (status == -1) {
			printf("get_next_line(fd, &ligne) : -1 : Une erreur est survenue\n");
			return 0;
		}
		else {
			printf("get_next_line(fd, &ligne) return %d\n\n", status);
			return 0;
		}
	}
	return 0;
}
