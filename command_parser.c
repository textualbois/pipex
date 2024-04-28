/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:11:54 by isemin            #+#    #+#             */
/*   Updated: 2024/04/29 00:19:54 by isemin           ###   ########.fr       */
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
		ft_strlcpy(args[1], trimmed_cmd + has_quotes, ft_strlen(trimmed_cmd) - 2 * has_quotes + 1);
		free(trimmed_cmd);
		args[2] = NULL;
	}
	return (args);
	// temp_split = ft_Split(cmd)[0];
	// argv[0] = malloc(ft_trlen(temp_splt[0])) + 1;
	// argv[0] = ft_strlcpy()
	// clear_arr(temp_split);
	// args[1] = this thing;
}

// char	**parse_args(char *cmd)
// {
// 	if (ft_strncmp(cmd, "awk ", 4) && ft_strncmp(cmd, "sed ", 4))
// 		return (ft_split(cmd, ' '));
// 	else
// 		return (parse_awk_sed(cmd));
// }

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
	return (parse_awk_sed(cmd));
}