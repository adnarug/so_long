NAME	:= so_long.a
CFLAGS	:= -Wall -Wextra -g #Werror
LIBMLX	:= lib/
CC		:= cc
LIBS	:= $(LIBMLX)/libmlx.a -framework Cocoa -framework OpenGL -framework IOKit
OBJ_DIR	:= objs/
SRC_DIR	:= src/
#SRC_FILES	:= $(shell find ./src -iname "*.c")
AR		:= ar rcs

DEF_COLOR = \033[0;80m
GREEN = \033[0;92m

SRC_FILES	=	get_next_line\
				get_next_line_utils\
				utils\
				game_init\
				newpanel\
				update\
				tilemap\
				main

SRC		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ		=	$(addprefix	$(OBJ_DIR), $(addsuffix .o, $(SRC_FILES))) 

all: libmlx $(NAME)

libmlx:
	$(MAKE) -C $(LIBMLX)

OBJF	=	.cache_exists

$(NAME)	:	$(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(CC) $(LIBS) so_long.a -o so_long
	@echo "$(GREEN)so_long compiled!$(DEF_COLOR)"

$(OBJF):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o	:	$(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f ./libmlx.a 
	@rm -rf so_long
	@$(MAKE) -C $(LIBMLX) clean

re: fclean all

.PHONY: all, clean, fclean, re, libmlx