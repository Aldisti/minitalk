# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 15:18:48 by adi-stef          #+#    #+#              #
#    Updated: 2023/02/26 15:46:57 by adi-stef         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME	= client
SNAME	= server

CSRC	= client.c
SSRC	= server.c

BCSRC	= client_bonus.c
BSSRC	= server_bonus.c

COBJ	= ${CSRC:.c=.o}
SOBJ	= ${SSRC:.c=.o}

BCOBJ	= ${BCSRC:.c=.o}
BSOBJ	= ${BSSRC:.c=.o}

.o:.c
		${CC} -c $< -o ${<:.c=.o}

CC		= gcc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

$(CNAME):	${COBJ} ${SOBJ}
		make -C ./printf
		${CC} ${FLAGS} ${COBJ} printf/libftprintf.a -o ${CNAME}
		${CC} ${FLAGS} ${SOBJ} printf/libftprintf.a -o ${SNAME}

all:		${CNAME} bonus

bonus:		${BCOBJ} ${BSOBJ}
		make -C ./printf
		${CC} ${FLAGS} ${BCOBJ} printf/libftprintf.a -o client_bonus
		${CC} ${FLAGS} ${BSOBJ} printf/libftprintf.a -o server_bonus

clean:
		make clean -C ./printf
		${RM} ${COBJ} ${SOBJ}
		${RM} ${BCOBJ} ${BSOBJ}

fclean:		clean
		make fclean -C ./printf
		${RM} ${CNAME} ${SNAME}
		${RM} client_bonus server_bonus

re:			fclean all

.PHONY:	all clean fclean bonus re
