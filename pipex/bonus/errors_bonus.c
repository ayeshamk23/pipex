/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:07:12 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/13 19:08:41 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	arg_err(void)
{
	write(2, "invalid arguments\n", 19);
	exit(0);
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

int	message(char *message)
{
	write(2, message, ft_strlen(message));
	return (1);
}

void	error_message(char *message, int state)
{
	if (!state)
		return ;
	perror(message);
	exit(1);
}

void	pipe_error_message(char *message)
{
	write(2, "command not found: ", 19);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}
