/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:11:21 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/10 15:37:12 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		xm;
	int		ym;
	int		tmpx;
	int		c;
	char	**map;
	char	**tmap;
	char	*str;
	char	idl;
	int		b;
	int		len;
	int		j;
	int		mv;
	int		e;
	int		n;
	int		r;
	int		can_ex;
	int		fd;
	int		p;
	int		k;
	int		g;
	int		hide;
	void	*tree;
	void	*coin;
	void	*img;
	void	*idle;
	void	*house;
	void	*en;
	char	*tree_path;
	char	*coin_path;
	char	*idle_path;
	char	*house_path;
	char	*relative_path;
	char	*en_path;
	char	*line;
	char	*map1line;
}				t_vars;

void	ft_free(char **str);
int		get_map(t_vars *vars);
void	ft_display(t_vars *vars);
char	*ft_idlle(t_vars *vars);
char	*ft_hous(t_vars *vars);
char	*ft_bee_path(t_vars *vars);
void	ft_def(t_vars *vars);
void	ft_putimg(t_vars *vars, void *img, int m, int k);
int		m_can_move(char **map2d, int xm, int ym, t_vars *vars);
void	monster_gen(t_vars *vars);
void	ft_mstr_rot(t_vars *vars);
void	m_rotate_move(t_vars *vars);
int		mon_move(t_vars *vars);
void	ft_idlto_s(t_vars *vars);
void	ft_idlto_w(t_vars *vars);
void	ft_idlto_d(t_vars *vars);
void	ft_idlto_a(t_vars *vars);
void	ft_to_win(t_vars *vars);
void	ft_graphiqual_out(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		destroy(t_vars *vars);
int		ft_chaekmap(char *map, t_vars *vars);
int		ft_chek(char *str, t_vars *vars);
int		ft_chek_break(char **map2d);
int		ft_can_u_move_to_all(char **map2d, int x, int y, int *e);
int		chek2d(char **map2d, int *e, t_vars *vars);
void	ft_hide(t_vars *vars);

#endif