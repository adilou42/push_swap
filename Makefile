NAME		=	push_swap

SRCS		=	check_doublons.c \
				executes_methods_2.c \
				executes_moves.c \
				ft_atoi.c \
				ft_big_sort.c \
				ft_is_sorted.c \
				ft_split.c \
				get_min_max.c \
				index.c \
				last_sort.c \
				list.c \
				lstclear.c \
				lstsize.c \
				methods.c \
				parsing.c \
				rotate.c \
				small_sort.c \
				sort_4.c \
				sort_5_2.c \
				sort_5.c \
				sorting_algo_2.c \
				sorting_algo.c \
				swap_push.c \

OBJS		=	${SRCS:.c=.o}

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			= 	rm -rf

all:	${NAME}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJS} ${BONUS_OBJ}

fclean: clean
	${RM} ${NAME}
	${RM} ${BONUS_NAME}

re: fclean all

.PHONY: all clean fclean re
