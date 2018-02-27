/*
** EPITECH PROJECT, 2017
** my_strdup_strcmp.c
** File description:
** strdup, strndup, strdupn, strcmp and strncmp
*/

#include "my.h"

char	*my_strdup(char *str)
{
	int	i = 0;
	char	*tmp = NULL;

	if (str == NULL) {
		if ((tmp = malloc(sizeof(char) * 1)) == NULL)
			return (NULL);
		str[0] = '\0';
		return (tmp);
	}
	if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
		return (NULL);
	while (str[i]) {
		tmp[i] = str[i];
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*my_strdupn(char *src, int nb)
{
	int	i = 0;
	int	j = nb;
	char	*dest = NULL;

	if ((dest = malloc(sizeof(char) * (my_strlen(src) - nb + 1))) == NULL)
		return (NULL);
	while (src[j]) {
		dest[i] = src[j];
		++j;
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*my_strndup(char *src, int n)
{
	int	i = 0;
	char	*dest = malloc(sizeof(char) * (n + 1));

	if (dest == NULL)
		return (NULL);
	while (src[i] && i < n) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	is_letter(char c)
{
	if (' ' < c && c <= '~' && c != ':')
		return (1);
	return (0);
}
