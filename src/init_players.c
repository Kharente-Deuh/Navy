/*
** EPITECH PROJECT, 2017
** init_players.c
** File description:
** init players
*/

#include "navy.h"

static void	handler(UNUSED int sig, siginfo_t *siginfo,
UNUSED void *context)
{
	glob_int = siginfo->si_pid;
	my_printf("\nenemy connected\n");
}

static int	init_connexion_pone(void)
{
	struct sigaction sig;

	sig.sa_sigaction = handler;
	sig.sa_flags = SA_SIGINFO;
	my_printf("waiting for enemy connection...\n");
	if (sigaction(SIGUSR1, &sig, NULL) == -1 || pause() == -1)
		return (-1);
	return (1);
}

int	init_player_one(map_t *map, char **argv)
{
	if (!create_map(map) || !read_map(map, argv[1]))
		return (-1);
	map->player_nb = 1;
	my_printf("my_pid: %d\n", getpid());
	if (!init_connexion_pone())
		return (-1);
	map->enemy_pid = glob_int;
	return (1);
}

static int	init_connexion_ptwo(map_t *map)
{
	if (kill(map->enemy_pid, SIGUSR1) == -1) {
		my_printf("\nWrong target\n\n");
		return (-1);
	}
	my_printf("Successfully connected\n");
	return (1);
}

int	init_player_two(map_t *map, char **av)
{
	if (!create_map(map) || !my_strpos(av[1]) || !read_map(map, av[2]))
		return (-1);
	map->player_nb = 2;
	my_printf("my_pid: %d\n", getpid());
	map->enemy_pid = my_getnbr(av[1]);
	if (init_connexion_ptwo(map) == -1)
		return (-1);
	return (1);
}
