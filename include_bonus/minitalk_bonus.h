#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include "libft.h"

void	print_header(void);
void	hand(int sig);
void	handler_sub(int sig);
void	handler(int sig, siginfo_t *info, void *context);
void	err(int err, int i, int tot);
void	send(int c, int dst, int *tot);
#endif
