/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:58:16 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/11 21:33:23 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child(t_pipex data, char **envp, int *fd)
{
	dup2(data.infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(data.infile);
	close_fd(data, fd);
	data.path1 = cmd_file(*data.cmd1, envp);
	cmd_err(data.path1, data, data.outfile);
	if ((execve(data.path1, data.cmd1, NULL)) == -1)
	{
		free(data.path1);
		free_path(data.cmd2);
		free_path(data.cmd1);
		free(data.path2);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		exit(1);
	}
}

void	second_child(t_pipex data, char **envp, int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(data.outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(data.outfile);
	close_fd(data, fd);
	data.path2 = cmd_file(*data.cmd2, envp);
	cmd_err(data.path2, data, data.infile);
	if ((execve(data.path2, data.cmd2, NULL)) == -1)
	{
		free_path(data.cmd2);
		free_path(data.cmd1);
		free(data.path1);
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		exit(1);
	}
}

void	parent_process(t_pipex data, int *fd)
{
	int	i;

	i = 0;
	while (data.cmd1[i])
		free(data.cmd1[i++]);
	free(data.cmd1);
	i = 0;
	while (data.cmd2[i])
		free(data.cmd2[i++]);
	free(data.cmd2);
	close(fd[1]);
	close(fd[0]);
	close(data.infile);
	close(data.outfile);
	close(STDERR_FILENO);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close_fd(data, fd);
	wait(NULL);
	wait(NULL);
}
