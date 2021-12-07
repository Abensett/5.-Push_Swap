# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abensett <abensett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 22:08:35 by abensett          #+#    #+#              #
#    Updated: 2021/11/11 22:31:05 by abensett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN   = \033[1;32m
WHITE   = \033[0;m

SRC =	ft_errorshandler.c \
		ft_push_swap.c \
		ft_ps_utils.c \
		ft_ps_commands.c \
		ft_sort.c \
		ft_ps_utils2.c \
		
OBJ= $(SRC:.c=.o)
CC = gcc
CFLAGS = -g -I ./includes/

EXEC = push_swap

all:			$(EXEC)

$(EXEC) :	$(OBJ) 
			@make -C libft
			@make bonus -C libft
			$(CC) -o $@ $^ libft/libft.a
			@printf "\n[$(GREEN)OK$(WHITE)] $(EXEC) generated\n"

%.o:%.c	
				@$(CC) -c $(CFLAGS) $?

clean:
				@rm -f $(OBJ)
				@make -C libft clean
				@printf "\n[$(GREEN)cleaned$(WHITE)] .o FILES and libft \n"


fclean:			clean
				@rm -f $(EXEC) libft/libft.a
				@printf "\n[$(GREEN)cleaned$(WHITE)] $(EXEC) and libft.a \n"

re:				fclean all

.PHONY:			all clean fclean re