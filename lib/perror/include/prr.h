/*
** EPITECH PROJECT, 2017
** prr.h
** File description:
** prr
*/

#ifndef __PRR_H__
# define __PRR_H__

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

# ifndef __UNUSED__
#  define UNUSED	__attribute__((unused))
# endif /* UNUSED */

typedef struct flag {
	char	flag;
	int	(*fptr)(va_list);
} flags_t;

char	*prr_conv_base(char *, int, long long unsigned int);
int 	my_perror(char *, ...);
int	prr_unsigned(va_list);
int	prr_put_pointer(va_list);
int	prr_putchar(va_list);
int	prr_putstr(va_list);
int	prr_put_nbr(int);
int	prr_put_nbr_list(va_list);
int	prr_percent(va_list);
int	prr_put_bin(va_list);
char	*prr_revstr(char *);
int	prr_put_hexa_low(va_list);
int	prr_put_hexa_up(va_list);
int	prr_put_octal(va_list);
char	*prr_strcat(char *, char *);
int	prr_strlen(char *);

#endif /* __PRR_H__ */
