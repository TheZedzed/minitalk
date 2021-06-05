#include "minitalk.h"

void	hand(int sig)
{
	(void)sig;
}

void	send(int c, int dst)
{
	int	j;

	j = 0;
	while (!errno && j < 8)
	{
		signal(SIGUSR1, hand);
		if (usleep(1000) < 0)
			errno = 0;
		if ((c >> j) & 1)
			kill(dst, SIGUSR2);
		else
			kill(dst, SIGUSR1);
		++j;
	}
}

int	main(int ac, char **av)
{
	int	dst;
	int	i;

	if (ac == 3)
	{
		i = 0;
		dst = ft_atoi(av[1]);
		while (av[2][i])
		{
			send(av[2][i], dst);
			++i;
		}
		if (errno)
			ft_putstr_fd(strerror(errno), 2);
	}
	else
		write(2, "Error, number of arg must to be 3\n", 34);
	return (0);
}
