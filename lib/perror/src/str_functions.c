/*
** EPITECH PROJECT, 2017
** str_functions.c
** File description:
** str functions
*/

#include "prr.h"

int	prr_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*prr_strcat(char *s1, char *s2)
{
	char	*dest = malloc(sizeof(char) * (prr_strlen(s1)
	+ prr_strlen(s2) + 2));
	int	i = 0;
	int	j = 0;

	if (dest == NULL)
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
	free(s2);
	return (dest);
}

char	*prr_revstr(char *str)
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
	return (str);
}
