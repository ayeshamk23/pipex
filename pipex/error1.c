/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:04:55 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/13 20:08:14 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	arg_err(void)
{
	write(2, "invalid arguments\n", 19);
	close(STDERR_FILENO);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	exit(0);
}

void	pipe_err(int *pipe_fd, t_pipex data)
{
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	close_fd(data, pipe_fd);
	exit(1);
}

void	check_envp(char **envp)
{
	if (!envp && envp[0] == NULL)
	{
		write(2, "no envp\n", 9);
		exit(0);
	}
}

void	close_fd(t_pipex data, int *fd)
{
	if (fd[1] == -1)
		close_err();
	if (fd[0] == -1)
		close_err();
	if (data.outfile == -1)
		close_err();
	if (data.outfile == -1)
		close_err();
}
