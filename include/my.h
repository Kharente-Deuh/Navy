/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** proto of lib my
*/

#ifndef __MY_H__
# define __MY_H__

#include <stdlib.h>
#include <unistd.h>

# define MALCHECK(x)	if (!x) return (NULL);
# define NULLCHECK(x)	if (!x) return (-1);
# ifndef READ_SIZE
#  define CTRL_D	"qlfBFIFDSN_-_èè__ééé"
#  define READ_SIZE	4096
# endif /* !READ_SIZE */

int	my_compute_power_it(int, int);
char	**create_tab(int, int);
char	*my_itoa(int);
int	my_strpos(char const *s);
int	is_letter(char);
char	*my_realloc(char *, int);
char	*get_next_line(int);
int	my_strlen(char *);
char	**my_str_to_word_tab(char *);
char	*my_strcat(char *, char *);
char	*my_strdup(char *);
void	my_revstr(char *);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	**my_tabdup(char **);
char	*my_strdupn(char *, int);
void	my_freetab(char **);
int	my_tablen(char **);
char	*my_strndup(char *, int);
void	my_revtab(char ***);
void	my_puttab(char **);
int	my_getnbr(char const *);

#endif /* __MY_H__ */
