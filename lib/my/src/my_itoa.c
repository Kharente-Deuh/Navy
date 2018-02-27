/*
** EPITECH PROJECT, 2017
** my_itoa.c
** File description:
** my_itoa
*/

#include "my.h"

char	*my_itoa(int nb)
{
	char	*dest;
	int	tmp = nb;
	int	i = 0;

	while (tmp) {
		tmp /= 10;
		++i;
	}
	MALCHECK((dest = malloc(sizeof(char) * (i + 1))))
	i = 0;
	while (nb) {
		dest[i] = (nb % 10) + '0';
		++i;
		nb /= 10;
	}
	dest[i] = '\0';
	my_revstr(dest);
	return (dest);
}
