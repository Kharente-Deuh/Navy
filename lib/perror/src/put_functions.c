/*
** EPITECH PROJECT, 2017
** put_functions.c
** File description:
** all the put functions used
*/

#include <limits.h>
#include "prr.h"

int	prr_putchar(va_list ap)
{
	char	c = va_arg(ap, int);

	write(2, &c, 1);
	return (0);
}

int	prr_putstr(va_list ap)
{
	char	*str = va_arg(ap, char *);
	int	len = 0;

	if (str == NULL) {
		write(2, "(null)", 6);
		return (0);
	}
	len = prr_strlen(str);
	if (len == 0) {
		write(2, "(null)", 6);
	} else {
		write(2, str, len);
	}
	return (0);
}

int	prr_percent(va_list UNUSED ap)
{
	write(2, "%", 1);
	return (0);
}

int	prr_put_nbr(int nb)
{
	char	c = 0;

	if (nb == INT_MIN) {
		write(2, "-2147483648", 11);
		return (0);
	}
	if (nb < 0) {
		write(2, "-", 1);
		prr_put_nbr((nb / 10) * -1);
		c = ((nb % 10) * -1) + '0';
		write(2, &c, 1);
	} else {
		if (nb >= 10)
			prr_put_nbr(nb / 10);
		c = (nb % 10) + '0';
		write(2, &c, 1);
	}
	return (0);
}

int	prr_put_nbr_list(va_list ap)
{
	prr_put_nbr(va_arg(ap, int));
	return (0);
}
