/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:38:04 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/12 21:03:00 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid_err(int pid, int files)
{
	if (pid == -1)
	{
		close (files);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
}

void	file_err(int files)
{
	if (files == -1)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		exit(0);
	}
}

void	close_err(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	exit(1);
}

void	cmd_err(char *path_cmd, t_pipex pipex, int file)
{
	if (!path_cmd)
	{
		write(2, "command not found\n", 19);
		free(path_cmd);
		free_path(pipex.cmd1);
		free_path(pipex.cmd2);
		close(file);
		close(STDERR_FILENO);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		exit(1);
	}
}
