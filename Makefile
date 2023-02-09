# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:10:41 by ibenhaim          #+#    #+#              #
#    Updated: 2023/02/09 12:41:43 by ibenhaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
FLAGS		=	-Wall -Werror -Wextra

HEADER		=	pipex.h
SRCS		=	pipex.c

INCLUDES	=	includes/
DIR_LIB		=	libft/

LIBFT		=	$(DIR_LIB)libft.a

OBJS		= 	${SRCS:.c=.o}

LFTNAME		= 	libft.a

%.o:%.c	${HEADER} ${DIR_LIB}libft.h
				${CC} ${FLAGS} -c $< -o $@

${NAME}		: $(LIBFT) ${OBJS}
				${CC} ${FLAGS} ${OBJS} ${DIR_LIB}${LFTNAME} -o ${NAME}

all : ${NAME}

$(LIBFT)	:
				${MAKE} -C ${DIR_LIB}

clean:
				rm -f ${OBJS} 
				${MAKE} -C ${DIR_LIB} clean

fclean:	clean
				rm -f ${NAME}
				${MAKE} -C ${DIR_LIB} fclean
				
re: fclean all

.PHONY:	all clean fclean re libft
