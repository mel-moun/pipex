/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:39:16 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/10 17:42:55 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	checkout(char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ' && s[i] != '\0')
			i++;
		if (s[i] != ' ' && s[i] != '\0')
			count++;
		while (s[i] != ' ' && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*splitting(char *str, char c)
{
	int		len;
	int		i;
	char	*s;

	len = 0;
	i = 0;
	while (str[len] && str[len] != c)
		len++;
	s = (char *) malloc (len + 1);
	if (!s)
		return (NULL);
	while (i < len)
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*quotes(int *i, char **p, t_pipes *ptr, char *s)
{
	ptr->c = s[*i];
	while (s[*i] == ptr->c && s[*i])
		(*i)++;
	p[ptr->k] = splitting(s + *i, ptr->c);
	*i += ft_strlen(p[ptr->k]);
	while (s[*i] == ptr->c && s[*i])
		(*i)++;
	ptr->k++;
	return (p[ptr->k]);
}

static char	**everything(char *s, char **p, int i, int j)
{
	t_pipes	all;

	all.k = 0;
	all.len = 0;
	all.count = 0;
	while (s[i])
	{
		while (s[i] == ' ' && s[i])
			i++;
		if (s[i] == '\'' || s[i] == '"')
			p[all.k] = quotes(&i, p, &all, s);
		else if (s[i] != '\0')
		{
			j = i - 1;
			while (s[++j] != ' ' && s[j] != '\'' && s[j] != '"' && s[j] != '\0')
				all.len++;
			p[all.k++] = ft_substr(s, i, all.len);
			all.len = 0;
			i = j;
		}
	}
	p[all.k] = NULL;
	return (p);
}

char	**splitcommand(char *s)
{
	char	**p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	p = (char **) ft_calloc ((checkout(s) + 1), sizeof(char *));
	if (p == NULL)
		return (NULL);
	return (everything(s, p, i, j));
}
