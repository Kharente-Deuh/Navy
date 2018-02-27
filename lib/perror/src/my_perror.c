/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** printf
*/

#include "prr.h"

static int	prr_found_flag(char c, flags_t *struct_tab)
{
	int	i = 0;

	while (i < 11) {
		if (c == struct_tab[i].flag)
			return (i);
		i++;
	}
	return (84);
}

static int	run(flags_t struct_tab[], char *str, va_list ap)
{
	int	i = 0;
	int	flag = 0;

	while (str[i]) {
		if (str[i] == '%') {
			flag = prr_found_flag(str[i + 1], struct_tab);
			if (flag == 84 || struct_tab[flag].fptr(ap) == 84)
				return (-1);
			i++;
		} else
			write(2, &str[i], 1);
		i++;
	}
	return (1);
}

int	my_perror(char *str, ...)
{
	va_list	ap;
	flags_t struct_tab[] = {{'c', &prr_putchar}, {'%', &prr_percent},
		{'s', &prr_putstr}, {'d', &prr_put_nbr_list},
		{'i', &prr_put_nbr_list}, {'x', &prr_put_hexa_low},
		{'X', &prr_put_hexa_up}, {'o', &prr_put_octal},
		{'b', &prr_put_bin}, {'p', &prr_put_pointer},
		{'u', &prr_unsigned}};

	va_start(ap, str);
	if (!run(struct_tab, str, ap))
		return (84);
	va_end(ap);
	return (0);
}
