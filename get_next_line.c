/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:59:06 by mkibous           #+#    #+#             */
/*   Updated: 2023/12/24 08:32:26 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft__strlen(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (0);
	while (c[i])
		i++;
	return (i);
}

int	ft_find_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*ret;
	char		*rd;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX || BUFFER_SIZE > INT_MAX)
		return (NULL);
	rd = ft_readln(fd);
	if (buf == NULL && rd == NULL)
		return (NULL);
	if (buf == NULL)
		buf = ft__strdup("");
	buf = ft__strjoin(buf, rd);
	if (buf == NULL)
		return (NULL);
	free(rd);
	if (ft_find_nl(buf) == 0)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	ret = ft__substr(buf, 0, ft_find_nl(buf), 0);
	if (buf + ft_find_nl(buf))
		buf = ft__substr(buf, ft_find_nl(buf), ft__strlen(buf), 1);
	return (ret);
}
