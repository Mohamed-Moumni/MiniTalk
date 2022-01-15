/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumni <mmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:49:50 by mmoumni           #+#    #+#             */
/*   Updated: 2022/01/16 00:15:20 by mmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bits(int pid, char c)
{
	unsigned int	one;
	unsigned int	and;
	unsigned int	j;

	j = 0;
	one = 0b10000000;
	while (j < 8)
	{
		and = c & one;
		if (and == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c << 1;
		j++;
		usleep (300);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac < 3)
	{
		write(1, "There is An Error Here\n", 23);
	}
	else
	{
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			bits(pid, av[2][i]);
			i++;
		}
		bits(pid, av[2][i]);
	}
}
