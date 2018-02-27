/*
** EPITECH PROJECT, 2017
** my_str_to_word_tab.c
** File description:
** make a table with all the words of a sentence
*/

#include "my.h"

int	count_words(char *str)
{
	int	i = 0;
	int	word = 0;

	while (str[i]) {
		while (!is_letter(str[i]) && str[i])
			i++;
		if (is_letter(str[i]) && str[i])
			word++;
		while (is_letter(str[i]) && str[i])
			i++;
	}
	return (word);
}

char	**malloc_lines_two(int *i, char *src, char **dest, int *j)
{
	int	k = 0;
	int	len = 0;
	int	srclen = my_strlen(src);

	if (*i >= srclen || !is_letter(src[*i]))
		return (dest);
	while (*i + len < srclen && is_letter(src[*i + len]))
		++len;
	if ((dest[*j] = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	dest[*j][len] = '\0';
	while (is_letter(src[*i])) {
		dest[*j][k] = src[*i];
		++*i;
		k++;
	}
	++*j;
	return (dest);
}

char	**malloc_lines(char *src, char **dest)
{
	int	i = 0;
	int	j = 0;
	int	srclen = my_strlen(src);

	while (i < srclen) {
		dest = malloc_lines_two(&i, src, dest, &j);
		if (dest == NULL)
			return (NULL);
		i++;
	}
	dest[j] = NULL;
	free(src);
	return (dest);
}

char	**my_str_to_word_tab(char *src)
{
	char	**dest = NULL;
	int	tab_len = 0;

	if (src == NULL)
		return (NULL);
	tab_len = count_words(src);
	if ((dest = malloc(sizeof(char *) * (tab_len + 1))) == NULL)
		return (NULL);
	dest[tab_len] = NULL;
	return (malloc_lines(src, dest));
}
