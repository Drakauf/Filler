/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   surround_ennemy.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/29 10:34:05 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 14:39:59 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/main.h"

void	surround_ennemy(t_memory *mem, int i, int j)
{
	int a;

	a = 0;
	while (a < mem->board_h || a < mem->board_w)
	{
		right_ennemy(mem, i, j, a);
		left_ennemy(mem, i, j, a);
		up_ennemy(mem, i, j, a);
		down_ennemy(mem, i, j, a);
		a++;
	}
}

void	left_ennemy(t_memory *mem, int i, int j, int a)
{
	int k;
	int n;

	n = PROX - a;
	k = 1;
	if (j - a >= 0 && mem->board[i][j - a] == '.')
		mem->grades[i][j - a] += n;
	if (j - a >= 0)
	{
		while (k < a + 1 && i - k >= 0)
		{
			if (mem->board[i - k][j - a] == '.')
				mem->grades[i - k][j - a] += n;
			k++;
		}
		k = 1;
		while (k < a + 1 && i + k < mem->board_h)
		{
			if (mem->board[i + k][j - a] == '.')
				mem->grades[i + k][j - a] += n;
			k++;
		}
	}
}

void	right_ennemy(t_memory *mem, int i, int j, int a)
{
	int k;
	int n;

	n = PROX - a;
	k = 1;
	if (j + a < mem->board_w + 1 && mem->board[i][j + a] == '.')
		mem->grades[i][j + a] += n;
	if (j + a < mem->board_w + 1)
	{
		while (k < a + 1 && i - k >= 0)
		{
			if (mem->board[i - k][j + a] == '.')
				mem->grades[i - k][j + a] += n;
			k++;
		}
		k = 1;
		while (k < a + 1 && i + k < mem->board_h)
		{
			if (mem->board[i + k][j + a] == '.')
				mem->grades[i + k][j + a] += n;
			k++;
		}
	}
}

void	up_ennemy(t_memory *mem, int i, int j, int a)
{
	int k;
	int n;

	n = PROX - a;
	k = 1;
	if (i - a >= 0 && mem->board[i - a][j] == '.')
		mem->grades[i - a][j] += n;
	if (i - a >= 0)
	{
		while (k < a && j - k >= 0)
		{
			if (mem->board[i - a][j - k] == '.')
				mem->grades[i - a][j - k] += n;
			k++;
		}
		k = 1;
		while (k < a && j + k < mem->board_w)
		{
			if (mem->board[i - a][j + k] == '.')
				mem->grades[i - a][j + k] += n;
			k++;
		}
	}
}

void	down_ennemy(t_memory *mem, int i, int j, int a)
{
	int k;
	int n;

	n = PROX - a;
	k = 1;
	if (i + a < mem->board_h && mem->board[i + a][j] == '.')
		mem->grades[i + a][j] += n;
	if (i + a < mem->board_h)
	{
		while (k < a && j - k >= 0)
		{
			if (mem->board[i + a][j - k] == '.')
				mem->grades[i + a][j - k] += n;
			k++;
		}
		k = 1;
		while (k < a && j + k < mem->board_w)
		{
			if (mem->board[i + a][j + k] == '.')
				mem->grades[i + a][j + k] += n;
			k++;
		}
	}
}
