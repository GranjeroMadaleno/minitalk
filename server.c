/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andefern <andefern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:35:18 by andefern          #+#    #+#             */
/*   Updated: 2024/01/10 16:35:53 by andefern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 1;
	n = 0;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == ' ' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + str[i] - '0';
		i++;
	}
	return (n * j);
}

void	server(int sig, siginfo_t *s_info, void *context)
{
	int				i;
	int				c;
	unsigned char	client_pid;

	i = 0;
	c = 0;
	client_pid = 0;
	(void)context;
	if (!client_pid)
		client_pid = s_info->si_pid;
	c = c | (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	while (1)
	{
		sleep(1);
	}
	return (0);
}
int main(argv[1])
{
	server(argv[1]);
	return 0;
}
//server tiene que mostrar su pid, printearmelo
//y sino que se quede pensndo