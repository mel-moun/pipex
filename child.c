/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:41:44 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/10 17:44:28 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	childprocess(char **av, char **env)
{
	t_pipex	all;

	if (access(av[1], F_OK | R_OK) == -1)
		error_msg(errno, av[1]);
	all.infile = open(av[1], O_RDONLY);
	if (all.infile == -1)
		error_msg(errno, av[1]);
	dup2(all.infile, 0);
	close(all.infile);
	all.global = globalpath(env);
	cmdpath(all.global, av[2], env);
}
