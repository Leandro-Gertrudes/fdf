# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 16:41:07 by lgertrud          #+#    #+#              #
#    Updated: 2025/06/03 14:50:26 by lgertrud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executables
NAME = fdf

# Directories
SRC_DIR = src
INCLUDES_DIR = includes
LIBFT_DIR = libft
MLX_DIR = ./minilibx-linux

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

# Includes
INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# Library
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/makefile.gen

# Source and objs
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/draw_map.c $(SRC_DIR)/parse.c  $(SRC_DIR)/commands_1.c $(SRC_DIR)/commands_2.c \
	$(SRC_DIR)/rotate.c $(SRC_DIR)/color.c $(SRC_DIR)/fill.c $(SRC_DIR)/draw_utils.c
OBJS = $(SRC:.c=.o)

# Colors
YELLOW = \e[93m
GREEN = \033[1;32m
RED = \033[1;31m
BLUE = \033[1;36m
RESET = \033[0m
INTRO = @echo "\n$(BLUE)🚀 Starting compilation of the $(YELLOW)FDF$(RESET) $(BLUE)project by $(YELLOW)lgertrud$(RESET)...\n\
--------------------------------------------------------------"
END = @echo "$(GREEN)✔ Compilation complete!$(RESET)\n\n\
To run the program:\n\
  $(BLUE)./fdf <path_to_map.fdf>$(RESET)\n\n\
Example:\n\
  $(BLUE)./fdf maps/42.fdf$(RESET)\n\n\
Enjoy the view! 🚀"

all: $(LIBFT) MLX $(NAME)

$(LIBFT):
	$(INTRO)
	@echo "$(YELLOW)[LOADING...]$(RESET)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

MLX: $(MLX_DIR)/libmlx.a

$(MLX_DIR)/libmlx.a:
	@$(MAKE) --no-print-directory -C $(MLX_DIR) > /dev/null 2>&1

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	$(END)
	
%.o: %.c
	@echo "$(YELLOW)[.o]$(RESET)Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)[CLEAN]$(RESET) Removing object files..."
	@rm -f $(OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(MAKE) --no-print-directory -C $(MLX_DIR) clean > /dev/null 2>&1

fclean:
	@echo "$(RED)[FCLEAN]$(RESET) Removing all generated files..."
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@$(MAKE) --no-print-directory -C $(MLX_DIR) clean > /dev/null 2>&1

re: fclean all MLX
