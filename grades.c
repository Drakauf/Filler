/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   grades.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/29 09:50:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 14:39:18 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/main.h"

void	grades_to_zero(t_memory *mem)
{
	int i;
	int j;

	i = 0;
	while (i < mem->board_h)
	{
		j = 0;
		while (j < mem->board_w)
		{
			mem->grades[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	assign_grades(t_memory *mem)
{
	int i;
	int j;

	i = 0;
	while (i < mem->board_h)
	{
		j = 0;
		while (j < mem->board_w)
		{
			if (mem->board[i][j] == mem->ennemy_id
					|| mem->board[i][j] == mem->ennemy_id - 32)
				surround_ennemy(mem, i, j);
			j++;
		}
		i++;
	}
}
