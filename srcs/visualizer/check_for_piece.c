/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 16:02:05 by bmarlin           #+#    #+#             */
/*   Updated: 2020/11/11 16:02:17 by bmarlin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/visualizer.h"

void	check_for_piece(t_v *begin, t_visu *v)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (begin->tab[i] != NULL)
	{
		j = 0;
		while (j < v->nb_x)
		{
			if (begin->tab[i][j] != '.')
				draw_rect(i, j, v, begin);
			j++;
		}
		i++;
	}
}
