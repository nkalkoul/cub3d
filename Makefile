SRCS = $(addprefix srcs/, parsing.c main.c utils.c utils_bis.c parsing_bis.c parsing_fill_param.c\
		parsingmap.c parsingmap_bis.c utils_tres.c)
CC = cc -g3 #-Wall -Werror -Wextra -g3
DIRLIB = ./libft

LIBFT = $(DIRLIB)/libft.a

NAME = cub3D
OBJS_DIR = .obj
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully!"


$(LIBFT):
	@make -sC $(DIRLIB)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o : srcs/%.c | $(OBJS_DIR)
	@$(CC) -c $< -o $@ -Imlx

clean :
	@make fclean -sC $(DIRLIB)
	@rm -rf $(OBJS_DIR)

fclean : clean
	@rm -f $(NAME)
	@echo "🧽 Fully cleaned $(NAME)"

re : fclean all
