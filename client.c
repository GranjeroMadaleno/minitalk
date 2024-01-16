/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:35:06 by andefern          #+#    #+#             */
/*   Updated: 2024/01/16 13:25:23 by andefern         ###   ########.fr       */
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

/*int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("%s", "ERROR, THERE ARE NOT 3 ARGUMENT FOUND");
		return (1);
	}
	else
	{
		printf("PID: %s\n", argv[1]);
		printf("STRING: %s\n", argv[2]);
		client(argv[1], argv[2]);
	}
	//recibe PID, String y ejecutble
	//devolver el string recibido
	return (0);
}
*/
/*
    // Registrar el manejador para SIGUSR1
    if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
        perror("Error al registrar el manejador para SIGUSR1");
        return 1;
    }

    // Registrar el manejador para SIGUSR2
    if (signal(SIGUSR2, sigusr2_handler) == SIG_ERR) {
        perror("Error al registrar el manejador para SIGUSR2");
        return 1;
    }
*/

//kill -SIGUSR1 <pid_del_programa>
