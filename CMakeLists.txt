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

set(SRC source/main.c
		source/map_check.c
		source/map_parser.c
		source/get_next_line.c
		source/get_next_line_utils.c
		source/utils1.c
		source/utils2.c
		source/init_game.c
		source/render_frame.c
		source/hook.c
		source/close.c
		source/init_map.c
		source/animation.c
		source/move_player.c
		source/init_sprite.c
		source/move_ghost.c)

find_library(MLX mlx mlx_mac/)
message(${MLX})

add_executable(so_long_rework ${SRC} ${INC})
target_link_libraries(so_long_rework ${MLX})
target_link_libraries(so_long_rework "-framework OpenGL")
target_link_libraries(so_long_rework "-framework AppKit")
