/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucar <alucar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:26:49 by alucar            #+#    #+#             */
/*   Updated: 2023/09/08 13:26:53 by alucar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
	else
		ft_putchar (n + 48);
}

void	sig_handler(int sig)
{
	static char	c = 0;
	static int	eq_8 = 0;

	if (sig == SIGUSR1)
	{
		c = c | 1;
	}
	if (++eq_8 == 8)
	{
		eq_8 = 0;
		write(1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
}
