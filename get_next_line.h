/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:36:47 by mkibous           #+#    #+#             */
/*   Updated: 2023/12/24 08:32:49 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_readln(int fd);
char	*ft__strjoin(char *s1, char *s2);
int		ft_find_nl(char *s);
int		ft__strlen(char *c);
char	*ft__strdup(char *s1);
char	*ft__substr(char *s, int start, int len, int f);
char	*ft_read(int fd);

#endif
