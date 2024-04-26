# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"

int main()
{
    char *cmd[] = {"which", "cat", NULL};

    if (execve("/bin/which", cmd, NULL) == -1)
        perror(cmd[0]);
    return (0);
}