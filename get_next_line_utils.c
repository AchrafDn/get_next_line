/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:04:23 by adadoun           #+#    #+#             */
/*   Updated: 2022/11/13 20:47:20 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (1);
	return (0);
}

char	*ft_res(char *s1, char *s2, char *p)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*p;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	p = ft_res(s1, s2, p);
	free(s1);
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	if (start >= slen)
		len = 0;
	else if ((start + len) > slen)
		len = slen - start;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}
