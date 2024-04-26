/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 04:04:00 by isemin            #+#    #+#             */
/*   Updated: 2024/01/29 15:43:11 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		perror("too few args");
		return (EXIT_FAILURE);
	}
	if (ft_strlen(argv[1]) == 8 && ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
		{
			perror("too few args");
			return (EXIT_FAILURE);
		}
		else
			return (here_doc(argc, argv, get_path(envp), envp));
	}
	//else if (access(argv[1], R_OK) != 0)
	//{
	//	perror(argv[1]);
		//return (EXIT_FAILURE);
	//}
	//else
	return (execute_args(argc, argv, get_path(envp), envp));
	//return (EXIT_SUCCESS);
}
