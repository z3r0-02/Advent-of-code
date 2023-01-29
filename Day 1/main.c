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

int cmp(const void* a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void calculate()
{
	char *str = read_input();
	int i = 0;
	int j = 0;
	int res;
	int sum;
	sum = 0;
	res = 0;
	int arr[1000] = {0};
	while (str[i])
	{
		res += atoi(&str[i]);
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if ((str[i] == '\n' && str[i + 1] == '\n') || str[i] == '\0')
		{
			arr[j] = res;
			j++;
			res = 0;
			i++;
		}
		i++;
	}
	qsort(arr, 1000, sizeof(int), cmp);
	sum = arr[0] + arr[1] + arr[2];
	printf("%d", sum);
}
int main()
{
	calculate();
}
