/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: israeloriente <israeloriente@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:33:27 by israelorien       #+#    #+#             */
/*   Updated: 2022/12/03 20:37:29 by israelorien      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

	void	*mlx;
	void	*mlx_win;

int	close(int keycode, void *mlx, void *win)
{
	mlx_destroy_window(mlx, win);
	return (0);
}

int	key_win3(int key,void *p)
{
  if (key==0xFF1B)
    mlx_destroy_window(mlx, mlx_win);
}

int	main(int argc, char **argv)
{
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
	mlx_key_hook(mlx_win, key_win3, 0);
	mlx_loop(mlx);
}

//Ola bem vindo ao meu born2beroot
// EXAMPLE 42 DOCS
// #include <mlx.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
// 	mlx_loop(vars.mlx);
// }
