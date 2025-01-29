#include<signal.h>
#include<stdio.h>

void signal_handler()
{
    printf("dont stop me now!!");
    //signal(SIGINT, SIG_IGN);
}


int main()
{
    while (1)
    {
        signal(SIGINT, signal_handler);
        continue;
    }
    return(0);
}