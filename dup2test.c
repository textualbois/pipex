# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

int main()
{
    int fd[2];
    pipe(fd);
    char *cmd[] = {"wc", "-l", NULL};
    dup2(fd[0], STDIN_FILENO); //redirect stdin to pipe // like emty file because write end is empty
    close(fd[1]);              //close the unused write end of the pipe
   // close(STDOUT_FILENO);
    execve("/usr/bin/wc", cmd, NULL);
    return (0);
}