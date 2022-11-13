# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akazarya <akazarya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 20:20:08 by akazarya          #+#    #+#              #
#    Updated: 2022/04/07 01:15:06 by akazarya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

LIBFT = 		../libft/libft.a
LIBFT_DIR =		-C .././libft
NAME =			libftprintf.a
CC =			cc
CFLAGS =		-Wall -Wextra -Werror
RM =			/bin/rm -f
#OPTION =		-I ft_printf.h
SRCS =			ft_printf.c ft_printf_nbr.c ft_printf_hex.c \
			ft_printf_str.c ft_flags1.c ft_flags2.c
OBJS =			${SRCS:.c=.o}
BONUS_OBJS =	${BONUS:.c=.o}

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	
all: 		${NAME}

$(NAME):	${OBJS}
			$(MAKE) bonus ${LIBFT_DIR}
			cp ${LIBFT} $(NAME)
			ar rcs ${NAME} ${OBJS}
			@echo "$(GREEN)${NAME} compiled!$(DEF_COLOR)"

run:		all
			${CC} ${CFLAGS} ${NAME} && ./a.out

clean:
			$(MAKE) clean ${LIBFT_DIR}
			@${RM} ${OBJS} ${BONUS_OBJS}
			@echo "${YELLOW}Libs *.o Cleaned!$(DEF_COLOR)"

fclean: clean
			$(MAKE) fclean ${LIBFT_DIR}
			@${RM} ${NAME} a.out
			@echo "${YELLOW}Libs Cleaned!$(DEF_COLOR)"

re: fclean all

bonus:	$(NAME)

.PHONY:		all clean fclean re bonus run