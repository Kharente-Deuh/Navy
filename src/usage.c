/*
** EPITECH PROJECT, 2018
** usage.c
** File description:
** for navy
*/

#include "navy.h"

void	usage(void)
{
	my_printf("USAGE\n\t./navy [first_player_pid] navy_positions\n");
	my_printf("DESCRIPTION\n\tfirst_player_pid:  only for the 2nd player");
	my_printf(". pid of the first player.\n\tnavy_positions:  ");
	my_printf("file representing the positions of the ships.\n");
}
