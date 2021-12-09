NAME =	minishell

CC =	gcc
CFLAGS =	-g -Wall -Wextra -Werror -MMD

RM =	rm -rf

SRC =   parse/parcer.c	\
		utils/utils.c 	\
		utils/utils1.c 	\
		utils/lists.c     \
		parse/do_symbol.c \
		parse/redirect.c  \
		utils/get_next_line.c \
		utils/get_next_line_utils.c \
		srcs/main.c		\
		pipes/init_pipe.c \
		pipes/pipe.c		\
		beans/cd.c  \
		beans/echo.c \
		beans/env.c  \
		beans/exit.c  \
		beans/export.c  \
		beans/pwd.c  \
		beans/unset.c  \
		beans/dq.c	\
		beans/shlvl.c	\
		srcs/minishell.c \
		beans/history.c	\
		beans/exec.c \
		utils/utils2.c \
		utils/utils3.c \
		utils/utils4.c \

INC = 	-I libft/libft.h 	\
		-I includes/parser.h         \
		-I includes/get_next_line.h	\
		-I includes/pipe.h			\
		-I includes/minishell.h		\
		-I /Users/${USER}/.brew/opt/readline/include \

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

LD_FLAGS =	-L libft \
			-L /Users/${USER}/.brew/opt/readline/lib \

.PHONY :	all clean re fclean

.c.o :	
		$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)


$(NAME):	$(OBJS)
			@make -C ./libft/
			@make bonus -C ./libft/
			$(CC) $(CFLAGS) $(LD_FLAGS) $(OBJS) ./libft/libft.a -o $(NAME) -lreadline

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP)
			@make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			@make fclean -C libft/

re: 		fclean all

-include $(DEP)