# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfrontel <jfrontel@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 13:40:04 by jfrontel          #+#    #+#              #
#    Updated: 2022/10/03 14:00:32 by jfrontel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	push_swap

# ========== ADDING SRCR ==========
SRCR	= 	push_swap.c \
			./src/argument_and_index.c \
			./src/find_partnet_and_cost.c \
			./src/ft_split.c \
			./src/push_swap_utils.c \
			./src/push_swap_operations_I.c \
			./src/push_swap_operations_II.c \
			./src/push_swap_operations_III.c \
			./src/sort_number.c \
			./src/stack_operations.c \
			./src/validate_arg.c \
			./src/move_stack.c \
			./src/validate_overflow.c

# ========== ADDING COLORS ==========
GREEN:="\033[1;32m"
BLUE:="\033[0;34m"
CYAN:="\033[1;36m"

OBJS	= ${SRCR:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS	= -Werror -Wall -Wextra -g

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo $(GREEN) "[OK COMPILED]"

all:	${NAME}

clean:
		${RM} ${OBJS}
		@echo $(CYAN) "[OK CLEAN]"

fclean:	clean
		${RM} ${NAME}
		@echo $(CYAN) "[OK FCLEAN]"
	
re:		fclean all

.PHONY:		all clean fclean re
