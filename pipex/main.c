/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:08:49 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/13 14:28:11 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipex	data;
	int		fd[2];

	check_envp(envp);
	if (ac != 5)
		arg_err();
	else
	{
		init(&data, av);
		if (pipe(fd) == -1)
			pipe_err(fd, data);
		data.pid1 = fork();
		pid_err(data.pid1, data.infile);
		if (data.pid1 == 0)
			first_child(data, envp, fd);
		data.pid2 = fork();
		pid_err(data.pid2, data.outfile);
		if (data.pid2 == 0)
			second_child(data, envp, fd);
		parent_process(data, fd);
	}
}
