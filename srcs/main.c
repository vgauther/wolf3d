/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgauther <vgauther@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:19:01 by vgauther          #+#    #+#             */
/*   Updated: 2019/10/14 14:30:09 by vgauther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		**fill_map_struct(t_var var)
{
	int		**map;
	int		x_x2_y[3];

	x_x2_y[2] = -1;
	if (!(map = malloc(sizeof(int *) * var.y_max)))
		ft_error(2);
	while (++x_x2_y[2] != var.y_max)
	{
		if (!(map[x_x2_y[2]] = malloc(sizeof(int) * var.x_max)))
			ft_error(2);
	}
	x_x2_y[2] = 0;
	while (x_x2_y[2] != var.y_max)
	{
		x_x2_y[0] = 0;
		x_x2_y[1] = 0;
		while (x_x2_y[0] <= (var.x_max * 2))
		{
			map[x_x2_y[2]][x_x2_y[1]] = var.map[x_x2_y[2]][x_x2_y[0]] - 48;
			x_x2_y[1] += 1;
			x_x2_y[0] += 2;
		}
		x_x2_y[2]++;
	}
	return (map);
}

void	player_data_set(t_player *player, t_var *var)
{
	int x;
	int y;

	y = 0;
	while (y != var->y_max)
	{
		x = 0;
		while (x != var->x_max)
		{
			if (var->m[y][x] == 7)
			{
				var->spawn.x = BLOCK_SIZE * x + BLOCK_SIZE / 2;
				var->spawn.y = BLOCK_SIZE * y + BLOCK_SIZE / 2;
				player->pos.x = var->spawn.x;
				player->pos.y = var->spawn.y;
			}
			x++;
		}
		y++;
	}
	player->height = BLOCK_SIZE / 2;
	player->fov = 60;
	player->angle = 210;
}

void	ft_init_sdl(t_var *var)
{
	var->sdl.window = NULL;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
		return ;
	var->sdl.window = SDL_CreateWindow("WOLFCRAFT", SDL_WINDOWPOS_CENTERED, \
			SDL_WINDOWPOS_CENTERED, SIZE_X, SIZE_Y, 0);
	var->sdl.render = SDL_CreateRenderer(var->sdl.window, -1, 0);
	if (!var->sdl.window || !var->sdl.render)
		return ;
}

void	init_key_move(t_var *var)
{
	var->key.left = SDLK_a;
	var->key.right = SDLK_d;
	var->key.forw = SDLK_w;
	var->key.back = SDLK_s;
	var->select_key = 0;
	var->key_id[0] = 3;
	var->key_id[1] = 0;
	var->key_id[2] = 22;
	var->key_id[3] = 18;
}

int		main(int ac, char **av)
{
	int				fd;
	t_var			var;
	t_player		player;

	if ((fd = open(av[1], O_RDONLY)) < 0 || ac != 2)
		ft_error(5);
	ft_init_sdl(&var);
	init_key_move(&var);
	parsing_map(fd, &var);
	var.m = fill_map_struct(var);
	player_data_set(&player, &var);
	open_wall_texture(&var);
	open_img_opt_button(&var);
	display(&var, &player);
	return (0);
}
