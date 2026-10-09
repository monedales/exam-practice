#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>    // pipe, fork, dup2, execvp, close
#include <sys/wait.h>  // wait

// evita fechar stdin (0) por engano na primeira iteração
void handle_close_fd(int fd)
{
    if (fd != STDIN_FILENO) // STDIN_FILENO = 0
        close(fd);
}

// LoPiFo DuDuEx FePa Wa
int picoshell(char **cmds[])
{
    int pipefds[2];   // pipe atual
    pid_t pid;
    int i;
    int tmp_fd;       // ponta de leitura do pipe ANTERIOR

    tmp_fd = STDIN_FILENO; // começa como stdin (0), primeiro cmd lê do teclado
    i = 0;

    // Lo - loop pelos comandos
    while (cmds[i])
    {
        // Pi - cria pipe (sempre, mesmo pro último)
        if (pipe(pipefds))
        {
            handle_close_fd(tmp_fd);
            return (1);
        }

        // Fo - fork
        pid = fork();
        if (pid == -1)
        {
            handle_close_fd(tmp_fd);
            close(pipefds[0]);
            close(pipefds[1]);
            return (1);
        }

        if (pid == 0) // filho
        {
            // DuDu - dois dup2:

            // 1 - tem pipe anterior? -> le dele
            if (tmp_fd != STDIN_FILENO)
            {
                dup2(tmp_fd, STDIN_FILENO);
                close(tmp_fd);
            }

            // 2 - tem próximo comando? -> escrevo no pipe
            if (cmds[i + 1])
                dup2(pipefds[1], STDOUT_FILENO);

            // fecha os dois, execvp, exit se falhar
            close(pipefds[0]);
            close(pipefds[1]);
            execvp(cmds[i][0], cmds[i]);
            exit(1);
        }

        // FePa - pai: fecha o que não usa, passa fd[0] pro tmp_fd
        handle_close_fd(tmp_fd);    // fecha pipe anterior, se existia
        close(pipefds[1]);          // fecha ponta de escrita
        tmp_fd = pipefds[0];        // guarda ponta de leitura pra próxima volta
        i++;
    }

    // Wa - espera todos os filhos
    handle_close_fd(tmp_fd);
    while (wait(NULL) != -1)
        ;
    return (0);
}

int main(int argc, char **argv)
{
	int cmds_size = 1;
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "|"))
			cmds_size++;
	}
	char ***cmds = calloc(cmds_size + 1, sizeof(char **));
	if (!cmds)
	{
		dprintf(2, "Malloc error: %m\n");
		return 1;
	}
	cmds[0] = argv + 1;
	int cmds_i = 1;
	for (int i = 1; i < argc; i++)
		if (!strcmp(argv[i], "|"))
		{
			cmds[cmds_i] = argv + i + 1;
			argv[i] = NULL;
			cmds_i++;
		}
	int ret = picoshell(cmds);
	if (ret)
		perror("picoshell");
	free(cmds);
	return ret;
}
