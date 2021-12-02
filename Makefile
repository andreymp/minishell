NAME	=	minishell
SRCS	=	minishell.c utils.c beans/echo.c beans/pwd.c beans/cd.c beans/exit.c \
	beans/env.c lists.c beans/export.c utils2.c beans/unset.c
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
OBJS	=	${SRCS:.c=.o}
HEADER	=	minishell.h
RM		=	rm -f

all:		$(NAME)
$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L/Users/remelia/.brew/opt/readline/lib -I/Users/remelia/.brew/opt/readline/include -lreadline
$(OBJS):	$(HEADER)
clean:
		$(RM) $(OBJS)
fclean:		clean
		$(RM) $(NAME)
re:			fclean all

.PHONY:		all clean fclean re