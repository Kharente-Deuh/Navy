/*
** EPITECH PROJECT, 2017
** get_next_line.c
** File description:
** get a line and go to the next one
*/

#include "my.h"

char	*my_realloc(char *src, int size)
{
	int	i = 0;
	char	*tmp;

	MALCHECK((tmp = malloc(sizeof(char) * size + 1)));
	while (src[i]) {
		tmp[i] = src[i];
		++i;
	}
	src[i] = '\0';
	free(src);
	return (tmp);
}

static char	*ret_value(int ret, char *str)
{
	if (ret == -1)
		return (NULL);
	free(str);
	return (CTRL_D);
}

static char	*norme(char *str, int i, int *ret, int *ptr)
{
	str[i] = '\0';
	--*ret;
	++*ptr;
	return (str);
}

char	*get_next_line(const int fd)
{
	static int	ptr = 0;
	static char	buff[READ_SIZE];
	static int	ret = 0;
	char		*str;
	int		i = 0;

	MALCHECK((str = malloc(sizeof(char) * (READ_SIZE + 1))));
	if (ret == 0 && (ret = read(fd, buff, READ_SIZE)))
		ptr = 0;
	if (!ret)
		return (ret_value(ret, str));
	while (buff[ptr] != '\n' && (buff)[ptr]) {
		str[i++] = buff[ptr++];
		if (--ret == 0 && (ret = read(fd, buff, READ_SIZE))) {
			str[i] = '\0';
			MALCHECK((str = my_realloc(str, i + READ_SIZE)));
			ptr = 0;
		}
	}
	return (str = norme(str, i, &ret, &ptr));
}
