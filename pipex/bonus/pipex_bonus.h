/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:08:51 by aymohamm          #+#    #+#             */
/*   Updated: 2024/02/13 19:22:52 by aymohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipe
{
	pid_t	p;
	int		*pipe;
	int		pipe_num;
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		cmd_num;
	char	*envp_path;
	int		here_doc;
	int		pid;

}			t_pipe;

void		arg_err(void);
void		pipe_error_message(char *message);
int			message(char *message);
void		file_err(int files);
void		error_message(char *message, int state);

void		free_pipes(t_pipe *pipex);
void		parent_free(t_pipe *pipex);
void		child_free(t_pipe *pipex);

char		*get_path(char **envp);
char		*get_cmd(char **paths, char *cmd);

void		init(int ac, char *av[], t_pipe *pipex);
void		open_infile(char *argv[], t_pipe *pipex);
void		open_outfile(char *arg, t_pipe *pipex);

void		do_dup(t_pipe *pipex);
void		here_doc(char *arg, t_pipe *pipex);
void		create_pipes(t_pipe *pipex);
void		close_pipes(t_pipe *pipex);
void		child_process(t_pipe pipex, char **argv, char **envp);

void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_strdup_gnl(const char *s1);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char		*make_line(char **str, int chars, char **buf);
char		*get_next_line(int fd);

#endif
