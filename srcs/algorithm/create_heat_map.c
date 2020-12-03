/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_heat_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:01:58 by bmarlin           #+#    #+#             */
/*   Updated: 2020/11/11 16:02:17 by bmarlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	fill_hmap_init(int *y, t_filler **f)
{
	int	x;

	x = 0;
	while (x < (*f)->w_board)
	{
		if ((*f)->map[*y][x] == '.')
			(*f)->hmap[*y][x] = 0;
		if ((*f)->map[*y][x] == (*f)->letter_me)
			(*f)->hmap[*y][x] = -2;
		if ((*f)->map[*y][x] == (*f)->letter_ennemy)
			(*f)->hmap[*y][x] = -1;
		x++;
	}
	x = 0;
	(*y)++;
}

int			create_heat_map(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	f->hmap = (int **)malloc(sizeof(int*) * (unsigned long)f->h_board);
	if (!f->hmap)
	{
		free_tab(f);
		return (1);
	}
	while (y < f->h_board)
	{
		f->hmap[y] = (int *)malloc(sizeof(int) * (unsigned long)f->w_board);
		if (!f->hmap[y])
		{
			free_tab(f);
			while (y > 0)
				free(f->hmap[--y]);
			return (1);
		}
		fill_hmap_init(&y, &f);
	}
	return (0);
}
