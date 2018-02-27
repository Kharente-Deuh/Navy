/*
** EPITECH PROJECT, 2017
** run_game.c
** File description:
** run_game
*/

#include "navy.h"

static int	check_win_map(char **map)
{
	int	i = 0;
	int	j = 0;
	int	nb_x = 0;

	while (map[i]) {
		j = 0;
		while (map[i][j]) {
			if (map[i][j] == 'x')
				++nb_x;
			++j;
		}
		++i;
	}
	if (nb_x == 14)
		return (1);
	return (0);
}

static int	check_win(map_t *map)
{
	if (check_win_map(map->player)) {
		my_printf("Enemy won\n");
		return (1);
	} else if (check_win_map(map->enemy)) {
		my_printf("I won\n");
		return (0);
	}
	return (-1);
}

static int	player_turn(map_t *map)
{
	int	ret = 0;
	int	i = map->player_nb;
	int	turn = 0;

	while (turn < 2) {
		if ((ret = check_win(map)) != -1)
			return (ret);
		if (i % 2 == 1) {
			if (run_atk(map) == -1)
				return (-1);
			++i;
		} else if (i % 2 == 0) {
			if (run_def(map) == -1)
				return (-1);
			++i;
		}
		++turn;
	}
	return (2);
}

int	run_game(map_t *map)
{
	int	ret = 0;

	while (1) {
		my_printf("\nmy positions:\n");
		print_map(map->player);
		my_printf("\nenemy's position:\n");
		print_map(map->enemy);
		my_printf("\n");
		ret = player_turn(map);
		if (ret != 2)
			return (ret);
	}
 }
