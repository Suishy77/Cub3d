NAME		=	libft.a

SRCS = ft_printf.c ft_printf_utils.c \
ft_puthex.c \
ft_atoll.c \
ft_swap.c \
ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isascii.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
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
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
get_next_line.c \
get_next_line_utils.c


DIR_SRCS	=	srcs/
DIR_OBJS	=	objs/

SOURCE		=	$(addprefix ${DIR_SRCS}, ${SRCS})
OBJS		=	$(subst ${DIR_SRCS}, ${DIR_OBJS}, $(SOURCE:.c=.o))

INCLUDES	=	-I includes

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(DIR_OBJS)%.o :	$(DIR_SRCS)%.c | $(DIR_OBJS)
			@ $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJS):
			@mkdir -p $(DIR_OBJS)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

clean:
			@rm -rf $(OBJS)
			@rm -rf $(DIR_OBJS)

fclean:		clean
			@ rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
