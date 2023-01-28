/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <adadoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:52:58 by adadoun           #+#    #+#             */
/*   Updated: 2022/11/13 20:34:39 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buf)
{
	char	*new_buf;
	ssize_t	r;

	r = 1;
	new_buf = malloc(BUFFER_SIZE + 1);
	if (!new_buf)
		return (NULL);
	while (r != 0 && !ft_strchr(buf, '\n'))
	{
		r = read(fd, new_buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(new_buf);
			free (buf);
			return (NULL);
		}
		new_buf[r] = '\0';
		buf = ft_strjoin(buf, new_buf);
	}
	free (new_buf);
	return (buf);
}	

char	*ft_first(char	*buf)
{
	size_t	i;
	char	*b;

	i = 0;
	if (!ft_strlen(buf))
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	b = ft_substr(buf, 0, i);
	if (!b)
		return (NULL);
	return (b);
}

char	*ft_second(char *buf)
{
	size_t	i;
	char	*b;
	size_t	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	if (ft_strlen(buf) == i)
	{
		free (buf);
		return (NULL);
	}
	b = malloc(ft_strlen(buf) - i + 1);
	if (!b)
	{
		free (buf);
		return (NULL);
	}
	while (buf[i])
		b[j++] = buf[i++];
	free (buf);
	return (b[j] = '\0', b);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*bef;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_read(fd, buf);
	if (!buf)
		return (NULL);
	bef = ft_first(buf);
	buf = ft_second(buf);
	return (bef);
}
