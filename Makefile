# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibenhaim <ibenhaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 13:10:41 by ibenhaim          #+#    #+#              #
#    Updated: 2023/04/27 13:11:35 by ibenhaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
FLAGS		=	-Wall -Werror -Wextra -g3

HEADER		=	pipex.h
SRCS		=	pipex.c parsing.c utils.c get_env.c processes.c

BONUS		=	pipex_bonus.c parsing.c utils.c get_env.c processes.c

INCLUDES	=	includes/
DIR_LIB		=	libft/

OBJS		= 	${SRCS:.c=.o}

OBONUS		=	${BONUS:.c=.o}

LFTNAME		= 	libft.a

%.o:%.c ${HEADER} $(DIR_LIB)libft.h
				${CC} ${FLAGS} -c $< -o $@

${NAME}		: ${OBJS} ${HEADER} $(DIR_LIB)*.c $(DIR_LIB)libft.h
				make -C libft
				${CC} ${FLAGS} ${OBJS} ${DIR_LIB}${LFTNAME} -o ${NAME}

all : ${NAME}

clean:
				rm -f ${OBJS} 
				rm -f ${OBONUS}
				${MAKE} -C ${DIR_LIB} clean

fclean:	clean
				rm -f ${NAME}
				${MAKE} -C ${DIR_LIB} fclean
				
bonus: 	${OBONUS} ${HEADER} $(DIR_LIB)*.c $(DIR_LIB)libft.h
				make -C libft
				${CC} ${FLAGS} ${OBONUS} ${DIR_LIB}${LFTNAME} -o ${NAME}


re: fclean all

.PHONY:	all clean fclean re libft
