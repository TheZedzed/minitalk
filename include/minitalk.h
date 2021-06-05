#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include "libft.h"

void	hand(int sig);
void	handler_sub(int sig);
void	handler(int sig, siginfo_t *info, void *context);
void	print_header(void);
void	send(int c, int dst);
void	hand(int sig);
#endif
