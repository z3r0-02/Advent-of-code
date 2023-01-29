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

/*int ft_double(char c, char *str)
{
	int i;
	int len;
   	len = strlen(str);
	while (i != len)
	{
		if (str[i] == c)
			return (0);
        i++;
	}
	return (1);
}
*/
void calculate()
{
    int i;
    int j;
    int k;
    int lenght;
    char *str;

    i = 0;
    lenght = 0;
    str = read_input();
    while (str[i] != '\0')
    {
        if (str[i + 1] != str[i] && str[i + 2] != str[i] && str[i + 3] != str[i] && str[i + 4] != str[i] && str[i + 5] != str[i] && str[i + 6] != str[i] && str[i + 7] != str[i] && str[i + 8] != str[i] && str[i + 9] != str[i] && str[i + 10] != str[i] && str[i + 11] != str[i] && str[i + 12] != str[i] && str[i + 13] != str[i])
        {
            if (str[i + 2] != str[i + 1] && str[i + 3] != str[i + 1] && str[i + 4] != str[i + 1] && str[i + 5] != str[i + 1] && str[i + 6] != str[i + 1] && str[i + 7] != str[i + 1] && str[i + 8] != str[i + 1] && str[i + 9] != str[i + 1] && str[i + 10] != str[i + 1] && str[i + 11] != str[i + 1] && str[i + 12] != str[i + 1] && str[i + 13] != str[i + 1])
            {
                if (str[i + 3] != str[i + 2] && str[i + 4] != str[i + 2] && str[i + 5] != str[i + 2] && str[i + 6] != str[i + 2] && str[i + 7] != str[i + 2] && str[i + 8] != str[i + 2] && str[i + 9] != str[i + 2] && str[i + 10] != str[i + 2] && str[i + 11] != str[i + 2] && str[i + 12] != str[i + 2] && str[i + 13] != str[i + 2])
                {
                    if (str[i + 4] != str[i + 3] && str[i + 5] != str[i + 3] && str[i + 6] != str[i + 3] && str[i + 7] != str[i + 3] && str[i + 8] != str[i + 3] && str[i + 9] != str[i + 3] && str[i + 10] != str[i + 3] && str[i + 11] != str[i + 3] && str[i + 12] != str[i + 3] && str[i + 13] != str[i + 3])
                    {
                        if (str[i + 5] != str[i + 4] && str[i + 6] != str[i + 4] && str[i + 7] != str[i + 4] && str[i + 8] != str[i + 4] && str[i + 9] != str[i + 4] && str[i + 10] != str[i + 4] && str[i + 11] != str[i + 4] && str[i + 12] != str[i + 4] && str[i + 13] != str[i + 4])
                        {
                            if (str[i + 6] != str[i + 5] && str[i + 7] != str[i + 5] && str[i + 8] != str[i + 5] && str[i + 9] != str[i + 5] && str[i + 10] != str[i + 5] && str[i + 11] != str[i + 5] && str[i + 12] != str[i + 5] && str[i + 13] != str[i + 5])
                            {
                                if (str[i + 7] != str[i + 6] && str[i + 8] != str[i + 6] && str[i + 9] != str[i + 6] && str[i + 10] != str[i + 6] && str[i + 11] != str[i + 6] && str[i + 12] != str[i + 6] && str[i + 13] != str[i + 6])
                                {
                                    if (str[i + 8] != str[i + 7] && str[i + 9] != str[i + 7] && str[i + 10] != str[i + 7] && str[i + 11] != str[i + 7] && str[i + 12] != str[i + 7] && str[i + 13] != str[i + 7])
                                    {
                                        if (str[i + 9] != str[i + 8] && str[i + 10] != str[i + 8] && str[i + 11] != str[i + 8] && str[i + 12] != str[i + 8] && str[i + 13] != str[i + 8])
                                        {
                                            if (str[i + 10] != str[i + 9] && str[i + 11] != str[i + 9] && str[i + 12] != str[i + 9] && str[i + 13] != str[i + 9])
                                            {
                                                if (str[i + 11] != str[i + 10] && str[i + 12] != str[i + 10] && str[i + 13] != str[i + 10])
                                                {
                                                   if (str[i + 12] != str[i + 11] && str[i + 13] != str[i + 11])
                                                    {
                                                        if (str[i + 13] != str[i + 12])
                                                        {
                                                            lenght = i + 14;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
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