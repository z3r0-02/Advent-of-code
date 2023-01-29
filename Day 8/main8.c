/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbui <thbui@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:27:31 by lin               #+#    #+#             */
/*   Updated: 2023/01/11 19:01:19 by thbui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    int row;
    int column;
    int i;
    int res;

    row = 0;
    column = 0;
    i = 0;
    while (str[row] != '\n')
        row++;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            column++;
        i++;
    }

    res = row + column ; // + something more
    i = 0;
    while (str[i])
    {
        
    }
    printf("%d", res);
}

int main()
{
    calculate();
}