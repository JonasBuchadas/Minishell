### OPERATING SYSTEM ###
OS=			$(shell uname -s)

### EXECUTABLE ###
NAME=		minishell

### COMPILATION ###
CC=			gcc
CFLAGS=		-Wall -Werror -Wextra -g -fsanitize=address

### PATHS ###
LIBFT_PATH=	./libft/
INCL_PATH=	incl/
SRCS_PATH=	srcs/
SRCS_BT_PATH= srcs/builtins/
OBJS_PATH=	objs/
OBJS_BT_PATH= objs/builtins/

### SOURCE FILES ###
SRC_NAME=	$(NAME).c
SRC_BONUS=	$(NAME)_bonus.c
SRCS=		structs.c \
			create_tokens.c \
			expand_tokens.c \
			expand_tilde.c \
			create_commands.c \
			error_handling.c \
			iterables.c \
			utils.c \
			pipes.c \
			exec_cmds.c \
			input.c \
			envp.c \
			signal.c \
			builtins/builtin.c \
			builtins/echo.c \
			builtins/cd.c \
			builtins/pwd.c \
			builtins/env.c \
			builtins/export.c \
			builtins/unset.c \
			builtins/exit.c
SRCS_NAME=	$(addprefix $(SRCS_PATH), $(SRC_NAME) $(SRCS))
SRCS_BONUS=	$(addprefix $(SRCS_PATH), $(SRC_BONUS) $(SRCS))

### OBJECT FILES ###
OBJ_NAME=	$(SRC_NAME:.c=.o)
OBJ_BONUS=	$(SRC_BONUS:.c=.o)
OBJS=		$(SRCS:.c=.o)
OBJS_NAME=	$(addprefix $(OBJS_PATH), $(OBJ_NAME) $(OBJS))
OBJS_BONUS=	$(addprefix $(OBJS_PATH), $(OBJ_BONUS) $(OBJS))

### LIBFT ###
LIBFTMAKE=  make bonus --silent -C $(LIBFT_PATH)

### LINKS ###
LINKS=      -L$(LIBFT_PATH) -lft -L$(READLINE_DIR) -lreadline

### INCLUDES ###
ifeq ($(OS), Linux)
	READLINE_DIR	=	/usr/include/readline
else
	READLINE_DIR	=	~/.brew/opt/readline/lib
endif
INC=		-I $(LIBFT_PATH)$(INCL_PATH) -I $(INCL_PATH) -I $(READLINE_DIR)

### COLOURS ###
ifeq ($(OS), Linux)
	ECHO=	echo "
else
	ECHO=	echo "
endif
GREEN= $(addprefix $(ECHO), \033[1;32m)
RED= $(addprefix $(ECHO), \033[1;31m)
DEFAULT= \033[0m"

### IMPLICT RULES ###
%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

### ACTIVE RULES ###
all: $(NAME) ## compiles minishell with mandatory requirements

help:  ## show this help
	@echo "usage: make [target]"
	@echo ""
	@egrep "^(.+)\:\ .*##\ (.+)" ${MAKEFILE_LIST} | sed 's/:.*##/#/' | column -t -c 2 -s '#'

bonus: $(OBJS_PATH) $(OBJS_BT_PATH) $(OBJS_BONUS) ## compiles minishell with bonus requirements
	@$(LIBFTMAKE)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(INC) $(LINKS) -o $(NAME)
	@$(GREEN)$(NAME) Program created$(DEFAULT)

$(NAME): $(OBJS_PATH) $(OBJS_BT_PATH) $(OBJS_NAME)
	@$(LIBFTMAKE)
	@$(CC) $(CFLAGS) $(OBJS_NAME) $(INC) $(LINKS) -o $(NAME)
	@$(GREEN)$(NAME) Program created$(DEFAULT)

$(OBJS_PATH):
	@mkdir -p $@

$(OBJS_BT_PATH):
	@mkdir -p $@

clean: ## removes object files
	@make $@ --silent -C $(LIBFT_PATH)
	@rm -rf $(OBJS_PATH)
	@$(RED)Object files removed$(DEFAULT)

fclean: clean ## removes object files and binary
	@make $@ --silent -C $(LIBFT_PATH)
	@$(RED)Libft removed$(DEFAULT)
	@rm -f $(NAME)
	@$(RED)$(NAME) Program removed$(DEFAULT)

re: fclean all ## recompiles minishell

### NORMINETTE ###
norm: ## checks norminette requirements
	@norminette -R CheckForbiddenSourceHeader $(SRCS_PATH)
	@norminette -R CheckForbiddenSourceHeader $(INCL_PATH)
	@norminette -R CheckDefine $(SRCS_PATH)
	@norminette -R CheckDefine $(INCL_PATH)

### PHONY RULE ###
.PHONY:	all help bonus clean fclean re norm
