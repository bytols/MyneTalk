/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:51:31 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/06 17:08:38 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

letter *letra;
int signal_count;

void    zero(int sig)
{
    (void) sig;
    letra->size++;
    signal_count++;
    //ft_printf("%d\n", signal_count);
}

void    one(int sig)
{
    (void) sig;
    int i;
    int num;

    num = 1;
    i = letra->size;
    letra->size++;
    while (i)
    {
        num = num + num;
        i--;
    }
    letra->letra = letra->letra + num;
    signal_count++;
    //ft_printf("%d\n", signal_count);
}

int main()
{
    int pid;

    letra = malloc(sizeof(letter));
    signal_count = 0;
    letra->letra = 0;
    letra->size = 0;
    signal(SIGUSR1, one);
    signal(SIGUSR2, zero);
    pid = getpid();
    ft_printf("%d\n", pid);
    while(1)
    {
        if(letra->size == 8)
        {
            letra->size = 0;
            ft_printf("%c", letra->letra);
            letra->letra = 0;
        }
        continue;
    }
    return(0);
}
