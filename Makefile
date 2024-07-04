NAME			=	push_swap

CC				=	cc

CFLAGS			=	 -I ./includes #-Wall -Wextra -Werror

LIBFT			=	./libft

LIB_A			=	$(LIBFT)/libft.a

SRC_FILES		=	./srcs/main.c \
					./srcs/exit.c \
					./srcs/args.c \
					./srcs/parse.c \
					./srcs/stack.c \
					./srcs/node.c \
					./srcs/stack_utils.c \
					./srcs/stack_action_swap.c \
					./srcs/stack_action_rotate.c \
					./srcs/stack_action_rrotate.c \
					./srcs/stack_action_push.c \
					./srcs/stack_actions.c \
					./srcs/algo_sort3.c \
					./srcs/algo_utils.c \
 					./srcs/algo.c \
					./srcs/debug.c 


O_DIR			=	obj
O_FILES			= $(addprefix $(O_DIR)/, $(notdir ${SRC_FILES:.c=.o}))


$(O_DIR)/%.o: srcs/%.c
	@mkdir -p $(O_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.libft:	
	@touch .libft
	${MAKE} -C ${LIBFT}

all: .mandatory

mandatory: .mandatory

bonus: .bonus

.mandatory: $(O_FILES) .libft
	$(CC) $(CFLAGS) $(O_FILES) -L${LIBFT} -lft -o $(NAME)
	@touch .mandatory
	@rm -f .bonus

clean:
	${MAKE} -C ${LIBFT} clean
	rm -rf ${O_DIR}
	@rm -f .bonus .mandatory .libft

fclean: clean
	${MAKE} -C ${LIBFT} fclean
	rm -rf ${NAME}

.PHONY: all clean fclean re