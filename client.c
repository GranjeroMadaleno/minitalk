/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:35:06 by andefern          #+#    #+#             */
/*   Updated: 2024/01/17 15:56:02 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + (str[i] - '0');
		i++;
	}
	return (k);
}

//message convierte los caracteres en bits y los envía
//en forma de señal SIGUSR1 o SIGUSR2.
//usleep hace una pausa de milisegundos para asegurarse
//de que el server pueda procesar correctamente todo.

void	message(char c, int pid)
{
	int	i;
	int	bits;

	i = 7;
	while (i >= 0)
	{
		bits = (c >> i) & 1;
		kill (pid, SIGUSR1 + bits);
		usleep (850);
		i--;
	}
}

//arv[0] Es el nombre del ejecutable "./client".
//arv[1] Es el PID del proceso al que se envian los mensajes.
//arv[2] ES la cadena de caracteres (string) que se envia
//al proceso identificado por el PID.

int	main(int arc, char **arv)
{
	int		i;
	int		pid;

	i = 0;
	if (arc != 3)
	{
		write(1, "error\n", 6);
		return (2);
	}
	pid = ft_atoi(arv[1]);
	if (pid <= 0)
	{
		write(1, "PID is invalid\n", 15);
		exit(EXIT_FAILURE);
	}
	while (arv[2][i] != '\0')
	{
		message(arv[2][i], pid);
		i++;
	}
	return (0);
}
