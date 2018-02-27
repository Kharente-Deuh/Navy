/*
** EPITECH PROJECT, 2017
** navy.h
** File description:
** navy protos
*/

#ifndef __NAVY_H__
# define __NAVY_H__

#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>
#include "my.h"
#include "printf.h"
#include "prr.h"

int	glob_int;

typedef struct	maps_s {
	char	**player;
	char	**enemy;
	int	enemy_pid;
	int	player_nb;
}map_t;

int	init_player_one(map_t *, char **);
int	init_player_two(map_t *, char **);
void	usage(void);

char	bin_to_char(int bin);
int	protocol(int, char *);

int	run_game(map_t *);
int	run_def(map_t *);
int	run_atk(map_t *);

int	create_map(map_t *);
void	print_map(char **);
int	read_map(map_t *, char *);
#endif
