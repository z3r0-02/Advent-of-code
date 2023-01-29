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
    char *str = read_input();
    int i = 0;
	int num = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int count;

	count = 0;
	while (str[i] != '\0')
    {
		num = atoi(&str[i]);
		while (str[i] != '-' && str[i] != '\0')
			i++;
		i++;
		num2 = atoi(&str[i]);
		while (str[i] != ',' && str[i] != '\0')
			i++;
		i++;
		num3 = atoi(&str[i]);
		while (str[i] != '-' && str[i] != '\0')
			i++;
		i++;
		num4 = atoi(&str[i]);
		if (num >= num3 && num2 <= num4 || num <= num3 && num2 >= num4)
			count++;
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		i++;
	}
	printf("%d\n", count);
}

int main()
{
	calculate();
}