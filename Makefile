# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: shthevak <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/08/29 14:06:47 by shthevak     #+#   ##    ##    #+#        #
#    Updated: 2018/08/29 17:29:07 by shthevak    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

PHONY = all clean fclean re

NAME = shthevak.filler

# **************************************************************************** #
#          PATH                                                                #
# **************************************************************************** #

SRC_PATH = ./
OBJ_PATH = ./obj/
INC_PATH = ./includes/
LIBFT_PATH = ./libft/

# **************************************************************************** #
#           SRCS                                                               #
# **************************************************************************** #

LIB_NAME = libft.a

SRC_NAME = copy.c get_next_line.c get_pos.c grades.c main.c parsing.c\
		   surround_ennemy.c

INC_NAME = main.h 

# **************************************************************************** #
#           VAR                                                                #
# **************************************************************************** #

OBJ_NAME= $(SRC_NAME:.c=.o)

INC = $(addprefix $(INC_PATH), $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
LIB = $(addprefix $(LIBFT_PATH), $(LIB_NAME))

# **************************************************************************** #
#           FLAG                         						               #
# **************************************************************************** #

ifndef FLAG
	FLAG= -Wall -Werror -Wextra
endif

# **************************************************************************** #
#           REGLES                                                             #
# **************************************************************************** #

all : $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	@printf "Compiling $(NAME)..."
	@make -C libft/
	@gcc $(CFLAGS) -o $@ $(OBJ) $(LIB)
	@printf "\033[32m[OK]\033[0m\n"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -I $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/

re: fclean all

