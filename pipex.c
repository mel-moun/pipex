/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:40:38 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/10 17:50:40 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	all;
	int		status;

	if (ac != 5)
		error_arg();
	if (pipe(all.tube) == -1)
		error_msg(errno, "pipe: ");
	all.pid = fork();
	if (all.pid == -1)
		error_msg(errno, "fork: ");
	if (all.pid == 0)
	{
		close(all.tube[0]);
		dup2(all.tube[1], 1);
		close(all.tube[1]);
		childprocess(av, env);
	}
	else
	{
		wait(&status);
		close(all.tube[1]);
		dup2(all.tube[0], 0);
		close(all.tube[0]);
		parentprocess(av, env);
	}
}
