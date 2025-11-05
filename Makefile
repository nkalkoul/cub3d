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
	srcs/init_mlx.c \
	srcs/init_mlx_utils.c \
	srcs/init_raycasting.c \
	srcs/exec/exec_general.c \
	srcs/exec/exec_raycasting_utils.c \
	srcs/exec/exec_render.c \
	srcs/move.c

MLX_DIR = minilibx-linux
LIBFT_DIR = libft

MLX = $(MLX_DIR)/libmlx.a
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -Iincludes -I$(LIBFT_DIR) -I$(MLX_DIR)

CC = cc -g3
CFLAGS = #-Wall -Wextra -Werror -g3

NAME = cub3D
OBJS_DIR = obj
OBJS = $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRCS))

TOTAL := $(words $(SRCS))
BUILD_DIR := .build
SCRIPTS = scripts

.PHONY: all clean fclean re libft mlx obj

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS) | $(OBJS_DIR) $(BUILD_DIR)
	@printf "\033[35m[BUILD] Linking (%d objects)...\033[0m\r" "$(words $(OBJS))"
	@{ $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -lXpm -lm -lz -lbsd -o $(NAME) >/tmp/$(NAME).link.log 2>&1 & pid=$$!; \
	 i=0; chars='|/-\\'; \
	 while kill -0 $$pid 2>/dev/null; do \
		 idx=$$(expr $$i % 4 + 1); \
		 ch=$$(printf "%s" "$$chars" | cut -c $$idx); \
		 printf "\r[LINK] %s %s" "$(NAME)" "$$ch"; \
		 i=$$((i+1)); sleep 0.12; \
	 done; \
	 wait $$pid || (printf "\n\033[31m[ERROR] Linking failed — showing verbose output:\033[0m\n"; cat /tmp/$(NAME).link.log; false); \
	 printf "\r\033[35m[OK] %s prêt\033[0m\n" "$(NAME)"; }

obj:
	@mkdir -p $(OBJS_DIR)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@> $(BUILD_DIR)/count

$(OBJS_DIR)/%.o: %.c | obj $(BUILD_DIR)
	@mkdir -p $(@D)
	@sh $(SCRIPTS)/compile_and_report.sh "$(CC)" "$(CFLAGS) $(INCLUDES)" "$<" "$@" $(TOTAL) $(BUILD_DIR) || exit 1

$(LIBFT):
	@printf "Preparing dependencies...\r"
	@{ make -sC $(LIBFT_DIR) >/tmp/libft.build.log 2>&1 & pid=$$!; \
	 i=0; chars='|/-\\'; \
	 while kill -0 $$pid 2>/dev/null; do \
		 idx=$$(expr $$i % 4 + 1); \
		 ch=$$(printf "%s" "$$chars" | cut -c $$idx); \
		 printf "\rBuilding libft... %s" "$$ch"; \
		 i=$$((i+1)); sleep 0.12; \
	 done; \
	 wait $$pid || (printf "\nFailed building libft; retrying with verbose output...\n"; cat /tmp/libft.build.log; make -C $(LIBFT_DIR); false); }

$(MLX):
	@{ make -sC $(MLX_DIR) >/tmp/minilibx.build.log 2>&1 & pid=$$!; \
	 i=0; chars='|/-\\'; \
	 while kill -0 $$pid 2>/dev/null; do \
		 idx=$$(expr $$i % 4 + 1); \
		 ch=$$(printf "%s" "$$chars" | cut -c $$idx); \
		 printf "\rBuilding minilibx... %s" "$$ch"; \
		 i=$$((i+1)); sleep 0.12; \
	 done; \
	 wait $$pid || (printf "\nFailed building minilibx; retrying with verbose output...\n"; cat /tmp/minilibx.build.log; make -C $(MLX_DIR); false); }

clean:
	@rm -rf $(OBJS_DIR) $(BUILD_DIR)
	@make -s -C $(LIBFT_DIR) clean >/dev/null 2>&1 || true
	@make -s -C $(MLX_DIR) clean >/dev/null 2>&1 || true

fclean: clean
	@rm -f $(NAME)
	@make -s -C $(LIBFT_DIR) fclean >/dev/null 2>&1 || true
	@make -s -C $(MLX_DIR) fclean >/dev/null 2>&1 || true

re: fclean all
