#ifndef DEFINES_H
# define DEFINES_H

# define VAL_CHAR	" 01NESW"
# define P_STARTS	"NESW"
# define OPEN_WALL	" 1X\n"
# define MAP_mlx	"01P"
# define PLAYER_N	'N'
# define PLAYER_E	'E'
# define PLAYER_S	'S'
# define PLAYER_W	'W'
# define PLAYER_mlx	'P'
# define WALL		'1'

//Key hooks
# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

# define S_W	1920
# define S_H	1200

//Error states
//Could do error messages aswell?
# define EMPTY_LINE		-1
# define EXTRA_START	-2
# define START_MISSING	-3
# define WRONG_CHAR		-4

//TESTS
# define BLOCK_SIZE		16
# define MOVE_SPEED		1
# define ROTATION_SPEED	0.08
//I think this is 90
# define FOV			1.3962634016

#endif