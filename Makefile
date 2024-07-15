# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/14 15:15:33 by ktieu             #+#    #+#              #
#    Updated: 2024/07/15 15:30:29 by ktieu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

CC				=	cc

CFLAGS			=	-g -Wall -Wextra -Werror -I ./includes

LIBFT			=	./libft

LIB_A			=	$(LIBFT)/libft.a

SRC_FILES		=	./srcs/main.c \
					./srcs/utils.c \
					./srcs/exit.c \
					./srcs/args.c \
					./srcs/parse.c \
					./srcs/stack.c \
					./srcs/node.c \
					./srcs/stack_action_swap.c \
					./srcs/stack_action_rotate.c \
					./srcs/stack_action_rrotate.c \
					./srcs/stack_action_push.c \
					./srcs/stack_actions.c \
					./srcs/algo_sort3.c \
					./srcs/algo_utils.c \
					./srcs/algo_a2b_utils.c \
					./srcs/algo_b2a_utils.c \
 					./srcs/algo.c

B_FILES			=	./srcs/checker_bonus.c \
					./srcs/stack_actions_bonus.c \
					./srcs/utils.c \
					./srcs/exit.c \
					./srcs/args.c \
					./srcs/parse.c \
					./srcs/stack.c \
					./srcs/node.c \
					./srcs/stack_action_swap.c \
					./srcs/stack_action_rotate.c \
					./srcs/stack_action_rrotate.c \
					./srcs/stack_action_push.c \
					./srcs/stack_actions.c \
					./srcs/algo_sort3.c \
					./srcs/algo_utils.c \
					./srcs/algo_a2b_utils.c \
					./srcs/algo_b2a_utils.c \
 					./srcs/algo.c

O_DIR			=	obj
O_FILES			=	$(addprefix $(O_DIR)/, $(notdir ${SRC_FILES:.c=.o}))
B_O_FILES		=	$(addprefix $(O_DIR)/, $(notdir ${B_FILES:.c=.o}))

$(O_DIR)/%.o: srcs/%.c
	@mkdir -p $(O_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.libft:	
	@touch .libft
	${MAKE} -C ${LIBFT}

all: $(NAME)

$(NAME): .mandatory

mandatory: .mandatory

bonus: .bonus

.mandatory: $(O_FILES) .libft
	$(CC) $(CFLAGS) $(O_FILES) -L${LIBFT} -lft -o $(NAME)
	@touch .mandatory
	@rm -f .bonus

.bonus: $(B_O_FILES) .libft
	$(CC) $(CFLAGS) $(B_O_FILES) -L${LIBFT} -lft -o $(NAME_BONUS)
	@touch .bonus
	@rm -rf .mandatory

clean:
	${MAKE} -C ${LIBFT} clean
	rm -rf ${O_DIR}
	@rm -f .bonus .mandatory .libft

fclean: clean
	${MAKE} -C ${LIBFT} fclean
	rm -rf ${NAME} $(NAME_BONUS)

.PHONY: all clean fclean re bonus