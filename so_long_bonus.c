/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:10:27 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/11 09:38:42 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

int	get_map(t_vars *vars)
{
	vars->map1line = ft__strdup("");
	if (vars->map1line == NULL)
		return (0);
	vars->line = get_next_line(vars->fd);
	while (vars->line)
	{
		vars->map1line = ft__strjoin(vars->map1line, vars->line);
		if (vars->map1line == NULL)
			return (close(vars->fd), 0);
		free(vars->line);
		vars->line = get_next_line(vars->fd);
	}
	close(vars->fd);
	vars->map = ft_split(vars->map1line, '\n');
	if (vars->map == NULL)
		return (free(vars->map1line), 0);
	vars->tmap = ft_split(vars->map1line, '\n');
	if (vars->tmap == NULL)
	{
		ft_free(vars->map);
		return (free(vars->map1line), 0);
	}
	return (1);
}

void	ft_display(t_vars *vars)
{
	monster_gen(vars);
	vars->mlx = mlx_init();
	if (vars->mlx == 0)
		exit(1);
	vars->win = mlx_new_window(vars->mlx, vars->n * 50, (vars->j) * 55, "MEHD");
	if (vars->win == 0)
		exit(1);
	mlx_hook(vars->win, 17, 0, destroy, vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	ft_graphiqual_out(vars);
	mlx_loop_hook(vars->mlx, mon_move, vars);
	mlx_loop(vars->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	ft_memset(&vars, 0, sizeof(vars));
	if (argc != 2 || ft_chaekmap(argv[1], &vars) == 0)
	{
		ft_printf("Error\n problem on args");
		exit(1);
	}
	if (get_map(&vars) == 0)
	{
		ft_printf("Error\n on reading file");
		exit(1);
	}
	vars.n = ft_strlen(vars.map[0]);
	vars.r = chek2d(vars.tmap, &vars.can_ex, &vars);
	if (ft_chek(vars.map1line, &vars) == 0 || ft_chek_break(vars.tmap) == 0
		|| vars.can_ex == 0 || vars.r == 0 || vars.n > 51 || (vars.j) > 25)
	{
		ft_printf("Error\n check the map");
		free(vars.map1line);
		ft_free(vars.map);
		ft_free(vars.tmap);
		exit(1);
	}
	ft_display(&vars);
}
