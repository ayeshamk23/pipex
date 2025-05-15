/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:20:51 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/13 19:20:34 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	open_infile(char *argv[], t_pipe *pipex)
{
	if (pipex->here_doc)
		here_doc(argv[2], pipex);
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile == -1)
			file_err(pipex->infile);
	}
}

void	open_outfile(char *arg, t_pipe *pipex)
{
	if (pipex->here_doc)
		pipex->outfile = open(arg, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
	{
		pipex->outfile = open(arg, O_CREAT | O_RDWR | O_TRUNC, 0000644);
		if (pipex->outfile == -1)
			file_err(pipex->outfile);
	}
}

void	init(int ac, char *av[], t_pipe *pipex)
{
	pipex->here_doc = 0;
	if (!ft_strncmp("here_doc", av[1], 9))
		pipex->here_doc = 1;
	pipex->cmd_num = ac - 3 - pipex->here_doc;
	pipex->pipe_num = 2 * (pipex->cmd_num - 1);
	open_infile(av, pipex);
	open_outfile(av[ac - 1], pipex);
}
