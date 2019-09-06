##########################################################
#                                                         #
#             Makefile for push_swap                     #
#                                                         #
# First compiles the library for use in the project         #
# Before compiling the programs "checker" & "push_swap"     #
#                                                         #
##########################################################

LIB = libft
NAME_CH = checker
NAME_PS = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_DIR = ./srcs/
INC_DIR = ./includes/
OBJ_DIR = ./srcs/
OPTIONS = -I$(INC_DIR) -I./libft -lft -L./libft
HDR = ./includes/ps.h

OBJ_CH = $(OBJ_DIR)checker.o $(OBJ_DIR)5sort.o $(OBJ_DIR)flagsauce.o
OBJ_CH += $(OBJ_DIR)pins.o $(OBJ_DIR)sauces.o $(OBJ_DIR)stk.o
OBJ_CH += $(OBJ_DIR)visual.o 

OBJ_PS = $(OBJ_DIR)push_swap.o $(OBJ_DIR)5sort.o
OBJ_PS += $(OBJ_DIR)flagsauce.o $(OBJ_DIR)pins.o $(OBJ_DIR)sauces.o
OBJ_PS += $(OBJ_DIR)visual.o  $(OBJ_DIR)stk.o

all: $(LIB) $(NAME_CH) $(NAME_PS)

$(LIB): relib cleanlib
	@echo "[$(LIB)] compiled"

%.o: $(SRC_DIR)%.c $(HDR)
	@$(CC) $(FLAGS) $(OPTIONS) -c $< -o $@

$(NAME_CH): $(OBJ_CH)
	@$(CC) -o $(NAME_CH) $(FLAGS) $(OPTIONS) $(OBJ_CH) 
	@echo "[$(NAME_CH)] compiled"

$(NAME_PS): $(OBJ_PS)
	@$(CC) -o $(NAME_PS) $(FLAGS) $(OPTIONS) $(OBJ_PS)
	@echo "[$(NAME_PS)] compiled"

clean: cleanlib
	@/bin/rm -f $(SRC_DIR)*.o
	@echo "Object files removed"

fclean: clean fcleanlib
	@/bin/rm -f $(NAME_CH) $(NAME_PS)
	@echo "[$(NAME_CH)] & [$(NAME_PS)] removed"

re: fclean all

relib:
	@$(MAKE) -C ./libft re

cleanlib:
	@$(MAKE) -C ./libft clean

fcleanlib: cleanlib
	@$(MAKE) -C ./libft fclean
