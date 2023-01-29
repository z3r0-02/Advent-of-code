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

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);

}

int ft_double(char c, char *str)
{
    int i;
    int len;

    len = ft_strlen(str);
    i = ft_strlen(str) / 2;
    while (i < len)
	{
		if (str[i] == c)
			return (1);
        i++;
	}
	return (0);
}

void calculate()
{
    int i;
    int lenght;
    int sum;
    i = 0;
    char *str = read_input();
    lenght = ft_strlen(str) / 2;
    while (str[i])
    {
        while (i < lenght)
        {
            if (ft_double(str[i], str) == 1)
            {
                if (str[i] >= 'a' && str[i] <= 'z')
                {
                    sum += str[i] - 'a' + 1;
                    break;
                }
                else if (str[i] >= 'A' && str[i] <= 'Z')
                {
                    sum += str[i] - 'A' + 27;
                    break;
                }
            }
            i++;
        }
        while (str[i] != '\n' && str[i] != '\0')
        i++;
    }  
    printf("%d", sum);
}

int main ()
{
    calculate();
}