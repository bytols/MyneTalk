/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:51:31 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/03 14:49:16 by erocha-l         ###   ########.fr       */
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
    struct sigaction sa;
    struct sigaction sb;

    letra = malloc(sizeof(letter));
    signal_count = 0;
    letra->letra = 0;
    letra->size = 0;
    sa.sa_handler = one;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART | SA_NODEFER;
    sb.sa_handler = zero;
    sigemptyset(&sb.sa_mask);
    sb.sa_flags = SA_RESTART | SA_NODEFER;
    if(sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_printf("deu ruim no um \n");
        return(1);
    }
    if(sigaction(SIGUSR2, &sb, NULL) == -1)
    {
        ft_printf("deu ruim no dois \n");
        return(1);
    }
    pid = getpid();
    ft_printf("%d\n", pid);
    while(1)
    {
        if(letra->size == 8)
        {
            letra->size = 0;
            printf("%c", letra->letra);
            letra->letra = 0;
        }
        continue;
    }
    return(0);
}
