/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:50:18 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/17 13:34:45 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_pid = 0;

void	ft_print(int *i, int *result)
{
	if (*i == 8)
	{
		ft_putchar(*result);
		*result = 0;
		*i = 0;
	}
}

void	reset(int *i, int *result, int pid)
{
	g_pid = pid;
	*i = 0;
	*result = 0;
}

void	sig_handler(int sig, siginfo_t *sig_info, void *b)
{
	static int	i;
	static int	result;

	(void)b;
	if (g_pid != sig_info->si_pid)
		reset(&i, &result, sig_info->si_pid);
	if (sig == SIGUSR1)
	{
		result *= 2;
		result = result + 1;
		i++;
		ft_print(&i, &result);
	}
	else
	{
		result *= 2;
		result = result + 0;
		i++;
		ft_print(&i, &result);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig_struct;

	pid = getpid();
	write(1, "Server PID :", 13);
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
	return (0);
}
