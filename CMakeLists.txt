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
		includes/utils.h
		includes/sprite.h
		includes/player.h)

set(SRC source/main.c
		source/check_map.c
		source/map_parser.c
		source/get_next_line.c
		source/get_next_line_utils.c
		source/utils1.c
		source/utils2.c
		source/game_init.c
		source/render_frame.c
		source/hook.c
		source/close.c
		source/map_init.c
		source/key_control.c)

find_library(MLX mlx mlx_mac/)
message(${MLX})

add_executable(so_long_rework ${SRC} ${INC})
target_link_libraries(so_long_rework ${MLX})
target_link_libraries(so_long_rework "-framework OpenGL")
target_link_libraries(so_long_rework "-framework AppKit")
