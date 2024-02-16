/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:11:21 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/11 09:38:16 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_idlle(t_vars *vars)
{
	if (vars->idl == 'D')
		return ("./allxpm/idle-r.xpm");
	else if (vars->idl == 'W')
		return ("./allxpm/idleup.xpm");
	else if (vars->idl == 'A')
		return ("./allxpm/idleleft.xpm");
	else
		return ("./allxpm/idle-down.xpm");
}

char	*ft_hous(t_vars *vars)
{
	if (vars->c == 0)
		return ("./allxpm/house_open.xpm");
	else
		return ("./allxpm/house.xpm");
}

char	*ft_bee_path(t_vars *vars)
{
	if (vars->tmpx == 3 || vars->tmpx == 0)
		return ("./allxpm/bee_r.xpm");
	else
		return ("./allxpm/bee_l.xpm");
}

void	ft_def(t_vars *vars)
{
	int	l;
	int	w;

	l = 50;
	w = 55;
	vars->tree_path = "./allxpm/tree.xpm";
	vars->coin_path = "./allxpm/Food.xpm";
	vars->idle_path = ft_idlle(vars);
	vars->house_path = ft_hous(vars);
	vars->relative_path = "./allxpm/New-Project.xpm";
	vars->en_path = ft_bee_path(vars);
	vars->tree = mlx_xpm_file_to_image(vars->mlx, vars->tree_path, &l, &w);
	vars->coin = mlx_xpm_file_to_image(vars->mlx, vars->coin_path, &l, &w);
	vars->idle = mlx_xpm_file_to_image(vars->mlx, vars->idle_path, &l, &w);
	vars->house = mlx_xpm_file_to_image(vars->mlx, vars->house_path, &l, &w);
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->relative_path, &l, &w);
	vars->en = mlx_xpm_file_to_image(vars->mlx, vars->en_path, &l, &w);
	if (vars->tree == 0 || vars->coin == 0 || vars->idle == 0
		|| vars->house == 0 || vars->img == 0 || vars->en == 0)
	{
		ft_printf("Error\nproblem on xpm files");
		exit(1);
	}
}

void	ft_putimg(t_vars *vars, void *img, int m, int k)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, m * 50, k * 55);
}
