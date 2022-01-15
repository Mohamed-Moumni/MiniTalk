#include "minitalk.h"

void sig_handler(int sig, siginfo_t *t,void *b)
{
    if (sig == SIGUSR1)
    {
        write(1, "The Signal Is Recieved\n",24);
    }
}
void bits(int pid, char c)
{

    unsigned int    one;
    unsigned int    and;
    unsigned int    j;

    j = 0;
    one = 0b10000000;
    while (j < 8)
    {
        and = c&one;
        if (and == 0)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        c = c<<1;
        j++;
        usleep (300);
    }
}
int main(int ac, char **av)
{
    int pid;
    int i;

    if (ac < 3)
    {
        write(1, "There is An Error Here\n",23);
    }
    else
    {
        struct sigaction sig_struct;
        sig_struct.sa_sigaction = &sig_handler;
        sig_struct.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &sig_struct, NULL);
        pid = ft_atoi(av[1]);
        i = 0;
        while (av[2][i])
        {
            bits(pid,av[2][i]);
            i++;
        }
        bits(pid, av[2][i]);
    }
}