# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aymohamm <aymohamm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 10:16:22 by aymohamm          #+#    #+#              #
#    Updated: 2024/02/13 19:18:34 by aymohamm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAG = -Wall -Wextra -Werror

BONUS_HEADER = ./bonus/pipex_bonus.h

SRC = pipex.c error.c error1.c path.c process.c utils.c utils1.c main.c 

BONUS_SRC = ./bonus/heredoc_bonus.c \
		./bonus/process_bonus.c \
		./bonus/pipe_bonus.c \
		./bonus/errors_bonus.c \
		./bonus/init_bonus.c \
		./bonus/path_bonus.c \
		./bonus/utils1_bonus.c \
		./bonus/utils2_bonus.c \
		./bonus/utils3_bonus.c \
		./bonus/utils4_bonus.c \
		./bonus/utils5_bonus.c \


OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC := gcc

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) -o $(NAME)

bonus: $(BONUS_OBJ) $(BONUS_HEADER)
	@$(CC) $(BONUS_OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f $(BONUS_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: re, clean, fclean, all, bonus
