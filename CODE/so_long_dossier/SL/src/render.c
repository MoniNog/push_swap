/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 18:09:34 by moni              #+#    #+#             */
/*   Updated: 2024/05/10 09:18:18 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Gestion de tout le rendu graphique du jeu. */

void draw_map(t_game *game, int map[MAX_WIDTH][MAX_WIDTH], int rows, int cols)
{
	int i;
	int j;
	void *img;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			img = select_image(map[i][j], game);
			if (img != NULL)
			{
				x = j * TILE_SIZE;
				y = i * TILE_SIZE;
				mlx_put_image_to_window(game->mlx, game->win, img, x, y);
			}
		j++;
		}
		i++;
	}
}

// ft_render, render, core_render, render_other, render_background, render_down,
// render_left, render_right, render_top, draw, draw_background, draw_hud, draw_hud_life,
// draw_hud_mana, draw_hud_steps: Toutes les fonctions liées au rendu des différents composants à l'écran.