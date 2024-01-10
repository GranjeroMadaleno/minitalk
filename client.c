/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:35:06 by andefern          #+#    #+#             */
/*   Updated: 2024/01/10 16:36:13 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	client(int pid, char *str)
{
	
}

int	main(int argc, char **argv)
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
