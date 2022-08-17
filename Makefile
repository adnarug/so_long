NAME	:= so_long
CFLAGS	:= -Werror -Wextra -Wall 
LIBMLX	:= ./lib/MLX42
CC		:= gcc
LIBS	:= $(LIBMLX)/libmlx42.a $(LIBMLX)/libglfw3.a -framework Cocoa -framework OpenGL -framework IOKit
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<  && printf "Compiling: $(notdir $<)"


$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f ./libmlx42.a 
	@rm -f ./libglfw3.a
	@$(MAKE) -C $(LIBMLX) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx