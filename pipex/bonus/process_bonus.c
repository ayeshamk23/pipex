/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:06:58 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/13 19:20:55 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	do_dup(t_pipe *pipex)
{
	if (pipex->pid == 0)
	{
		dup2(pipex->infile, 0);
		dup2(pipex->pipe[1], 1);
	}
	else if (pipex->pid == pipex->cmd_num - 1)
	{
		dup2(pipex->pipe[2 * pipex->pid - 2], 0);
		dup2(pipex->outfile, 1);
	}
	else
	{
		dup2(pipex->pipe[2 * pipex->pid - 2], 0);
		dup2(pipex->pipe[2 * pipex->pid + 1], 1);
	}
}

void	parent_free(t_pipe *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".heredoc_file");
	while (pipex->cmd_paths[i])
		free(pipex->cmd_paths[i++]);
	free(pipex->cmd_paths);
	free(pipex->pipe);
}

void	child_free(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
		free(pipex->cmd_args[i++]);
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	child_process(t_pipe pipex, char **av, char **envp)
{
	pipex.p = fork();
	if (pipex.p)
		return ;
	do_dup(&pipex);
	close_pipes(&pipex);
	pipex.cmd_args = ft_split(av[2 + pipex.here_doc + pipex.pid], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		pipe_error_message(pipex.cmd_args[0]);
		child_free(&pipex);
		parent_free(&pipex);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
	child_free(&pipex);
	parent_free(&pipex);
	perror(strerror(errno));
	exit(1);
}
