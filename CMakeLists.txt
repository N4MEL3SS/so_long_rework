cmake_minimum_required(VERSION 3.21)
project(so_long_rework C)

set(CMAKE_C_STANDARD 99)

include_directories("includes/")
include_directories("mlx_mac/")

set(INC includes/game.h)

set(SRC source/main.c
		source/check.c
		source/utils1.c
		source/utils2.c)

find_library(MLX mlx mlx_mac/)
message(${MLX})

add_executable(so_long_rework ${SRC} ${INC})
target_link_libraries(so_long_rework ${MLX})
target_link_libraries(so_long_rework "-framework OpenGL")
target_link_libraries(so_long_rework "-framework AppKit")
