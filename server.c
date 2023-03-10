/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:37:00 by ataskin           #+#    #+#             */
/*   Updated: 2023/02/06 19:37:01 by ataskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	signalcather(int signal)
{
	static unsigned char	total;
	static int				mi = 128;

	if (signal == SIGUSR2)
		total += mi;
	mi /= 2;
	if (mi == 0)
	{
		write (1, &total, 1);
		mi = 128;
		total = 0;
	}
}

void	ft_printnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_printnbr(n / 10);
	c = n % 10 + 48;
	write(1, &c, 1);
}

int	main(void)
{
	ft_printnbr(getpid());
	write(1, "\n", 1);
	signal (SIGUSR1, signalcather);
	signal (SIGUSR2, signalcather);
	while (1)
		pause();
	return (0);
}
