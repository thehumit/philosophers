NAME		=	philo

SRCS	=	philo.c \
			handlers.c \


OBJS			= $(SRCS:.c=.o)

CC				= gcc	-Wall -Werror -Wextra
RM				= rm -f

NAME			= philo

all:			$(NAME)

$(NAME):		$(OBJS) $(LIB)
				$(CC) -o ${NAME} ${OBJS} ${LIBS}

%.o:	%.c Makefile philo.h
		$(CC) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
