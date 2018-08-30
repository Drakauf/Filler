/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_pos.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/29 10:43:37 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 14:39:09 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/main.h"

void	get_pos_to_play(t_memory *mem)
{
	int i;
	int j;
	int k;

	mem->play_x = 0;
	mem->play_y = 0;
	mem->play_p = -1000;
	k = 0;
	i = -1;
	while (++i + mem->piece.last_h < mem->board_h)
	{
		j = -1;
		while (++j + mem->piece.last_w < mem->board_w)
		{
			if (check_piece(mem, i, j) == 1)
			{
				k = get_points(mem, i, j);
				k > mem->play_p ? mem->play_x = i : 0;
				k > mem->play_p ? mem->play_y = j : 0;
				k > mem->play_p ? mem->play_p = k : 0;
			}
		}
	}
}

int		check_piece(t_memory *mem, int i, int j)
{
	int a;
	int b;
	int n;

	a = -1;
	n = 0;
	while (++a < mem->piece.piece_h && n <= 1)
	{
		b = -1;
		while (++b < mem->piece.piece_w && n <= 1)
		{
			if (mem->piece.piece[a][b] && mem->piece.piece[a][b] == '*')
			{
				if (mem->board[i + a][j + b]
					&& (mem->board[i + a][j + b] == mem->player_id
						|| mem->board[i + a][j + b] == mem->player_id - 32))
					n++;
				if (mem->board[i + a][j + b]
					&& (mem->board[i + a][j + b] == mem->ennemy_id
						|| mem->board[i + a][j + b] == mem->ennemy_id - 32))
					return (0);
			}
		}
	}
	return (n);
}

int		get_points(t_memory *mem, int i, int j)
{
	int a;
	int b;
	int n;

	a = 0;
	n = 0;
	while (a < mem->piece.piece_h)
	{
		b = 0;
		while (b < mem->piece.piece_w)
		{
			if (mem->piece.piece[a][b] == '*'
				&& mem->board[i + a][j + b] && mem->board[i + a][j + b] == '.')
				n += mem->board[i + a][j + b];
			b++;
		}
		a++;
	}
	return (n);
}
