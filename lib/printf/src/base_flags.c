/*
** EPITECH PROJECT, 2017
** base_flags.c
** File description:
** %x%X%p%b
*/

#include "printf.h"

int	prtf_put_pointer(va_list ap)
{
	char		*base = "0123456789abcdef";
	char		*s = NULL;
	long long unsigned int nb = va_arg(ap, long long unsigned int);

	if (nb == 0) {
		write(1, "(nil)", 5);
		return (0);
	}
	if ((s = prtf_conv_base(base, 16, nb)) == NULL) {
		return (84);
	}
	write(1, "0x", 2);
	write(1, s, prtf_strlen(s));
	free(s);
	return (0);
}

int	prtf_put_bin(va_list ap)
{
	char		*base = "01";
	char		*s = NULL;
	long long unsigned int	nb = va_arg(ap, long long unsigned int);

	if ((s = prtf_conv_base(base, 2, nb)) == NULL)
		return (84);
	write(1, s, prtf_strlen(s));
	free(s);
	return (0);
}

int	prtf_put_hexa_low(va_list ap)
{
	char		*base = "0123456789abcdef";
	char		*s = NULL;
	long long unsigned int	nb = va_arg(ap, long long unsigned int);

	if ((s = prtf_conv_base(base, 16, nb)) == NULL)
		return (84);
	write(1, s, prtf_strlen(s));
	free(s);
	return (0);
}

int	prtf_put_hexa_up(va_list ap)
{
	char		base[16] = "0123456789ABCDEF";
	char		*s = NULL;
	long long unsigned int	nb = va_arg(ap, long long unsigned int);

	if ((s = prtf_conv_base(base, 16, nb)) == NULL)
		return (84);
	write(1, s, prtf_strlen(s));
	free(s);
	return (0);
}

int	prtf_put_octal(va_list ap)
{
	char		base[8] = "01234567";
	char		*s = NULL;
	long long unsigned int	nb = va_arg(ap, long long unsigned int);

	if ((s = prtf_conv_base(base, 8, nb)) == NULL)
		return (84);
	write(1, s, prtf_strlen(s));
	free(s);
	return (0);
}
