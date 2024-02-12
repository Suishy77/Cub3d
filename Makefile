NAME	=	cub3D

INCL	=	includes

LIB_DIR	=	libft
LIB		=	$(LIB_DIR)/libft.a

S_DIR	=	srcs
O_DIR	=	obj

SRC		=	parse.c			utils.c\
			check_data.c	check_txt.c\
			exec.c			check_map.c\
			free.c			check_color.c\
			init_struct.c	init_player.c\
			raycast.c		mlx_func.c\
			textures.c		main.c\

OBJ		=	$(SRC:.c=.o)

SRCS	=	$(addprefix $(S_DIR)/, $(SRC))
OBJS	=	$(addprefix $(O_DIR)/, $(OBJ))

CFLAGS	=	-g -Wall -Wextra -Werror -I $(INCL) -I $(I_MLX) -I $(LIB_DIR)
CC		=	cc

UNAME	=	$(shell uname)

ifeq ($(UNAME),Darwin)

I_MLX	=	minilibx_opengl

LFLAGS	=	-framework OpenGL -framework AppKit

else

I_MLX	=	minilibx_linux

LFLAGS	=	-lXext -lX11 -lm

endif

MLX_NAME =	$(I_MLX)/libmlx.a

RM		=	rm -rf

HEADER	=	$(INCL)/cub3D.h
HEAD	=	-I$(INCL) -Ilibft/includes

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_DIR)
	@make -C $(I_MLX)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX_NAME) $(LFLAGS) -o $(NAME)

$(O_DIR)/%.o: $(S_DIR)/%.c | $(O_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(O_DIR):
	@mkdir -p $(O_DIR)

clean:
	@make clean -C $(LIB_DIR)
	@$(RM) $(OBJS)
	@$(RM) $(O_DIR)

fclean:	clean
	@make fclean -C $(LIB_DIR)
	@$(RM) $(LIB)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
