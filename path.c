/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:41:29 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/10 17:46:06 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**globalpath(char **env)
{
	int		i;
	char	**paths;
	char	*path;

	i = 0;
	path = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki";
	if (!env)
		return (ft_split(path, ':'));
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (ft_split(path, ':'));
	paths = ft_split(env[i] + 5, ':');
	return (paths);
}

void	cmdpath(char **gpath, char *arg, char **env)
{
	t_pipex	data;
	int		i;

	i = 0;
	if (access(arg, F_OK) == 0)
	{
		if (access(arg, X_OK) == 0)
		{
			data.cmd = splitcommand(arg);
			execve(arg, data.cmd, env);
		}	
		error_msg(errno, arg);
	}
	data.cmd = splitcommand(arg);
	data.path = ft_strjoin(gpath[i], data.cmd[0]);
	while (access(data.path, F_OK) != 0 && gpath[i])
	{
		free(data.path);
		i++;
		data.path = ft_strjoin(gpath[i], data.cmd[0]);
	}
	if (data.path)
		execve(data.path, data.cmd, env);
	cmdnotfound(arg);
}
