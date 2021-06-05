#include "minitalk_bonus.h"

void	hand(int sig)
{
	(void)sig;
}

void	err(int err, int i, int tot)
{
	if (err)
		ft_putstr_fd(strerror(errno), 2);
	else if (tot != i * 8)
		write(2, "Lost bit!\n", 10);
	else
		write(1, "Message transmitted!\n", 21);
}

void	send(int c, int dst, int *tot)
{
	int	j;

	j = 0;
	while (!errno && j < 8)
	{
		if (signal(SIGUSR1, hand) != SIG_ERR)
			*tot += 1;
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
	int	tot;
	int	i;

	if (ac == 3)
	{
		i = 0;
		tot = 0;
		dst = ft_atoi(av[1]);
		while (av[2][i])
		{
			send(av[2][i], dst, &tot);
			++i;
		}
		err(errno, i, tot);
	}
	else
		write(2, "Error, number of arg must to be 3\n", 34);
	return (0);
}
