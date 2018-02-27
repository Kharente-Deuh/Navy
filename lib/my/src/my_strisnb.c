/*
** EPITECH PROJECT, 2017
** my_strisnb.c
** File description:
** verif if a string is a number
*/

#include "my.h"

int	my_strpos(char const *s)
{
	int	i = 0;

	while (s[i]) {
		if ('0' > s[i] || s[i] > '9')
			return (0);
		++i;
	}
	return (1);
}
