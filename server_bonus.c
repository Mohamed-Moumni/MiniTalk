/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:24:16 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/17 13:42:14 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	send_msg(int *var, int *result, siginfo_t *t)
{
	if (*var == 8)
	{
		if (*result == 0)
		{
			kill(t->si_pid, SIGUSR1);
		}
		else
			ft_putchar(*result);
		*result = 0;
		*var = 0;
	}
}

void	reset(int *var, int *result, int pid)
{
	g_pid = pid;
	*var = 0;
	*result = 0;
}

void	sig_handler(int sig, siginfo_t *t, void *b)
{
	static int	var;
	static int	result;

	(void)b;
	if (g_pid != t->si_pid)
		reset(&var, &result, t->si_pid);
	if (sig == SIGUSR1)
	{
		result *= 2;
		result = result + 1;
		var++;
		send_msg(&var, &result, t);
	}
	else
	{
		result *= 2;
		result = result + 0;
		var++;
		send_msg(&var, &result, t);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig_struct;

	pid = getpid();
	write(1, "Server PID: ", 13);
	ft_putnbr(pid);
	ft_putchar('\n');
	sig_struct.__sigaction_u.__sa_sigaction = &sig_handler;
	sig_struct.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig_struct, NULL);
	sigaction(SIGUSR2, &sig_struct, NULL);
	while (1)
	{
		pause();
	}
}
