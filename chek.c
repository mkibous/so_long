/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:07:36 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/11 09:37:09 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_chaekmap(char *map, t_vars *vars)
{
	int	i;

	i = ft_strlen(map);
	while (i >= 0)
	{
		if (map[i] == '.')
		{
			if (ft_strncmp((map + i), ".ber", 5) == 0)
			{
				vars->fd = open(map, O_RDONLY);
				if (vars->fd == -1)
				{
					ft_printf("Error\n open return -1");
					exit(1);
				}
				return (1);
			}
		}
		i--;
	}
	return (0);
}

int	ft_chek(char *str, t_vars *vars)
{
	int		e;
	int		i;
	char	*ret;

	e = 0;
	i = 0;
	ret = ft_strtrim(str, "01ECP\n");
	if (ret == NULL)
		return (0);
	vars->c = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			vars->p++;
		if (str[i] == 'E')
			e++;
		if (str[i] == 'C')
			vars->c += 1;
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (free(ret), 0);
		i++;
	}
	if (ret[0] != '\0' || vars->p != 1 || e != 1 || vars->c < 1)
		return (free(ret), 0);
	return (free(ret), 1);
}

int	ft_chek_break(char **map2d)
{
	int	x;
	int	y;

	y = 0;
	while (map2d[y])
	{
		x = 0;
		while (map2d[y][x])
		{
			if (map2d[y][x] == 'C')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_can_u_move_to_all(char **map2d, int x, int y, int *e)
{
	if (map2d[y + 1][x] == 'E' || map2d[y - 1][x] == 'E' ||
		map2d[y][x + 1] == 'E' || map2d[y][x - 1] == 'E')
		*e = 1;
	if (map2d[y + 1][x] == '0' || map2d[y + 1][x] == 'C')
	{
		map2d[y + 1][x] = 'P';
		ft_can_u_move_to_all(map2d, x, y + 1, e);
	}
	if (map2d[y - 1][x] == '0' || map2d[y - 1][x] == 'C')
	{
		map2d[y - 1][x] = 'P';
		ft_can_u_move_to_all(map2d, x, y - 1, e);
	}
	if (map2d[y][x + 1] == '0' || map2d[y][x + 1] == 'C')
	{
		map2d[y][x + 1] = 'P';
		ft_can_u_move_to_all(map2d, x + 1, y, e);
	}
	if (map2d[y][x - 1] == '0' || map2d[y][x - 1] == 'C')
	{
		map2d[y][x - 1] = 'P';
		ft_can_u_move_to_all(map2d, x - 1, y, e);
	}
	return (0);
}

int	chek2d(char **map2d, int *e, t_vars *vars)
{
	int	x;

	while (map2d[vars->j])
	{
		x = 0;
		while (map2d[vars->j][x])
		{
			if (((vars->j == 0) || (x == 0) || (x == vars->n - 1)
					|| (map2d[vars->j + 1] == NULL))
				&& map2d[vars->j][x] != '1')
				break ;
			if (vars->map[vars->j][x] == 'P')
			{
				vars->x = x;
				vars->y = vars->j;
				ft_can_u_move_to_all(map2d, x, vars->j, e);
			}
			x++;
		}
		if (x != vars->n)
			return (0);
		vars->j++;
	}
	return (1);
}
