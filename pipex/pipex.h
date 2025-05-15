/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:29:58 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/13 17:49:27 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
	int		infile;
	int		outfile;
}			t_pipex;

void		pid_err(int pid, int files);
void		file_err(int files);
void		close_err(void);
void		cmd_err(char *path_cmd, t_pipex pipex, int file);
void		arg_err(void);
void		pipe_err(int *pipe_fd, t_pipex data);
void		check_envp(char **envp);
void		close_fd(t_pipex data, int *fd);

void		init(t_pipex *pipex, char **av);
char		**ft_cmd(char *s);
char		*cmd_file(char *cmd, char **paths);
void		free_path(char **path);
char		**find_paths_and_split(char **envp);
char		**paths_add_slash(char **envp);
char		*given_path(char *cmd);

void		first_child(t_pipex data, char **envp, int *fd);
void		second_child(t_pipex data, char **envp, int *fd);
void		parent_process(t_pipex data, int *fd);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif