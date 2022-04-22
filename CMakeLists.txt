cmake_minimum_required(VERSION 3.21)
project(so_long_rework C)

set(CMAKE_C_STANDARD 99)

include_directories("includes/")
include_directories("mlx_mac/")
include_directories("mlx_linux/")

set(INC includes/game.h
		includes/map.h
		includes/get_next_line.h
		includes/sprite.h
		includes/utils.h
		includes/player.h)

set(SRC_CORE source/core/animation.c
		source/core/get_next_line.c
		source/core/get_next_line_utils.c
		source/core/hook.c
		source/core/init_map.c
		source/core/map_parser.c
		source/core/move_player.c
		source/core/utils1.c
		source/core/utils2.c)

set(SRC_MAN source/mandatory/close.c
		source/mandatory/init_game.c
		source/mandatory/init_sprite.c
		source/mandatory/main.c
		source/mandatory/map_check.c
		source/mandatory/print_move.c
		source/mandatory/render_frame.c)

set(SRC_BON source/bonus/close_bonus.c
		source/bonus/init_game_bonus.c
		source/bonus/init_sprite_bonus.c
		source/bonus/main_bonus.c
		source/bonus/map_check_bonus.c
		source/bonus/move_ghost_bonus.c
		source/bonus/print_move_bonus.c
		source/bonus/render_frame_bonus.c)

if (APPLE)
	set(OS_SRC includes/keycode_mac.h source/core/key_control_mac.c)
	find_library(MLX mlx mlx_mac/)
else()
	set(OS_SRC includes/linux/keycode_linux.h source/core/key_control_linux.c)
	find_library(MLX mlx mlx_linux/)
	find_library(XEXT Xext ${X11_Xext_LIB})
endif(APPLE)

message(${MLX})
message(${XEXT})
message(${OS_SRC})

add_executable(so_long_basic ${SRC_CORE} ${SRC_MAN} ${INC} ${OS_SRC})
target_link_libraries(so_long_basic PUBLIC ${MLX})

if (APPLE)
	target_link_libraries(so_long_basic "-framework OpenGL")
	target_link_libraries(so_long_basic "-framework AppKit")
else()
	target_link_libraries(so_long_basic PUBLIC X11)
	target_link_libraries(so_long_basic PUBLIC ${XEXT})
endif(APPLE)

add_executable(so_long_bonus ${SRC_CORE} ${SRC_BON} ${INC} ${OS_SRC})
target_link_libraries(so_long_bonus PUBLIC ${MLX})

if (APPLE)
	target_link_libraries(so_long_bonus "-framework OpenGL")
	target_link_libraries(so_long_bonus "-framework AppKit")
else()
	target_link_libraries(so_long_bonus PUBLIC X11)
	target_link_libraries(so_long_bonus PUBLIC ${XEXT})
endif(APPLE)
