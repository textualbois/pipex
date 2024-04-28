/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:22:35 by isemin            #+#    #+#             */
/*   Updated: 2024/04/28 19:13:59 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	set_fds(int fd_array[3][2], int cmd_num, int cmd_num_lim, char **argv)
{
	if (pipe(fd_array[(cmd_num % 2) + 1]) == -1)
		return (perror_return(-1, "pipe error"));
	if (cmd_num == 1)
	{
		fd_array[0][READ_END] = open(argv[1], O_RDONLY);
		if (fd_array[0][READ_END] == -1)
			return (perror_return(-1, argv[1]));
		if (dup2(fd_array[0][READ_END], STDIN_FILENO) == -1)
			return (perror_return(-1, argv[1]));
	}
	else if (dup2(fd_array[2 - (cmd_num % 2)][READ_END], STDIN_FILENO) == -1)
		return (perror_return(-1, "dup2"));
	if (cmd_num + 1 < cmd_num_lim)
	{
		if (dup2(fd_array[(cmd_num % 2) + 1][WRITE_END], STDOUT_FILENO) == -1)
			return (perror_return(-1, "dup2"));
	}
	else
	{
		fd_array[0][WRITE_END] = open(argv[cmd_num_lim + 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd_array[0][WRITE_END] == -1)
			return (perror_return(-1, argv[cmd_num_lim + 1]));
		 else if (dup2(fd_array[0][WRITE_END], STDOUT_FILENO) == -1)
		 	return (perror_return(-1, argv[cmd_num_lim + 1]));
	}
	return (1);
}

int	set_fds_h_doc(int fd_array[3][2], int cmd_num, int cmd_num_lim, char **argv)
{
	if (pipe(fd_array[(cmd_num % 2) + 1]) == -1)
		return (perror_return(-1, "pipe error"));
	if (cmd_num == 1)
	{
		fd_array[0][READ_END] = open(argv[1], O_RDONLY);
		if (fd_array[0][READ_END] == -1)
			return (perror_return(-1, argv[1]));
		if (dup2(fd_array[0][READ_END], STDIN_FILENO) == -1)
			return (perror_return(-1, argv[1]));
	}
	else if (dup2(fd_array[2 - (cmd_num % 2)][READ_END], STDIN_FILENO) == -1)
		return (perror_return(-1, "dup2"));
	if (cmd_num + 1 < cmd_num_lim)
	{
		if (dup2(fd_array[(cmd_num % 2) + 1][WRITE_END], STDOUT_FILENO) == -1)
			return (perror_return(-1, "dup2"));
	}
	else
	{
		fd_array[0][WRITE_END] = open(argv[cmd_num_lim + 1], O_WRONLY | O_CREAT, 0644);
		if (fd_array[0][WRITE_END] == -1)
			return (perror_return(-1, argv[cmd_num_lim + 1]));
		 else if (dup2(fd_array[0][WRITE_END], STDOUT_FILENO) == -1)
		 	return (perror_return(-1, argv[cmd_num_lim + 1]));
	}
	return (1);
}

void	close_fds_parent(int fd_array[3][2], int cmd_num, int cmd_num_lim)
{
	if (cmd_num + 1 < cmd_num_lim)
		close(fd_array[(cmd_num % 2) + 1][WRITE_END]);
	else
		close(fd_array[0][WRITE_END]);
}

void	close_all(int fd_array[3][2])
{
	int	i;

	i = 2;
	while (i >= 0)
	{
		close(fd_array[i][WRITE_END]);
		close(fd_array[i][READ_END]);
		i--;
	}
}
