/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:06:53 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/13 19:20:39 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char *arg, t_pipe *pipex)
{
	int		file;
	char	*temp_read;

	file = open(".heredoc_file", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	error_message("err: here_doc", file < 0);
	while (1)
	{
		write(1, "input: heredoc> ", 17);
		temp_read = get_next_line(0);
		if (!temp_read)
			exit(1);
		if (!ft_strncmp(arg, temp_read, ft_strlen(arg)))
			break ;
		write(file, temp_read, ft_strlen(temp_read));
		write(file, "\n", 1);
		free(temp_read);
	}
	free(temp_read);
	close(file);
	pipex->infile = open(".heredoc_file", O_RDONLY);
	if (pipex->infile < 0)
		unlink(".heredoc_file");
	error_message("err: here_doc", pipex->infile < 0);
}

int	main(int ac, char *av[], char *envp[])
{
	t_pipe	pipex;

	if (ac < 5)
	{
		arg_err();
	}
	init(ac, av, &pipex);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_num);
	error_message("pipe", !pipex.pipe);
	pipex.envp_path = get_path(envp);
	pipex.cmd_paths = ft_split(pipex.envp_path, ':');
	if (!pipex.cmd_paths)
		free_pipes(&pipex);
	create_pipes(&pipex);
	pipex.pid = -1;
	while (++(pipex.pid) < pipex.cmd_num)
		child_process(pipex, av, envp);
	close_pipes(&pipex);
	waitpid(-1, NULL, 0);
	parent_free(&pipex);
	return (0);
}
