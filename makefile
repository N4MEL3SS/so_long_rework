#	PROGRAM_NAMES
NAME_MAN = so_long
NAME_BONUS = so_long_bonus
OS = $(shell uname)


#	FLAG_COMPILATION
CC = clang
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIR)
FRAME_LINUX = -lXext -lX11
FRAME_MAC = -framework OpenGL -framework AppKit

ifeq ($(OS), Linux)
	MLX = ./mlx_linux/
	SRC_OS = key_control_linux.c
	MLX_LINK = -L $(MLX) -l mlx $(FRAME_LINUX)
else
	MLX = ./mlx_mac/
	SRC_OS = key_control_mac.c
	MLX_LINK = -L $(MLX) -l mlx $(FRAME_MAC) -DMAC
endif


#	HEADERS
HEADERS_LIST =	error_msg.h		\
				game.h			\
				get_next_line.h	\
				keycode_mac.h	\
				map.h			\
				player.h		\
				sprite.h		\
				utils.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))


#	SOURCE
SRC_CORE_DIR = ./source/core/
SRC_CORE = 	animation.c				\
			get_next_line.c			\
			get_next_line_utils.c	\
			hook.c					\
			init_map.c				\
			map_parser.c			\
			move_player.c			\
			pre_render.c			\
			utils1.c				\
			utils2.c
SRC_MAN_DIR = ./source/mandatory/
SRC_MAN = 	close.c					\
			init_game.c				\
			init_sprite.c			\
			main.c					\
			map_check.c				\
			print_move.c			\
			render_frame.c
SRC_BONUS_DIR = ./source/bonus/
SRC_BONUS = close_bonus.c			\
			init_game_bonus.c		\
			init_sprite_bonus.c		\
			main_bonus.c			\
			map_check_bonus.c		\
			move_ghost_bonus.c		\
			print_move_bonus.c		\
			render_frame_bonus.c
SRCS_CORE = $(addprefix $(SRC_CORE_DIR), $(SRC_CORE) $(SRC_OS))
SRCS_MAN = $(addprefix $(SRC_MAN_DIR), $(SRC_MAN))
SRCS_BONUS = $(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS))


#	OBJECT_FILES
OBJS_DIR = ./objs/
OBJS_DIR_NAME = objs
OBJS_OS = $(patsubst %.c, %.o, $(SRC_OS))
OBJS_CORE = $(patsubst %.c, %.o, $(SRC_CORE))
OBJS_MAN = $(patsubst %.c, %.o, $(SRC_MAN))
OBJS_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))
OBJS_C = $(addprefix $(OBJS_DIR), $(OBJS_CORE) $(OBJS_OS))
OBJS_M = $(addprefix $(OBJS_DIR), $(OBJS_MAN))
OBJS_B = $(addprefix $(OBJS_DIR), $(OBJS_BONUS))


#	COLORS
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
END = \033[0m

all: $(NAME_MAN)

bonus: $(NAME_BONUS)

$(NAME_MAN): $(OBJS_DIR) $(OBJS_C) $(OBJS_M)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS_C) $(OBJS_M) $(MLX_LINK) -o $(NAME_MAN)
	@echo "$(GREEN) $(NAME_MAN) created. $(END)"

$(NAME_BONUS): $(OBJS_DIR) $(OBJS_C) $(OBJS_B)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJS_C) $(OBJS_B) $(MLX_LINK) -o $(NAME_BONUS)
	@echo "$(GREEN) $(NAME_BONUS) created. $(END)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR_NAME)
	@echo "$(BLUE) Object files directory was created. $(END)"

$(OBJS_DIR)%.o : $(SRC_CORE_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJS_DIR)%.o : $(SRC_MAN_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(OBJS_DIR)%.o : $(SRC_BONUS_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) -DSTR_Y=20 -DSTR_X=6 $< -o $@

clean:
	@rm -rf $(OBJS_C)
	@rm -rf $(OBJS_M)
	@rm -rf $(OBJS_B)
	@echo "$(RED) Object files were deleted. $(END)"

fclean: clean
	@rm -f $(NAME_MAN)
	@echo "$(RED) $(NAME_MAN) was deleted. $(END)"
	@rm -f $(NAME_BONUS)
	@echo "$(RED) $(NAME_BONUS) was deleted. $(END)"

re: fclean all

re_bonus: fclean bonus

re_all: fclean all bonus

.PHONY: all bonus clean fclean re re_bonus re_all
