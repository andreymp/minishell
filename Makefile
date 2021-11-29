NAME	=	minishell
SRCS	=	minishell.c utils.c parcer.c gnl/get_next_line.c gnl/get_next_line_utils.c \
			beans/echo.c beans/pwd.c beans/cd.c
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
OBJS	=	${SRCS:.c=.o}
HEADER	=	minishell.h
RM		=	rm -f

all:		$(NAME)
$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -l readline
$(OBJS):	$(HEADER)
clean:
		$(RM) $(OBJS)
fclean:		clean
		$(RM) $(NAME)
re:			fclean all

.PHONY:		all clean fclean re