# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fomanca <fomanca@student.42porto.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/07 17:12:37 by fomanca           #+#    #+#              #
#    Updated: 2025/12/09 16:49:24 by fomanca          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I includes
SRC_DIR     = srcs
OBJ_DIR     = objs

COMMON_SRCS := $(shell find $(SRC_DIR) -name "*.c" ! -name "main.c" ! -name "checker.c")

MANDATORY_SRCS := $(COMMON_SRCS) $(SRC_DIR)/main.c
BONUS_SRCS     := $(COMMON_SRCS) $(SRC_DIR)/checker.c
MANDATORY_OBJS := $(MANDATORY_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS     := $(BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# deixar bonito
GREEN       = \033[0;32m
CYAN        = \033[0;36m
YELLOW      = \033[0;33m
RED         = \033[0;31m
RESET       = \033[0m
BOLD        = \033[1m


all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	@echo "$(CYAN)🔗 Linking $(BOLD)$(NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(MANDATORY_OBJS) -o $(NAME)
	@echo "$(GREEN)✔ Build complete!$(RESET)"

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@echo "$(CYAN)🔗 Linking $(BOLD)$(BONUS_NAME)$(RESET)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)
	@echo "$(GREEN)✔ Bonus complete!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(YELLOW)⚙️  Compiling $(RESET)$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)🧹 Cleaning objects$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)🗑  Removing binaries$(RESET)"
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
