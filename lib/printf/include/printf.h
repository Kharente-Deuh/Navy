/*
** EPITECH PROJECT, 2017
** printf.h
** File description:
** printf
*/

#ifndef __PRINTF_H__
# define __PRINTF_H__

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

# ifndef __UNUSED__
#  define UNUSED	__attribute__((unused))
# endif /* UNUSED */

#define MALCHECK(x)	if (!x) return (NULL);
typedef struct flag_struct {
	char	flag;
	int	(*fptr)(va_list);
} flag_t;

char	*prtf_conv_base(char *, int, long long unsigned int);
int 	my_printf(char *, ...);
int	prtf_unsigned(va_list);
int	prtf_put_pointer(va_list);
int	prtf_putchar(va_list);
int	prtf_putstr(va_list);
int	prtf_put_nbr(int);
int	prtf_put_nbr_list(va_list);
int	prtf_percent(va_list);
int	prtf_put_bin(va_list);
char	*prtf_revstr(char *);
int	prtf_put_hexa_low(va_list);
int	prtf_put_hexa_up(va_list);
int	prtf_put_octal(va_list);
char	*prtf_strcat(char *, char *);
int	prtf_strlen(char *);

#endif /* __PRINTF_H__ */
