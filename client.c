#include "minitalk.h"
int main(int argc, char *argv[])
{
    int pid;

    (void) argc;
    pid = ft_atoi(argv[1]);
    kill(SIGINT, pid);
    ft_printf("enviado\n", pid);
}