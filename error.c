/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:42:52 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/10 17:19:00 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, ": ", 2);
}

void	error_msg(int errnum, char *arg)
{
	write(2, "pipex: ", 7);
	ft_putstr(arg);
	write(2, strerror(errnum), ft_strlen(strerror(errnum)));
	write(2, "\n", 1);
	if (errnum == 13)
		exit(126);
	else if (errnum == 2)
		exit(127);
	exit(1);
}

void	error_arg(void)
{
	write (2, "5 arguments are requirred\n", 27);
	exit (1);
}

void	cmdnotfound(char *cmd)
{
	write(2, "pipex: ", 7);
	ft_putstr(cmd);
	write(2, "command not found\n", 18);
	exit(127);
}
