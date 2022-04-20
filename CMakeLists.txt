cmake_minimum_required(VERSION 3.21)
project(so_long_rework C)

set(CMAKE_C_STANDARD 99)

include_directories("includes/")
include_directories("mlx_mac/")

set(INC includes/game.h
		includes/map.h
		includes/get_next_line.h
		includes/keycode_mac.h
		includes/keycode_linux.h
		includes/sprite.h
		includes/utils.h
		includes/player.h)

set(SRC source/bonus/main.c
		source/bonus/map_check.c
		source/bonus/map_parser.c
		source/bonus/get_next_line.c
		source/bonus/get_next_line_utils.c
		source/bonus/utils1.c
		source/bonus/utils2.c
		source/bonus/init_game.c
		source/bonus/render_frame.c
		source/bonus/hook.c
		source/bonus/close.c
		source/bonus/init_map.c
		source/bonus/animation.c
		source/bonus/move_player.c
		source/bonus/init_sprite.c
		source/bonus/move_ghost.c)

find_library(MLX mlx mlx_mac/)
message(${MLX})

add_executable(so_long_rework ${SRC} ${INC})
target_link_libraries(so_long_rework ${MLX})
target_link_libraries(so_long_rework "-framework OpenGL")
target_link_libraries(so_long_rework "-framework AppKit")
