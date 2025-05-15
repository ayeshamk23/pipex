/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:07:06 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/13 19:20:22 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_pipes(t_pipe *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".heredoc_file");
	free(pipex->pipe);
	error_message("err: environment", 1);
}

void	create_pipes(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_num - 1)
		if (pipe(pipex->pipe + 2 * i++) < 0)
			parent_free(pipex);
}

void	close_pipes(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_num))
		close(pipex->pipe[i++]);
}
