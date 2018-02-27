/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** for navy
*/

#include "navy.h"

int	init_game(map_t *map, int argc, char **argv)
{
	if (argc == 2) {
		if (init_player_one(map, argv) == -1)
			return (-1);
	} else {
		if (init_player_two(map, argv) == -1)
			return (-1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	map_t	*map = NULL;
	int	ret = 0;

	if (!(argc == 2 || argc == 3)) {
		my_printf("navy: Invalid options, try -h for see help\n");
		return (84);
	}
	if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
		usage();
		return (0);
	}
	NULLCHECK((map = malloc(sizeof(map_t))));
	map->enemy_pid = 0;
	if (init_game(map, argc, argv) == -1 || (ret = run_game(map)) == -1)
		return (84);
	my_freetab(map->player);
	my_freetab(map->enemy);
	free(map);
	return (ret);
}
