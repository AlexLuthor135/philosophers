SRCS		=	main.c init_philo.c parsing.c\
				routine.c utils.c free.c\
				error_handle.c

CC_FLAGS		=	-Wall -Wextra -Werror -g
CC				=	gcc
SRCS_F			= src/
OBJS_F			= obj/

LIBFT = inc/libft/

OBJS		=	$(SRCS:.c=.o)
OBJS_P		=	$(addprefix $(OBJS_F), $(OBJS))
NAME		= 	philo

all:$(NAME)

$(OBJS_F)%.o: $(SRCS_F)%.c Makefile philo.h
	@mkdir -p $(OBJS_F)
	@echo "Working on: $<"
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@

$(NAME): $(OBJS_P)
	@$(CC) $(CC_FLAGS) -O3 -o $(NAME) $(OBJS_P)
	@echo "Done"

clean:
	@rm -rf $(OBJS_F)

fclean:	clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re