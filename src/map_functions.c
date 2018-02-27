/*
** EPITECH PROJECT, 2017
** map_functions.c
** File description:
** map functions
*/

#include "navy.h"

static void	change_map(map_t *map, char *str)
{
	int index = 0;
	int index2 = '1';
	int index3 = 'A';

	map->player[str[6] - '1'][str[5] - 'A'] = str[0];
	if (str[2] == str[5]) {
		while (((str[0] - 48) - index) > 0) {
			map->player[str[3] - index2][str[2] - 'A'] = str[0];
			++index;
			--index2;
		}
	}
	else {
		while (((str[0] - 48) - index) > 0) {	
			map->player[str[3] - '1'][str[2] - index3] = str[0];
			++index;
			--index3;
		}
	}
}

int	read_map(map_t *map, char *file)
{
	int	fd = open(file, O_RDONLY);
	char	*str = NULL;
	int	is_reading = 1;

	if (fd == -1)
		return (-1);
	while (is_reading) {
		if ((str = get_next_line(fd)) == NULL)
			return (-1);
		if (my_strcmp(str, CTRL_D) == 0)
			is_reading = 0;
		else
			change_map(map, str);
	}
	return (1);
}

void	print_map(char **map)
{
	int	i = 0;
	int	j = 0;
	char	nb = '1';

	my_printf(" |A B C D E F G H\n-+---------------\n");
	while (map[i]) {
		my_printf("%c|", nb);
		j = 0;
		while (map[i][j]) {
			my_printf("%c ", map[i][j]);
			++j;
		}
		my_printf("\n");
		++i;
		++nb;
	}
}

int	create_map(map_t *map)
{
	int	i = 0;
	int	j = 0;

	NULLCHECK((map->player = create_tab(8, 8)));
	NULLCHECK((map->enemy = create_tab(8, 8)));
	while (i < 8) {
		j = 0;
		while (j < 8) {
			map->player[i][j] = '.';
			map->enemy[i][j] = '.';
			++j;
		}
		map->player[i][j] = '\0';
		map->enemy[i][j] = '\0';
		++i;
	}
	return (1);
}
