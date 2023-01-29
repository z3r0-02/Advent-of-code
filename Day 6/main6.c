#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char *read_input()
{
	char *buff;
	char *res;
	int op;
	int size;

	op = open("input.txt", O_RDONLY);
	size = 0;
	buff = malloc(sizeof(char));
	while (read(op, buff, 1))
		size++;
	close(op);
	op = open("input.txt", O_RDONLY);
	res = malloc(sizeof(char) * size);
	read(op, res, size);
	free(buff);
	return (res);
}

void calculate()
{
    int i;
    int lenght;
    char *str;

    i = 0;
    lenght = 0;
    str = read_input();
    while (str[i] != '\0')
    {
        if (str[i + 1] != str[i] && str[i + 2] != str[i] && str[i + 3] != str[i])
        {
            if (str[i + 2] != str[i + 1] && str[i + 3] != str[i + 1])
            {
                if(str[i + 3] != str[i + 2])
                {
                    lenght = i + 4;
                    break;
                }
            }
        }
        i++;
        lenght++;
    }
    printf("%d", lenght);
}

int main()
{
    calculate();
}