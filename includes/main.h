/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/28 17:11:16 by shthevak     #+#   ##    ##    #+#       */
/*   Updated: 2018/08/29 14:40:38 by shthevak    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include "../get_next_line.h"

# define PROX 11

typedef struct			s_piece
{
	char				**piece;
	int					piece_h;
	int					piece_w;
	int					last_h;
	int					last_w;
}						t_piece;

typedef struct			s_memory
{
	char				player_id;
	char				ennemy_id;
	char				**board;
	int					board_h;
	int					board_w;
	int					**grades;
	int					play_x;
	int					play_y;
	int					play_p;
	t_piece				piece;
}						t_memory;

void					parse(t_memory *mem);
void					get_players(t_memory *mem);
void					get_board(t_memory *mem);
void					copy_board(t_memory *mem);
void					copy_piece(t_memory *mem);
void					get_last_star(t_memory *mem);
void					grades_to_zero(t_memory *mem);
void					assign_grades(t_memory *mem);
void					surround_ennemy(t_memory *mem, int i, int j);
void					right_ennemy(t_memory *mem, int i, int j, int a);
void					left_ennemy(t_memory *mem, int i, int j, int a);
void					up_ennemy(t_memory *mem, int i, int j, int a);
void					down_ennemy(t_memory *mem, int i, int j, int a);
void					get_pos_to_play(t_memory *mem);
int						check_piece(t_memory *mem, int i, int j);
int						get_points(t_memory *mem, int i, int j);
void					free_piece(t_memory *mem);
void					free_memory(t_memory *mem);

#endif
