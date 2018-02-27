/*
** EPITECH PROJECT, 2017
** tab_functions.c
** File description:
** tab functions
*/

#include "my.h"

char	**create_tab(int line_nb, int char_nb)
{
	char	**tab;
	int	i = 0;

	MALCHECK((tab = malloc(sizeof(char *) * (line_nb + 1))));
	tab[line_nb] = NULL;
	while (i < line_nb) {
		MALCHECK((tab[i] = malloc(sizeof(char) * (char_nb + 1))));
	++i;
	}
	return (tab);
}

char	**my_tabdup(char **src)
{
	char	**dest = NULL;
	int	i = 0;

	while (src[i])
		++i;
	if ((dest = malloc(sizeof(char *) * (i + 1))) == NULL) {
		return (NULL);
	}
	i = 0;
	while (src[i]) {
		if ((dest[i] = my_strdup(src[i])) == NULL)
			return (NULL);
		++i;
	}
	dest[i] = NULL;
	return (dest);
}

void	my_freetab(char **tab)
{
	int	i = 0;

	while (tab[i]) {
		free(tab[i]);
		++i;
	}
	free(tab);
}

int	my_tablen(char **tab)
{
	int	i = 0;

	while (tab[i]) {
		++i;
	}
	return (i);
}

void	my_puttab(char **tab)
{
	int	i = 0;

	while (tab[i]) {
		write(1, tab[i], my_strlen(tab[i]));
		write(1, "\n", 1);
		++i;
	}
}
