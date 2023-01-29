#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

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

void calculate() //rock = 1, paper = 2, scissors = 3 || win = 6, loss = 0, draw = 3
{
    int i;
    int sum;
    char *str = read_input();

    i = 0;
    sum = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'A')
        {
            i++;
            if (str[i] == ' ')
                i++;
            if (str[i] == 'Y' || str[i] == 'X' || str[i] == 'Z')
            {
                if (str[i] == 'X')
                    sum += 3;
                else if (str[i] == 'Y')
                    sum += 4;
                else
                    sum += 8;
            }
        }
        if (str[i] == 'B')
        {
            i++;
            if (str[i] == ' ')
                i++;
            if (str[i] == 'Y' || str[i] == 'X' || str[i] == 'Z')
            {
                if (str[i] == 'X')
                    sum += 1;
                else if (str[i] == 'Y')
                    sum += 5;
                else
                    sum += 9;
            }
        }
        if (str[i] == 'C')
        {
            i++;
            if (str[i] == ' ')
                i++;
            if (str[i] == 'Y' || str[i] == 'X' || str[i] == 'Z')
            {
                if (str[i] == 'X')
                    sum += 2;
                else if (str[i] == 'Y')
                    sum += 6;
                else
                    sum += 7;
            }
        }
        i++;
    }
    printf("%d", sum);
}

int main()
{
    calculate();
}