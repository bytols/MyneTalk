/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:51:31 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/01 01:12:41 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    sigint_handler(int sig)
{
    ft_printf("recebi um sigint %d\n", sig);
}

int main()
{
    int pid;
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if(sigaction(SIGINT, &sa, NULL) == -1)
    {
        ft_printf("puts. deu erro");
        return (0);
    }
    pid = getpid();
    ft_printf("%d\n", pid);
    while(1)
    {
        continue ;
    }
    return(0);

}
