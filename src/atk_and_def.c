/*
** EPITECH PROJECT, 2017
** atk_and_def.c
** File description:
** run defence end attack turns
*/

#include "navy.h"

static void	handler(int sig)
{
	if (sig == SIGUSR1)
		glob_int = 0;
	else if (sig == SIGUSR2)
		glob_int = 1;
}

static int	check_atk(map_t *map, char *pos)
{
	my_printf("%s: ", pos);
	if ('2' <= map->player[pos[1] - '1'][pos[0] - 'A'] &&
	map->player[pos[1] - '1'][pos[0] - 'A'] <= '5') {
		map->player[pos[1] - '1'][pos[0] - 'A'] = 'x';
		usleep(1000);
		kill(map->enemy_pid, SIGUSR2);
		my_printf("hit\n");
	} else {
		map->player[pos[1] - '1'][pos[0] - 'A'] = 'o';
		usleep(1000);
		kill(map->enemy_pid, SIGUSR1);
		my_printf("missed\n");
	}
	return (1);
}

int	run_def(map_t *map)
{
	int	i = 0;
	int	j = 0;
	int	bin = 0;
	char	*pos = malloc(sizeof(char) * 3);

	NULLCHECK(pos);
	my_printf("waiting for enemy’s attack...\n");
	while (i < 2) {
		j = 0;
		bin = 0;
		while (j < 8) {
			signal(SIGUSR1, &handler);
			signal(SIGUSR2, &handler);
			pause();
			bin = bin * 10 + glob_int;
			++j;
		}
		pos[i++] = bin_to_char(bin);
	}
	pos[2] = '\0';
	return (check_atk(map, pos));
}

int	run_atk(map_t *map)
{
	char	*s = NULL;
	int	ret = 0;

	my_printf("attack: ");
	if ((s = get_next_line(0)) == NULL || (my_strcmp(s, CTRL_D) == 0) ||
		(ret = protocol(map->enemy_pid, s)) == -1)
		return (-1);
	if (ret == 0)
		return (run_atk(map));
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	pause();
	if (glob_int) {
		my_printf("%s: hit\n", s);
		map->enemy[s[1] - '1'][s[0] - 'A'] = 'x';
	} else {
		my_printf("%s: missed\n", s);
		map->enemy[s[1] - '1'][s[0] - 'A'] = 'o';
	}
	return (1);
}
