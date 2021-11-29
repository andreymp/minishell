NAME = libft.a
DOT_H = libft.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MMD
AR = ar rcs
RM = rm -f

FILES = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c\
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_striteri.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

FILES_B = 	ft_lstnew.c \
	  		ft_lstadd_front.c \
	  		ft_lstsize.c \
	  		ft_lstlast.c \
	  		ft_lstadd_back.c \
	  		ft_lstdelone.c \
	  		ft_lstclear.c \
	  		ft_lstiter.c\
	  		ft_lstmap.c

MAN =		${FILES:.c=.o}
DEP =		$(FILES:.c=.d)
BON =		${FILES_B:.c=.o}
DEP_B =		${FILES_B:.c=.d}

${NAME}: 
		${CC} ${CFLAGS} -c ${FILES} -I${DOT_H}
		${AR} ${NAME} ${MAN}

bonus: 
		${CC} ${CFLAGS} -c ${FILES_B} -I${DOT_H}
		${AR} ${NAME} ${BON}

all: ${NAME}

clean:
	${RM} ${MAN} ${BON} $(DEP) $(DEP_B)

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: bonus all clean fclean re

-include $(DEP)
-include $(DEP_B)