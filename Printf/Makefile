# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguranda <pguranda@student.42heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 17:39:15 by pguranda          #+#    #+#              #
#    Updated: 2022/09/26 11:29:48 by pguranda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME			= libftprintf.a
INCLUDE			= include/ft_printf.h
BONUS_INCLUDE	= include/ft_printf_bonus.h
LIBFT			= libft
SRC_DIR			= sources/
OBJ_DIR			= obj/
BONUS_SRC_DIR	= sources_bonus/
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -I
RM				= rm -f
AR				= ar rcs

SRC_FILES 		=	ft_parse_decode\
					ft_printf\
					ft_writing\
					ft_digit\
					ft_find_len\
					ft_hex_low\
					ft_hex_up\
					ft_putnbr_unsigned\
					ft_zero\
					ft_put_pointer\
					ft_putnbr_with_zeroes\
					ft_sign\
					ft_space_sign\
					ft_hex_low_pointer\
					ft_putstr_printf\
					ft_putchar_printf\
					ft_precision_hex_low\
					ft_precision_hex_up\
					ft_precision_unsigned\
					ft_precision_string\
					ft_putnbr_printf\
					ft_hex_counter\
					ft_write_width\
					ft_minus_width\
					ft_write_zeroes\
					ft_putnbr_with_zeros_unsigned\
					ft_write_hex

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "ft_printf compiled!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< "
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@cp ft_printf.c sources/

clean:
			@$(RM) -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@rm -rf a.out
			@echo "ft_printf object files cleaned!"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(LIBFT)/libft.a
			
			@echo "ft_printf executable files cleaned!"
			@echo "libft executable files cleaned!"

re:			fclean all
			@echo "Cleaned and rebuilt everything for ft_printf!"

bonus: $(OBJ_B) 
	@make -s $(OBJ) INCLUDE="$(BONUS_INCLUDE)"
	@echo  "compiled with bonus header!"


norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm