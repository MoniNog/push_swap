/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:34 by moni              #+#    #+#             */
/*   Updated: 2024/06/21 11:25:31 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gestion de tout le rendu graphique du jeu. */
// #include "../includes/so_long.h"

// int	create_trgb(int t, int r, int g, int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

// int	get_t(int trgb)
// {
// 	return ((trgb >> 24) & 0xFF);
// }

// int	get_r(int trgb)
// {
// 	return ((trgb >> 16) & 0xFF);
// }

// int	get_g(int trgb)
// {
// 	return ((trgb >> 8) & 0xFF);
// }

// int	get_b(int trgb)
// {
// 	return (trgb & 0xFF);
// }




// // void draw_map(t_game *game, int map[MAX_WIDTH][MAX_WIDTH], int rows, int cols)
// // {
// // 	int i;
// // 	int j;
// // 	void *img;

// // 	i = 0;
// // 	while (i < rows)
// // 	{
// // 		j = 0;
// // 		while (j < cols)
// // 		{
// // 			img = select_image(map[i][j], game);
// // 			if (img != NULL)
// // 			{
// 				x = j * TILE_SIZE;
// 				y = i * TILE_SIZE;
// 				mlx_put_image_to_window(game->mlx, game->win, img, x, y);
// 			}
// 		j++;
// 		}
// 		i++;
// 	}
// }

// int	main(void)
// {
// 	t_game	game;

// 	game.mlx = mlx_init();
// 	if (game.mlx == NULL)
// 	{
// 		printf("game.mlx == NULL");
// 		return (1);
// 	}
// 	game.win = mlx_new_window(game.mlx, 600, 600, "pixie");
// 	if (game.win == NULL)
// 	{
// 		printf("game.win == NULL");
// 		return (1);
// 	}	
// 	mlx_key_hook(game.win, key_hook, &game);
// 	mlx_pixel_put(game.mlx, game.win, 100, 100, 0xFF0000);
// 	mlx_loop(game.mlx);
// 	return (0);
// }

// mlx_put_image_to_window
// ft_render, render, core_render, render_other, render_background, render_down,
// render_left, render_right, render_top, draw, draw_background, draw_hud, draw_hud_life,
// draw_hud_mana, draw_hud_steps: Toutes les fonctions liées au rendu des différents composants à l'écran.