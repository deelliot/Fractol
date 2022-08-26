# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 14:45:22 by deelliot          #+#    #+#              #
#    Updated: 2022/08/26 11:49:41 by deelliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
MINILBX_DIR = ./minilibx/

# Source and object files
SRCS = 1_main.c
SRCS += 2_initialise.c
SRCS += 3_error_handling.c
SRCS += 4_threads.c
SRCS += 5_fractal.c
SRCS += 6_handle_input_2.c
SRCS += 6_handle_input.c
SRCS += 7_image.c
SRCS += barnsley_fern.c

OBJ_FILES = $(SRCS:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MINLBX = $(addprefix $(MINILBX_DIR), libmlx.a)

# Libraries
LINKS =  -L $(LIBFT_DIR) -lft
LINKS +=  -L $(MINILBX_DIR) -lmlx -Ofast -framework OpenGL -framework Appkit
# LINKS += -L /usr/local/lib -lmlx -I /usr/local/include -framework \
# 	OpenGL -framework AppKit

#Rules
all: obj $(LIBFT) $(MINLBX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(MINILBX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(MINLBX):
	@make -C $(MINILBX_DIR)

$(NAME): $(OBJ)
	@clear
	@echo "***** Compiling *****"
	@sleep 1
	@clear
	@echo "***** Compiling *****"
	@sleep 1
	@gcc $(OBJ) $(LINKS) -lm -o $(NAME)
	@clear
	@echo "***** $(NAME) generated *****"
	@echo
	@echo "Usage: ./fractol + option"
	@echo "options: >> julia / J"
	@echo "options: >> mandelbrot / M"
	@echo "options: >> tricorn / T"
	@echo "options: >> burningship / B"
	@echo "options: >> barnsleyfern / BF"

clean:
	@rm -Rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MINILBX_DIR)
	@echo " Objects removed"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo " $(NAME) removed "

re: fclean all

.PHONY: all clean fclean re