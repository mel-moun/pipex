/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-moun <mel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:27:28 by mel-moun          #+#    #+#             */
/*   Updated: 2023/03/10 17:40:07 by mel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	numwords(char *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	**splitpath(char *s, char **p, char c, int i)
{
	int		j;
	int		k;
	size_t	len;

	j = 0;
	k = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i - 1;
		while (s[++j] != c && s[j] != '\0')
			len++;
		if (s[i] == '\0')
		{
			p[k] = 0;
			break ;
		}
		p[k++] = ft_substr(s, i, len);
		len = 0;
		i = j;
	}
	return (p);
}

char	**ft_split(char *s, char c)
{
	char	**p;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	p = (char **) ft_calloc ((numwords(s, c) + 1), sizeof(char *));
	if (p == NULL)
		return (NULL);
	return (splitpath(s, p, c, i));
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	if (!s1 || !s2)
		return (0);
	while (i < n && (ss2[i] != '\0' || ss1[i] != '\0'))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*p;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	p = (char *) malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen (s2)) + 1);
	if (p == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i++] = '/';
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
