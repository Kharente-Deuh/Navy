/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** str to int
*/

#include "my.h"

int	my_getnbr(char const *s)
{
	int	nb = 0;

	if (*s && *s == '-')
		return (-my_getnbr(s + 1));
	else if (*s && *s == '+')
		return (my_getnbr(s + 1));
	while (*s) {
		if ('0' > *s || *s > '9')
			return (nb);
		nb = nb * 10 + (*s - '0');
		s++;
	}
	return (nb);
}
