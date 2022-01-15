#include "minitalk.h"

void ft_putchar(int c)
{
    write(1, &c, 1);
}

void sig_handler(int sig, siginfo_t *t,void *b)
{
    static int var;
    static int result;

    if (sig == SIGUSR1)
    {
        result *= 2;
        result = result + 1;
        var++;
        if (var == 8)
        {
            if (result == 0)
            {
                kill(t->si_pid,SIGUSR1);
            }
            else
                ft_putchar(result);
            result = 0;
            var = 0;
        }
    }
    else
    {
        result *= 2;
        result = result + 0;
        var++;
        if (var == 8)
        {
            if (result == 0)
            {
                kill(t->si_pid,SIGUSR1);
            }
            else
                ft_putchar(result);
            result = 0;
            var = 0;
        }
    }
}

int main(void)
{
    int pid;

    pid = getpid();
    printf("%d\n",pid);
    struct sigaction sig_struct;
    sig_struct.sa_sigaction = &sig_handler;
    sig_struct.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig_struct, NULL);
    sigaction(SIGUSR2, &sig_struct, NULL);
    while (1)
    {
        pause();
    }
}