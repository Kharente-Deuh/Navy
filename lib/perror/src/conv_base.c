/*
** EPITECH PROJECT, 2017
** conv_base.c
** File description:
** convert a number in a base
*/

#include "prr.h"

void	prr_conv_base_norm(char **str, char *base_content,
long long unsigned int *nb, int base)
{
	int	tmp = *nb % base;

	(*str)[0] = base_content[tmp];
	(*str)[1] = '\0';
	*nb /= base;
}

char	*prr_conv_base(char *base_content, int base,
long long unsigned int nb)
{
	char	*str = malloc(sizeof(char) * 2);
	char	*base_tmp = NULL;

	if (str == NULL)
		return (NULL);
	prr_conv_base_norm(&str, base_content, &nb, base);
	while (nb > 0) {
		if ((base_tmp = malloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		prr_conv_base_norm(&base_tmp, base_content, &nb, base);
		if ((str = prr_strcat(str, base_tmp)) == NULL)
			return (NULL);
	}
	str = prr_revstr(str);
	return (str);
}
