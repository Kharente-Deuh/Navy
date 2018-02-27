/*
** EPITECH PROJECT, 2017
** base_flags.c
** File description:
** %x%X%p%b
*/

#include "prr.h"

int	prr_put_pointer(va_list ap)
{
	char		*base = "0123456789abcdef";
	char		*s = NULL;
	long long unsigned int nb = va_arg(ap, long long unsigned int);

	if (nb == 0) {
		write(2, "(nil)", 5);
		return (0);
	}
	if ((s = prr_conv_base(base, 16, nb)) == NULL) {
		return (84);
	}
	write(2, "0x", 2);
	write(2, s, prr_strlen(s));
	free(s);
	return (0);
}

int	prr_put_bin(va_list ap)
{
	char		*base = "01";
	char		*s = NULL;
	long long unsigned int	nb = va_arg(ap, long long unsigned int);

	if ((s = prr_conv_base(base, 2, nb)) == NULL)
		return (84);
	write(2, s, prr_strlen(s));
	free(s);
	return (0);
}

int	prr_put_hexa_low(va_list ap)
{
	char		*base = "0123456789abcdef";
	char		*s = NULL;
	long long unsigned int	nb = va_arg(ap, long long unsigned int);

	if ((s = prr_conv_base(base, 16, nb)) == NULL)
		return (84);
	write(2, s, prr_strlen(s));
	free(s);
	return (0);
}

int	prr_put_hexa_up(va_list ap)
{
	char		base[16] = "0123456789ABCDEF";
	char		*s = NULL;
	long long unsigned int	nb = va_arg(ap, long long unsigned int);

	if ((s = prr_conv_base(base, 16, nb)) == NULL)
		return (84);
	write(2, s, prr_strlen(s));
	free(s);
	return (0);
}

int	prr_put_octal(va_list ap)
{
	char		base[8] = "01234567";
	char		*s = NULL;
	long long unsigned int	nb = va_arg(ap, long long unsigned int);

	if ((s = prr_conv_base(base, 8, nb)) == NULL)
		return (84);
	write(2, s, prr_strlen(s));
	free(s);
	return (0);
}
