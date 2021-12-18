# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abensett <abensett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 22:08:35 by abensett          #+#    #+#              #
#    Updated: 2021/12/18 17:09:29 by abensett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN   = \033[1;32m
WHITE   = \033[0;m

SRC =	src/ft_errorshandler.c \
		src/ft_push_swap.c \
		src/ft_ps_utils.c \
		src/ft_ps_commands.c \
		src/ft_ps_sort_utils.c \
		src/ft_ps_sort.c \

BSRC = 	src/ft_errorshandler.c \
		src/ft_ps_utils.c \
		src/ft_ps_commands.c \
		src/ft_checker.c \
		src/ft_ps_sort_utils.c \
		src/ft_ps_sort.c \
		src/ft_get_next_line.c \
		
		
		
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC: .c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./includes/

EXEC = push_swap

all:			$(EXEC)

bonus: push_swap checker

checker: $(BOBJ) libft
	gcc -o $@ $(BOBJ) -Llibft -lft
	@printf "\n[$(GREEN)OK$(WHITE)] checker generated\n"


$(EXEC) :	$(OBJ) 
			@make -C libft
			@make bonus -C libft
			@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛\n"
			$(CC) -o $@ $^ libft/libft.a
			@printf "\n[$(GREEN)OK$(WHITE)] $(EXEC) generated\n"

.o:.c	
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