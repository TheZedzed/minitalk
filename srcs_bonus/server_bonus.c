#include "minitalk_bonus.h"

void	handler_sub(int sig)
{
	static int	c = 0;
	static int	i = 0;

	if (sig == SIGUSR2)
		c += (1 << i);
	++i;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	print_header(void)
{
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	handler_sub(sig);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	print_header();
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigemptyset(&act.sa_mask);
		sigaddset(&act.sa_mask, SIGUSR1);
		sigaddset(&act.sa_mask, SIGUSR2);
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
	}
	return (0);
}
