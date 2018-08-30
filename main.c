/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 17:04:29 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 14:39:31 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/main.h"

int		main(void)
{
	int			i;
	t_memory	*mem;

	if (!(mem = malloc(sizeof(t_memory))))
		return (0);
	i = 1;
	while (i)
	{
		parse(mem);
		if (mem->play_p == -1000)
			i = 0;
		ft_putnbr(mem->play_x);
		ft_putstr(" ");
		ft_putnbr(mem->play_y);
		ft_putstr("\n");
		free_piece(mem);
	}
	free_memory(mem);
	return (0);
}

void	free_piece(t_memory *mem)
{
	int i;

	i = 0;
	while (i < mem->piece.piece_h)
	{
		free(mem->piece.piece[i]);
		i++;
	}
	free(mem->piece.piece);
}

void	free_memory(t_memory *mem)
{
	int i;

	i = 0;
	while (i < mem->board_h)
	{
		free(mem->board[i]);
		free(mem->grades[i]);
		i++;
	}
	free(mem->board);
	free(mem->grades);
	free(mem);
}
