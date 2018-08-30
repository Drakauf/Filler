/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 17:12:43 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 14:39:44 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/main.h"

void	parse(t_memory *mem)
{
	static int	parse_time = 0;

	if (!parse_time)
	{
		get_players(mem);
		get_board(mem);
		parse_time++;
	}
	mem->play_x = 0;
	mem->play_y = 0;
	mem->play_p = -1000;
	copy_board(mem);
	copy_piece(mem);
	grades_to_zero(mem);
	assign_grades(mem);
	get_pos_to_play(mem);
}

void	get_players(t_memory *mem)
{
	char	*str;

	if (get_next_line(0, &str) == 1 &&
			ft_strlen(str) >= 10 && (str[10] == '1' || str[10] == '2'))
	{
		if (str[10] == '1')
		{
			mem->player_id = 'O';
			mem->ennemy_id = 'X';
		}
		else
		{
			mem->player_id = 'X';
			mem->ennemy_id = 'O';
		}
	}
	free(str);
}

void	get_board(t_memory *mem)
{
	char	**strtab;
	char	*str;
	int		i;

	if (get_next_line(0, &str) == 1 && !ft_strncmp(str, "Plateau ", 8))
	{
		strtab = ft_strsplit(str, ' ');
		mem->board_h = ft_atoi(strtab[1]);
		mem->board_w = ft_atoi(strtab[2]);
		ft_strdel(strtab);
	}
	ft_strdel(&str);
	if (!(mem->board = malloc(sizeof(char *) * mem->board_h)))
		exit(0);
	if (!(mem->grades = malloc(sizeof(int *) * mem->board_h)))
		exit(0);
	i = 0;
	while (i < mem->board_h)
	{
		if (!(mem->board[i] = malloc(sizeof(char) * (mem->board_w + 1))))
			exit(0);
		if (!(mem->grades[i] = malloc(sizeof(int) * mem->board_w)))
			exit(0);
		i++;
	}
}
