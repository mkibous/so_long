/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:45:47 by mkibous           #+#    #+#             */
/*   Updated: 2023/12/24 08:31:28 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft__strdup(char *s1)
{
	char	*str;
	int		l;
	int		i;

	l = ft__strlen(s1);
	i = 0;
	str = (char *)malloc(l + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft__strjoin(char *s1, char *s2)
{
	int		lt;
	int		j;
	int		i;
	char	*str;

	if (s2 == NULL || s1 == NULL)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	lt = ft__strlen(s1) + ft__strlen(s2);
	str = (char *)malloc(lt + 1);
	if (str == NULL)
		return (free(s1), NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (free(s1), str);
}

char	*ft_read(int fd)
{
	char	*str;
	ssize_t	z;

	str = (char *)malloc(BUFFER_SIZE + 1);
	if (str == NULL)
		return (NULL);
	z = read(fd, str, BUFFER_SIZE);
	if (z == -1)
		return (free(str), NULL);
	str[z] = '\0';
	return (str);
}

char	*ft_readln(int fd)
{
	char	*str;
	char	*ret;

	str = ft_read(fd);
	if (str == NULL)
		return (NULL);
	ret = ft__strjoin(ft__strdup(""), str);
	while (ft_find_nl(str) == BUFFER_SIZE && str[BUFFER_SIZE - 1] != '\n')
	{
		free(str);
		str = NULL;
		str = ft_read(fd);
		if (str == NULL)
			return (NULL);
		ret = ft__strjoin(ret, str);
	}
	free(str);
	return (ret);
}

char	*ft__substr(char *s, int start, int len, int f)
{
	int		l;
	char	*str;
	int		i;

	l = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (start > ft__strlen(s))
		return (ft__strdup(""));
	while (l < len && s[start + l])
		l++;
	str = (char *)malloc(l + 1);
	if (str == NULL)
		return (NULL);
	while (i < l)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	if (f == 1)
		free(s);
	return (str);
}
