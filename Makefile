LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a


SOURCES_FILES 	= 	push_swap.c\
					arg_checker.c\
					init_stack.c\
					operations.c\
					operation_double.c\
					sort.c\
					sort_complex.c\
					sort_simple.c\
					sort_utils.c\
					sort_utils2.c\
					moves.c

BONUS_FILES 	= 	checker.c\
					arg_checker_bonus.c\
					init_stack_bonus.c\
					operations_bonus.c\
					op_double_bonus.c\
					utils.c\
					exec_instruc.c


NAME 			=	push_swap
NAME_BONUS 		=	checker

CFLAGS			=	-Wall -Wextra -Werror
CC 				=	gcc
RM 				=	rm -f
RM_ALL 			=	rm -rf
VAL				=	valgrind --leak-check=full --show-leak-kinds=all

SOURCES_DIR 	=	sources/
BONUS_DIR 		=	sources_bonus/
INCLUDES 		=	includes/
OBJ_DIR 		=	obj/
OBJ_BONUS_DIR 	=	obj_bonus/

HEADER			=	$(INCLUDES)/push_swap.h
HEADER_BONUS	=	$(INCLUDES)/checker.h

SOURCES 		=	${addprefix ${SOURCES_DIR}, ${SOURCES_FILES}}
SOURCES_BONUS 	=	${addprefix ${BONUS_DIR}, ${BONUS_FILES}}

OBJS 			=	${addprefix ${OBJ_DIR}, ${SOURCES_FILES:.c=.o}}
OBJS_BONUS 		=	${addprefix ${OBJ_BONUS_DIR}, ${BONUS_FILES:.c=.o}}

all:		${NAME}

${NAME}:	${LIBFT} ${OBJS} $(HEADER)
			${CC} ${OBJS} ${LIBFT} -o ${NAME}

${OBJ_DIR}%.o:	${SOURCES_DIR}%.c
				mkdir -p obj
				${CC} ${CFLAGS} -c $< -o $@

bonus:		${NAME_BONUS}

${NAME_BONUS}:	${LIBFT} ${OBJS_BONUS} $(HEADER_BONUS)
			${CC} ${OBJS_BONUS} ${LIBFT} -o ${NAME_BONUS}

${OBJ_BONUS_DIR}%.o:	${BONUS_DIR}%.c
				mkdir -p obj_bonus
				${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:	
			@echo "\033[32mcompiling\033[m"
			$(MAKE) -sC $(LIBFT_PATH)

clean:		
			${RM_ALL} ${OBJ_DIR} ${OBJ_BONUS_DIR}
			$(MAKE) -sC $(LIBFT_PATH) fclean

fclean:		clean
			${RM} ${NAME} ${NAME_BONUS}
			$(MAKE) -sC $(LIBFT_PATH) fclean

re:			fclean all

run:		${NAME}
			${VAL} ./${NAME} 2 1 3 4

norm:
			norminette $(SOURCES_DIR) $(BONUS_DIR) $(INCLUDES)

.PHONY:		all bonus clean fclean re libft run norm