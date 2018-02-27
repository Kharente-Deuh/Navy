/*
** EPITECH PROJECT, 2017
** protocol.c
** File description:
** protocol
*/

#include "navy.h"

char	bin_to_char(int nb)
{
	char	res = 0;
	int	pow = 0;

	while (nb) {
		res +=  (nb % 10) * my_compute_power_it(2, pow);
		nb /= 10;
		++pow;
	}
	return (res);
}

static char	*conv_char_bin(char nb)
{
	char	*base_tmp = NULL;
	int	tmp = nb % 2;
	char	*str = NULL;

	MALCHECK((str = malloc(sizeof(char) * 2)));
	MALCHECK((base_tmp = malloc(sizeof(char) * 2)));
	str[0] = tmp + '0';
	str[1] = '\0';
	nb /= 2;
	while (nb > 0) {
		tmp = nb % 2;
		base_tmp[0] = tmp + '0';
		base_tmp[1] = '\0';
		MALCHECK((str = my_strcat(str, base_tmp)));
		nb /= 2;
	}
	while (my_strlen(str) != 8)
		MALCHECK((str = my_strcat(str, "0")));
	my_revstr(str);
	free(base_tmp);
	return (str);
}

static int	send_signal(int pid, char *bin)
{
	int	i = 0;

	NULLCHECK(bin);
	while (bin[i]) {
		usleep(1000);
		if (bin[i] == '0') {
			kill(pid, SIGUSR1);
		} else {
			kill(pid, SIGUSR2);
		}
		++i;
	}
	free(bin);
	return (1);
}

int	protocol(int pid, char *msg)
{
	if (my_strlen(msg) != 2 || 'A' > msg[0] || msg[0] > 'H' ||
	'1' > msg[1] || msg[1] > '8') {
		my_perror("Wrong position\n");
		return (0);
	}
	NULLCHECK(send_signal(pid, conv_char_bin(msg[0])));
	usleep(2000);
	NULLCHECK(send_signal(pid, conv_char_bin(msg[1])));
	return (1);
}
