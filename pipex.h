/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:55:12 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/10 17:47:10 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_split{
	unsigned int	k;
	unsigned int	count;
	size_t			len;
	char			c;
}	t_pipes;

typedef struct s_pipex {
	pid_t	pid;
	int		tube[2];
	int		infile;
	int		outfile;
	char	**cmd;
	char	**global;
	char	*path;
}	t_pipex;

char	**splitcommand(char *s);
void	childprocess(char **av, char **env);
char	**globalpath(char **env);
void	cmdpath(char **gpath, char *arg, char **env);
size_t	ft_strlen(char *s);
void	ft_putstr(char *str);
void	error_msg(int errnum, char *arg);
void	error_arg(void);
void	cmdnotfound(char *cmd);
void	parentprocess(char **av, char **env);
char	**ft_split(char *s, char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
void	*ft_calloc(size_t count, size_t size);

#endif
