/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   copy.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 18:02:11 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 14:38:47 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/main.h"

void	copy_board(t_memory *mem)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	while (i < mem->board_h && get_next_line(0, &str))
	{
		if (!ft_strnstr(str, "    ", 4) && !ft_strnstr(str, "Plateau", 7))
		{
			tmp = str;
			tmp = 1 + ft_strchr(tmp, ' ');
			ft_strncpy(mem->board[i], tmp, mem->board_w);
			i++;
		}
		ft_strdel(&str);
	}
}

void	copy_piece(t_memory *mem)
{
	char	*str;
	char	*tmp;
	int		i;

	if (get_next_line(0, &str) && ft_strnstr(str, "Piece", 5))
	{
		tmp = str;
		tmp = ft_strchr(tmp, ' ');
		mem->piece.piece_h = ft_atoi(tmp++);
		tmp = ft_strchr(tmp, ' ');
		mem->piece.piece_w = ft_atoi(tmp);
		if (!(mem->piece.piece = malloc(sizeof(char *) * mem->piece.piece_h)))
			exit(0);
	}
	ft_strdel(&str);
	i = 0;
	while (i < mem->piece.piece_h && get_next_line(0, &str) == 1)
	{
		if (!(mem->piece.piece[i] = ft_strdup(str)))
			exit(0);
		ft_strdel(&str);
		i++;
	}
	get_last_star(mem);
}

void	get_last_star(t_memory *mem)
{
	int i;
	int j;

	mem->piece.last_h = 0;
	mem->piece.last_w = 0;
	i = 0;
	while (i < mem->piece.piece_h)
	{
		j = 0;
		while (j < mem->piece.piece_w)
		{
			if (mem->piece.piece[i][j] == '*')
			{
				if (i > mem->piece.last_h)
					mem->piece.last_h = i;
				if (j > mem->piece.last_w)
					mem->piece.last_w = j;
			}
			j++;
		}
		i++;
	}
}
