SRCS = \
	srcs/parsing.c \
	srcs/main.c \
	srcs/utils.c \
	srcs/utils_bis.c \
	srcs/parsing_bis.c \
	srcs/parsing_fill_param.c \
	srcs/parsingmap.c \
	srcs/parsingmap_bis.c \
	srcs/utils_tres.c \
	srcs/ft_close.c \
	srcs/init_mlx.c \
	srcs/init_mlx_utils.c \
	srcs/init_mlx_utils_1.c \
	srcs/init_raycasting.c \
	srcs/exec/exec_general.c \
	srcs/exec/exec_raycasting_utils.c \
	srcs/exec/exec_render.c \
	srcs/exec/exec_render_helpers.c \
	srcs/move.c \
	srcs/move_utils.c

MLX_DIR = minilibx-linux
LIBFT_DIR = libft

MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

NAME = cub3D
OBJS_DIR = obj
OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

.PHONY: all clean fclean re libft mlx

all: $(NAME)

objects: $(OBJS)
	@printf "\033[32m[OK] Objects compiled\033[0m\n"

$(NAME): $(LIBFT) $(MLX) objects
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME) >/tmp/$(NAME).link.log 2>&1 || { printf "\033[31m[ERROR] Linking failed — see /tmp/%s.link.log\033[0m\n" "$(NAME)"; cat /tmp/$(NAME).link.log; false; }

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	@{ $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ >/tmp/compile.log 2>&1 || { printf "\033[31m[ERROR] Compiling %s failed\033[0m\n" "$<"; cat /tmp/compile.log; false; }; }

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)


$(LIBFT):
	@make -sC $(LIBFT_DIR) >/tmp/libft.build.log 2>&1 || { printf "\033[31m[ERROR] Building libft failed — see /tmp/libft.build.log\033[0m\n"; cat /tmp/libft.build.log; false; }
	@printf "\033[32m[OK] libft built\033[0m\n"


$(MLX):
	@make -sC $(MLX_DIR) >/tmp/minilibx.build.log 2>&1 || { printf "\033[31m[ERROR] Building minilibx failed — see /tmp/minilibx.build.log\033[0m\n"; cat /tmp/minilibx.build.log; false; }
	@printf "\033[32m[OK] minilibx built\033[0m\n"

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean >/dev/null 2>&1 || true
	@make -C $(MLX_DIR) clean >/dev/null 2>&1 || true

re: fclean all

