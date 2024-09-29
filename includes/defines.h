#ifndef DEFINES_H
# define DEFINES_H

# define VAL_CHAR	" 01NESW"
# define OPEN_WALL	" 1X\n"
# define MAP_mlx	"01P"
# define PLAYER_N	'N'
# define PLAYER_E	'E'
# define PLAYER_S	'S'
# define PLAYER_W	'W'
# define PLAYER_mlx 'P'
# define WALL		'1'

//Key hooks
# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2

# define UP			126
# define LEFT		123
# define DOWN		125
# define RIGHT		124
# define DESTROY 	17

# define S_W	1280
# define S_H	720

//Error states
# define EMPTY_LINE		-1
# define EXTRA_START	-2
# define START_MISSING	-3
# define WRONG_CHAR		-4

#endif