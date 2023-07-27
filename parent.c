/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:42:10 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/10 17:44:34 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parentprocess(char **av, char **env)
{
	t_pipex	all;

	all.outfile = open(av[4], O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (all.outfile == -1)
		error_msg(errno, av[4]);
	dup2(all.outfile, 1);
	close(all.outfile);
	all.global = globalpath(env);
	cmdpath(all.global, av[3], env);
}
