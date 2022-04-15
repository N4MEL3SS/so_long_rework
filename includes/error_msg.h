#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define ERR_MALLOC "Memory not allocated!"
# define ERR_ARG0 	"You must specify the path to the map!"
# define ERR_ARGS	"Too many arguments!"
# define ERR_FILE 	"File open error!"
# define ERR_READ 	"File reading error!"
# define ERR_EXT	"Invalid file type! The file type must be '*.ber'."
# define ERR_LEN	"The file is not recognized!"

# define ERR_MAP_W	"The map must be closed!"
# define ERR_MAP_R	"The map must be rectangular!"
# define ERR_MAP_S	"Unexpected symbol(s) in map!"
# define ERR_MAP_E	"Invalid number of exits!"
# define ERR_MAP_P	"Invalid number of players!"
# define ERR_MAP_C	"There should be at least one collectible!"
# define ERR_MAP_PASS "There is no passage to the exit!"

/* Foreground colors */
# define GREEN "\e[0;32m"
# define RED "\e[0;31m"
# define YELLOW "\e[0;33m"
# define COLOR_END "\e[0;39m"
# define COLOR_SIZE 7

#endif //ERROR_MSG_H
