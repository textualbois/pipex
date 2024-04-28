/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:11:54 by isemin            #+#    #+#             */
/*   Updated: 2024/04/27 21:49:34 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static char	**parse_local_command(char *cmd)
// {

// }

static char	**parse_awk_sed(char *cmd)
{
	char	**args;
	int		has_quotes;
	char	*trimmed_cmd;

	trimmed_cmd = ft_strtrim(cmd + 3, " ");
	remove_chars(trimmed_cmd, "\\");
	has_quotes = (trimmed_cmd[0] == '\'' || trimmed_cmd[0] == '"');
	args = (char **)malloc(sizeof(char **) * 3);
	if (args != NULL)
	{
		args[0] = malloc(4);
		ft_strlcpy(args[0], cmd, 4);
		args[1] = malloc(ft_strlen(trimmed_cmd) - 2 * has_quotes + 1);
		ft_strlcpy(args[1], trimmed_cmd + has_quotes, \
					ft_strlen(trimmed_cmd) - 2 * has_quotes + 1);
		free(trimmed_cmd);
		args[2] = NULL;
	}
	return (args);
}

char	**parse_args(char *cmd)
{

	if (ft_str_end_wit(cmd, ".sh"))
	{
		remove_chars(cmd, "\\");
		return (ft_split(cmd, '\0'));
	}
	else if (ft_strncmp(cmd, "awk ", 4) && ft_strncmp(cmd, "sed ", 4))
	{
		remove_chars(cmd, "\\");
		return (ft_split(cmd, ' '));
	}
	// else if (ft_strncmp(cmd, "./", 2) == 0)
	// 	return (parse_local_command(cmd));
	else
		return (parse_awk_sed(cmd));
}






	// debug("current command", "debug.log");
	// debug(cmd, "debug.log");
	// debug("\n", "debug.log");
	// write(2,"Command: <", ft_strlen("Command: <"));
	// write(2, cmd, ft_strlen(cmd));
	// write(2, ">\n", 2);