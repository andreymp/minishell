NAME =	parser

CC =	gcc
CFLAGS =	-g -Wall -Wextra -Werror -MMD

RM =	rm -rf

SRC =   parcer.c	\
		utils.c 	\
		do_symbol.c \
		redirect.c  \
		get_next_line.c \
		get_next_line_utils.c \
		main.c		\
		init_pipe.c \
		pipe.c		\


INC = 	-I libft/libft.h 	\
		-I parser.h         \
		-I get_next_line.h	\
		-I pipe.h			\

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

LD_FLAGS =	-L libft

.PHONY :	all clean re fclean

.c.o :		
		$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.c=.o)


$(NAME):	$(OBJS)
			@make -C ./libft/
			@make bonus -C ./libft/
			$(CC) $(CFLAGS) $(LD_FLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP)
			@make clean -C libft/

fclean: 	clean
			$(RM) $(NAME)
			@make fclean -C libft/

re: 		fclean all

-include $(DEP)