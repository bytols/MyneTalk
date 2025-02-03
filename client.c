#include "minitalk.h"
void send_letter(char *str)
{
    int i;
    int bin_num;
    
    i = 0;
    while(str[i])
    {
        bin_num = 1;
        while(bin_num <= 128)
        {
            if((str[i] & bin_num) == bin_num)
                ft_printf("um \n");
            else
                ft_printf("zero \n");
            bin_num = bin_num + bin_num;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    int pid;

    if(argc != 3)
        return (0);
    send_letter(argv[2]);
    pid = ft_atoi(argv[1]);
    ft_printf("aqui o pid %d\n", pid);
    kill(pid, SIGINT);
}
