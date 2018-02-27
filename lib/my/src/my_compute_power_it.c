/*
** EPITECH PROJECT, 2017
** my_compute_power_it.c
** File description:
** compute power iterative
*/

#include "my.h"

int	my_compute_power_it(int nb, int p)
{
	int	x = nb;

	if (nb == 0)
		return (0);
	if (p < 0)
		return (0);
	else if (p == 0)
		return (1);
	else {
		while (p > 1) {
			x *= nb;
			p--;
		}
	}
	return (x);
}
