#Variables

LIB_DIR		= libs/printf
NAME		= cub3D
SRC_DIR		= src
CC			= cc
CFLAGS		= -Wall -Wextra $(INCLUDE)
RM			= rm -rf
SRC_FILES	= $(wildcard $(SRC_DIR)/*.c)

ifeq ($(shell uname), Linux)
 MLXFLAGS	= -lmlx_Linux -L/usr/lib -lmlx -lXext -lX11 -lm
 LIBMLX_DIR	= libs/minilibx_linux
 LIBMLX		= libmlx_Linux.a
 SRCS	= $(subst  $(SRC_DIR)/Util_Mac.c,,$(wildcard $(SRC_DIR)/*.c))
else
 MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
 LIBMLX_DIR	= libs/minilibx_mms
 LIBMLX		= libmlx.dylib
 SRCS	= $(subst  $(SRC_DIR)/Util_linux.c,,$(wildcard $(SRC_DIR)/*.c))
endif

OBJS		= $(SRCS:.c=.o)
INCLUDE	= -I includes -I $(LIBMLX_DIR)
LINKERS		= -L $(LIB_DIR) -lftprintf -L $(LIBMLX_DIR)

#Colors

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

#Arguments for run
ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif


all:		$(NAME)
bonus:		all
run:		all
			@echo "$(GREEN)runing prog $(NAME).$(DEF_COLOR)"
			./$(NAME) $(RUN_ARGS)

.c.o:
			@$(CC) $(CFLAGS) -I/usr/include -O3 -o $@ -c $<

$(NAME):	$(OBJS)
			@$(MAKE) bonus -C ./${LIB_DIR}
			@$(MAKE) -C ./$(LIBMLX_DIR)
			@cp $(LIBMLX_DIR)/$(LIBMLX) $(LIBMLX)
			@$(CC) $(CFLAGS) $(OBJS) $(LINKERS) $(MLXFLAGS) -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

clean:
			@$(MAKE) clean -C ./${LIB_DIR}
			@$(MAKE) clean -C ./${LIBMLX_DIR}
			@$(RM) $(LIBMLX)
			@$(RM) $(OBJS)
			@echo "$(YELLOW)Cleaned!$(DEF_COLOR)"

fclean: clean
			@$(MAKE) fclean -C ./${LIB_DIR}
			@$(RM) $(NAME)
			@echo "$(YELLOW)All cleaned!$(DEF_COLOR)"

re: fclean all

.PHONY:		all clean fclean re bonus run