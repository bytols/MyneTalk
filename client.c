/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erocha-l <erocha-l@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:44:50 by erocha-l          #+#    #+#             */
/*   Updated: 2025/02/03 20:44:50 by erocha-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void send_letter(char *str, int sig)
{
    int i;
    int bin_num;
    int signals_count;
    
    signals_count = 0;
    i = 0;
    ft_printf("meu sig: %d\n" , sig);
    while(str[i])
    {
        bin_num = 1;
        while(bin_num <= 128)
        {
            if((str[i] & bin_num) == bin_num)
            {
                kill(sig, SIGUSR1);
                signals_count++;
                ft_printf("um %d\n", signals_count);
            }
            else
            {
                kill(sig, SIGUSR2);
                signals_count++;
                ft_printf("zero %d\n", signals_count);
            }
            bin_num = bin_num + bin_num;
            usleep(2000);
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    int pid;

    if(argc != 3)
        return (0);
    pid = ft_atoi(argv[1]);
    ft_printf("aqui o pid %d\n", pid);
    send_letter(argv[2], pid);
}
