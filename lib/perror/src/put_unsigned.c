/*
** EPITECH PROJECT, 2017
** put_unsigned.c
** File description:
** %u
*/

#include "prr.h"

int	prr_put_nbr_uns(unsigned int nb)
{
	char	c = 0;

	if (nb >= 10)
		prr_put_nbr_uns(nb / 10);
	c = (nb % 10) + '0';
	write(2, &c, 1);
	return (0);
}

int	prr_unsigned(va_list ap)
{
	unsigned int nb = va_arg(ap, unsigned int);

	return (prr_put_nbr_uns(nb));
}
