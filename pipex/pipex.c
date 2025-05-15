/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:58:16 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/10 14:29:43 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_pipex *pipex, char **av)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile == -1)
		file_err(pipex->infile);
	pipex->cmd1 = ft_cmd(av[2]);
	pipex->cmd2 = ft_cmd(av[3]);
	pipex->outfile = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex->outfile == -1)
		file_err(pipex->outfile);
}

char	**ft_cmd(char *s)
{
	char	**str;

	if (!s)
		return (NULL);
	str = ft_split(s, ' ');
	if (!str)
		free_path(str);
	return (str);
}
