/*
** EPITECH PROJECT, 2017
** conv_base.c
** File description:
** convert a number in a base
*/

#include "printf.h"

char	*prtf_conv_base(char *base_content, int base,
long long unsigned int nb)
{
	char	*str = malloc(sizeof(char) * 2);
	char	*base_tmp = NULL;
	int	tmp = nb % base;

	MALCHECK(str);
	str[0] = base_content[tmp];
	str[1] = '\0';
	nb /= base;
	while (nb > 0) {
		MALCHECK((base_tmp = malloc(sizeof(char) * 2)));
		str[0] = base_content[tmp];
		str[1] = '\0';
		nb /= base;
		MALCHECK((str = prtf_strcat(str, base_tmp)));
	}
	str = prtf_revstr(str);
	return (str);
}
