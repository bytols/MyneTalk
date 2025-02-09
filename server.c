/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:51:31 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/09 17:48:18 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_letter	*g_letra;

void	zero(int sig)
{
	(void) sig;
	g_letra->size++;
}

void	one(int sig)
{
	int	i;
	int	num;

	(void) sig;
	num = 1;
	i = g_letra->size;
	g_letra->size++;
	while (i)
	{
		num = num + num;
		i--;
	}
	g_letra->letra = g_letra->letra + num;
}

int	main(void)
{
	int	pid;

	g_letra = malloc(sizeof(letter));
	signal_count = 0;
	g_letra->letra = 0;
	g_letra->size = 0;
	signal(SIGUSR1, one);
	signal(SIGUSR2, zero);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
	{
		if (g_letra->size == 8)
		{
			g_letra->size = 0;
			ft_printf("%c", g_letra->letra);
			g_letra->letra = 0;
		}
		continue ;
	}
	free(g_letra);
	return (0);
}
