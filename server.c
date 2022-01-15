/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:50:18 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/16 00:40:43 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print(int var, int result)
{
	if (var == 8)
	{
		ft_putchar(result);
		result = result + 1;
		var = 0;
	}
}

void	sig_handler(int sig, siginfo_t *t, void *b)
{
	static int	var;
	static int	result;

	(void)b;
	(void)t;
	if (sig == SIGUSR1)
	{
		result *= 2;
		result = result + 1;
		var++;
		ft_print(var, result);
	}
	else
	{
		result *= 2;
		result = result + 0;
		var++;
		ft_print(var, result);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig_struct;

	pid = getpid();
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
