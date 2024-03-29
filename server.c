/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:35:18 by andefern          #+#    #+#             */
/*   Updated: 2024/01/17 15:57:23 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

//El server muestra su número PID para que client
//pueda comunicarse utilizando ese mismo número.

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}
//handler procesa las señales SIGUSR1 y SIGUSR2.
//recibe bits mediante esas señales y cuando llega a 8 bits
//imprime el carácter y se resetea para el siguiente bit.

void	handler(int sig, siginfo_t *s_info, void *context)
{
	static char	c;
	static int	i;
	static int	last_pid;
	int			bits;

	context = NULL;
	if (last_pid != 0 && last_pid != s_info->si_pid)
	{
		c = 0;
		i = 0;
		write(1, "\n", 1);
	}
	i++;
	bits = sig - 30;
	c = (c << 1) | bits;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	last_pid = s_info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler;
	sa.sa_mask = 0;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "Server PID: ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
