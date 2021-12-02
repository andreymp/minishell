NAME =	minishell

CC =	gcc
CFLAGS =	-g -Wall -Wextra -Werror -MMD #-fsanitize=address

RM =	rm -rf

SRC =   parcer.c	\
		utils.c 	\
		utils1.c 	\
		lists.c     \
		do_symbol.c \
		redirect.c  \
		get_next_line.c \
		get_next_line_utils.c \
		main.c		\
		init_pipe.c \
		pipe.c		\
		beans/cd.c  \
		beans/echo.c \
		beans/env.c  \
		beans/exit.c  \
		beans/export.c  \
		beans/pwd.c  \
		beans/unset.c  \
		minishell.c	   \


INC = 	-I libft/libft.h 	\
		-I parser.h         \
		-I get_next_line.h	\
		-I pipe.h			\
		-I minishell.h		\

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

LD_FLAGS =	-L libft

.PHONY :	all clean re fclean

.c.o :		
		$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)


$(NAME):	$(OBJS)
			@make -C ./libft/
			@make bonus -C ./libft/
			$(CC) $(CFLAGS) $(LD_FLAGS) $(OBJS) ./libft/libft.a -o $(NAME) -l readline

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP)
			@make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			@make fclean -C libft/

re: 		fclean all

-include $(DEP)