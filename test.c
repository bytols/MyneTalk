#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void signal_handler(int signum)
{
    (void) signum;
    printf("dont stop me now!!\n");
    //signal(SIGINT, SIG_IGN);
}


int main()
{
    signal(SIGINT, signal_handler);
    while (1)
    {
        sleep(2);
    }
    return(0);
}