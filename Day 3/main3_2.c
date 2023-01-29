#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int split (char *str, char c, char ***arr)
{
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
            count++;
        p++;
    }

    *arr = (char**) malloc(sizeof(char*) * count);
    if (*arr == NULL)
        exit(1);

    p = str;
    while (*p != '\0')
    {
        if (*p == c)
        {
            (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
            if ((*arr)[i] == NULL)
                exit(1);

            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*arr)[i] = (char*) malloc( sizeof(char) * token_len );
    if ((*arr)[i] == NULL)
        exit(1);

    i = 0;
    p = str;
    t = ((*arr)[i]);
    while (*p != '\0')
    {
        if (*p != c && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = ((*arr)[i]);
        }
        p++;
    }

    return count;
}

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

int main()
{
	char *str = read_input();
	char **strs = NULL;
	int size = 0;
	int res = 0;
	int i = 0;
	int j = 0;
	int start = 0;
	int map1[123] = {0};
	int map2[123] = {0};
	int map3[123] = {0};

	size = split(str, '\n', &strs);
	while (i < size - 2)
	{
		int len1 = strlen(strs[i]);
		int len2 = strlen(strs[i + 1]);
		int len3 = strlen(strs[i + 2]);

		j = 0;
		while (j < len1)
		{
			map1[strs[i][j]]++;
			j++;
		}
		j = 0;
		while (j < len2)
		{
			map2[strs[i + 1][j]]++;
				j++;
		}
		j = 0;
		while (j < len3)
		{
			map3[strs[i + 2][j]]++;
			j++;
		}
		j = 0;
		while (j < 123)
		{
			if (map1[j] >= 1 && map2[j] >= 1 && map3[j] >= 1)
			{
				if (j >= 'A' && j <= 'Z')
					res += (j - 'A') + 27;
				else if (j >= 'a' && j <= 'z')
					res += (j - 'a') + 1;
			}
			map1[j] = 0;
			map2[j] = 0;
			map3[j] = 0;
			j++;
		}
		i += 3;
	}
	printf("%d", res);
}
