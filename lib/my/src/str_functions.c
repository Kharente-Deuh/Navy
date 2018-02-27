/*
** EPITECH PROJECT, 2017
** str_functions.c
** File description:
** str functions
*/

#include "my.h"

int	my_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*my_strcat(char *s1, char *s2)
{
	char	*dest = NULL;
	int	i = 0;
	int	j = 0;

	if ((dest = malloc(sizeof(char) * ((my_strlen(s1) +
		my_strlen(s2) + 1)))) == NULL)
		return (NULL);
	while (s1[i]) {
		dest[i] = s1[i];
		i++;
	}
	while (s2[j]) {
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}

void	my_revstr(char *str)
{
	char	tmp;
	int	i = 0;
	int	j = 0;

	while (str[i])
		i++;
	i--;
	while (i > j) {
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i--;
		j++;
	}
}

int	my_strncmp(char *s1, char *s2, int nb)
{
	int	i = 0;
	int	res = 0;

	while (s1[i] && s2[i] && i < nb) {
		if ((res = s2[i] - s1[i]) != 0)
			return (res);
		++i;
	}
	return (0);
}

int	my_strcmp(char *s1, char *s2)
{
	int	i = 0;
	int	res = 0;

	while (s1[i] && s2[i]) {
		if ((res = s2[i] - s1[i]) != 0)
			return (res);
		++i;
	}
	return (0);
}
