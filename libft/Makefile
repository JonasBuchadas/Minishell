### COMPILATION ###
CC=		gcc
CFLAGS=	-Wall -Werror -Wextra -g

### LIBRARY ###
NAME=	libft.a

### PATHS ###
INCL_PATH=	incl/
SRCS_PATH=	srcs/
OBJS_PATH=	objs/

### SOURCE FILES ###
SRC=	ft_atoi.c \
		ft_atol.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_sort_int_tab.c \
		ft_min_int.c \
		ft_max_int.c \
		ft_get_next_line.c \
		ft_strequal.c \
		ft_strarray_clear.c \
		ft_strdel.c \
		ft_memdel.c
BONUS=	ft_lstnew.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c
CLISTS=	ft_cdlstnew.c \
		ft_cdlstsize.c \
		ft_cdlstlast.c \
		ft_cdlstadd_front.c \
		ft_cdlstadd_back.c \
		ft_cdlstdelone.c \
		ft_cdlstclear.c \
		ft_cdlstiter.c
SRCS=		$(addprefix $(SRCS_PATH), $(SRC))
SRCS_BONUS=	$(addprefix $(SRCS_PATH), $(SRC) $(BONUS) $(CLISTS))

### OBJECT FILES ###
OBJ=		$(SRC:.c=.o)
OBJ_BONUS=	$(BONUS:.c=.o)
OBJ_CLISTS=	$(CLISTS:.c=.o)
OBJS=		$(addprefix $(OBJS_PATH), $(OBJ))
OBJS_BONUS=	$(addprefix $(OBJS_PATH), $(OBJ) $(OBJ_BONUS) $(OBJ_CLISTS))

### INCLUDES ###
INC=	-I $(INCL_PATH)

### IMPLICIT RULES ###
%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

### ACTIVE RULES ###
all: $(OBJS_PATH) $(OBJS)
	@ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_PATH) $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS)

$(OBJS_PATH):
	@mkdir -p $@

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

### NORMINETTE ###
norm:
	@norminette -R CheckForbiddenSourceHeader $(SRCS_PATH)
	@norminette -R CheckForbiddenSourceHeader $(INCL_PATH)
	@norminette -R CheckDefine $(SRCS_PATH)
	@norminette -R CheckDefine $(INCL_PATH)

### PHONY RULE ###
.PHONY:	all bonus clean fclean re norm

