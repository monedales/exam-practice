#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int ft_popen(const char *file, char *const argv[], char type)
{
    int pid;
    int fd[2];

    if (!file || !argv || (type != 'r' && type != 'w'))
		return -1;
	if (pipe(fd) < 0)
		return -1;
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return -1;
	}
    if (pid == 0)
    {
        if (type == 'w')
        {
            dup2(fd[0], 0);
            close(fd[0]);
            close(fd[1]);
        }
        else if (type == 'r')
        {
            dup2(fd[1], 1);
            close(fd[0]);
            close(fd[1]);
        }
        execvp(file, argv);
        exit(1);
    }
    if (type == 'w')
    {
        close(fd[0]);
        return (fd[1]);
    }
    else if (type == 'r')
    {
        close(fd[1]);
        return (fd[0]);
    }
    return (-1);
}

int main(void)
{
    int     fd;
    char    buf[4096];
    int     n;

    // Teste 1: modo 'r' - ler output do echo
    printf("=== Teste 1: echo com 'r' ===\n");
    fd = ft_popen("echo", (char *const []){"echo", "hello from pipe!", NULL}, 'r');
    n = read(fd, buf, sizeof(buf) - 1);
    buf[n] = '\0';
    printf("Recebi: %s", buf);
    close(fd);

    // Teste 2: modo 'r' - ler output do ls
    printf("\n=== Teste 2: ls com 'r' ===\n");
    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
    n = read(fd, buf, sizeof(buf) - 1);
    buf[n] = '\0';
    printf("%s", buf);
    close(fd);

    // Teste 3: modo 'w' - escrever pro cat
    printf("\n=== Teste 3: cat com 'w' ===\n");
    fd = ft_popen("cat", (char *const []){"cat", NULL}, 'w');
    write(fd, "mandei isso pelo pipe!\n", 22);
    close(fd);

    // Teste 4: erro - type invalido
    printf("\n=== Teste 4: type invalido ===\n");
    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'x');
    printf("Retorno: %d\n", fd);

    return (0);
}
