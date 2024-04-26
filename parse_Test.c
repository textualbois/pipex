# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft/libft.h"


int main(int argc, char **argv)
{
    // char *awk1_good = 'awk "{count++} END {print count}"';
    // char *awk1_good = 'awk '"{count++} END {print count}"'';
    // char *awk3_bad = 'awk "'{count++} END {print count}'"';
    // char *awk4_good = 'awk '{count++} END {print count}'';
    int i = 0;
	char **temp_split;
	int s_p = 0;

    while (i < argc)
    {
        printf("%d|%s|\n", i, argv[i]);
		if (i == 2)
		{
			temp_split = ft_split(argv[i], ' ');
			while (temp_split[s_p] != NULL)
			{
				printf("%d - %d|%s|\n", i, s_p, temp_split[s_p]);
				s_p++;
			}
		}
        i++;
    }
}
