NAME	= so_long.a
CFLAGS	= -Wall -Wextra -Werror
LIBMLX	= lib/
CC		= cc
LIBS	= $(LIBMLX)/libmlx.a -framework Cocoa -framework OpenGL -framework IOKit
BONUS_INCLUDE	= include/so_long_bonus.h
OBJ_DIR	= objs/
SRC_DIR	= src/
PRINTF	= Printf/

AR		:= ar rcs

DEF_COLOR = \033[0;80m
GREEN = \033[0;92m

SRC_FILES	=	get_next_line\
				get_next_line_utils\
				utils\
				utils_mem\
				game_init\
				update\
				tilemap\
				input\
				enemy_move\
				enemy_init\
				step_on\
				map_validity_checker\
				map_validity_tiles\
				valid_path\
				border_checks\
				map\
				main

SRC		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ		=	$(addprefix	$(OBJ_DIR), $(addsuffix .o, $(SRC_FILES))) 

BONUS = 
all: libmlx $(NAME)

libmlx:
	$(MAKE) -C $(LIBMLX)

OBJF	=	.cache_exists

$(NAME)	:	$(OBJ)
	@$(MAKE) -C Printf/
	@$(AR) $(NAME) $(OBJ)
	@$(CC) $(LIBS) Printf/libftprintf.a so_long.a -o so_long
	@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"

$(OBJF):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -r $(OBJ_DIR)
	@rm -rf a.out
	@make clean -C $(PRINTF)
	@$(MAKE) -C $(LIBMLX) clean

bonus: $(OBJ)
	@make
	@make -s $(OBJ) $(BONUS_INCLUDE)
	@echo  "$(GREEN)no forbidden functions used for the bonus$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@rm -f ./libmlx.a 
	@rm -rf so_long
	@make fclean -C $(PRINTF)
	@$(MAKE) -C $(LIBMLX) clean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx