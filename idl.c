/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:14:30 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/09 11:23:14 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_idlto_s(t_vars *vars)
{
	vars->idl = 'S';
	if ((vars->map[vars->y + 1][vars->x] != 'E'
		&& vars->map[vars->y + 1][vars->x] != '1'))
	{
		vars->map[vars->y][vars->x] = '0';
		vars->y += 1;
		if (vars->map[vars->y][vars->x] == 'C')
			vars->c -= 1;
		vars->map[vars->y][vars->x] = 'P';
		vars->mv++;
	}
	else if (vars->map[vars->y + 1][vars->x] == 'E')
		vars->e = 1;
}

void	ft_idlto_w(t_vars *vars)
{
	vars->idl = 'W';
	if (vars->map[vars->y - 1][vars->x] != 'E' &&
		vars->map[vars->y - 1][vars->x] != '1')
	{
		vars->map[vars->y][vars->x] = '0';
		vars->y--;
		if (vars->map[vars->y][vars->x] == 'C')
			vars->c -= 1;
		vars->map[vars->y][vars->x] = 'P';
		vars->mv++;
	}
	else if (vars->map[vars->y - 1][vars->x] == 'E')
		vars->e = 1;
}

void	ft_idlto_d(t_vars *vars)
{
	vars->idl = 'D';
	if ((vars->map[vars->y][vars->x + 1] != 'E'
		&& vars->map[vars->y][vars->x + 1] != '1'))
	{
		vars->map[vars->y][vars->x] = '0';
		vars->x++;
		if (vars->map[vars->y][vars->x] == 'C')
			vars->c -= 1;
		vars->map[vars->y][vars->x] = 'P';
		vars->mv++;
	}
	else if (vars->map[vars->y][vars->x + 1] == 'E')
		vars->e = 1;
}

void	ft_idlto_a(t_vars *vars)
{
	vars->idl = 'A';
	if ((vars->map[vars->y][vars->x - 1] != 'E'
		&& vars->map[vars->y][vars->x - 1] != '1'))
	{
		vars->map[vars->y][vars->x] = '0';
		vars->x--;
		if (vars->map[vars->y][vars->x] == 'C')
			vars->c -= 1;
		vars->map[vars->y][vars->x] = 'P';
		vars->mv++;
	}
	else if (vars->map[vars->y][vars->x - 1] == 'E')
		vars->e = 1;
}

void	ft_hide(t_vars *vars)
{
	vars->map[vars->y][vars->x] = '0';
	vars->hide = 1;
}
