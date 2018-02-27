/*
** EPITECH PROJECT, 2017
** put_unsigned.c
** File description:
** %u
*/

#include "printf.h"

int	prtf_put_nbr_uns(unsigned int nb)
{
	char	c = 0;

	if (nb >= 10)
		prtf_put_nbr_uns(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	return (0);
}

int	prtf_unsigned(va_list ap)
{
	unsigned int nb = va_arg(ap, unsigned int);

	return (prtf_put_nbr_uns(nb));
}
