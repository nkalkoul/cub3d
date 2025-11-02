SRCS = $(addprefix srcs/, parsing.c main.c utils.c utils_bis.c parsing_bis.c parsing_fill_param.c\
		parsingmap.c parsingmap_bis.c utils_tres.c init_mlx.c)
CC = cc -g3 -Wall -Werror -Wextra -g3
DIRLIB = ./libft

LIBFT = $(DIRLIB)/libft.a

NAME = cub3D
OBJS_DIR = .obj
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) -L./minilibx-linux  -lmlx -lX11 -lXext 
	@echo "✅ $(NAME) compiled successfully!"


$(LIBFT):
	@make -sC $(DIRLIB)
	@make -sC ./minilibx-linux

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : srcs/%.c | $(OBJS_DIR)
	@$(CC) -c $< -o $@
clean :
	@make fclean -sC $(DIRLIB)
	make clean -C ./minilibx-linux
	@rm -rf $(OBJS_DIR)

fclean : clean
	@rm -f $(NAME)
	@echo "🧽 Fully cleaned $(NAME)"

re : fclean all
