/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:33:35 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/10 17:40:18 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len >= ft_strlen(s) - start)
		return (ft_strdup(s + start));
	p = (char *) malloc(len * sizeof(char) + 1);
	if (p == NULL)
		return (NULL);
	while (i < len && start <= ft_strlen(s))
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *) malloc (ft_strlen(s1) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *) malloc (count * size);
	if (p == NULL)
		return (NULL);
	while (i < (count * size))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
