/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pc <pc@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:10:57 by pc                #+#    #+#             */
/*   Updated: 2024/10/28 18:10:57 by pc               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define VAL_CHAR	" 01NESWD"
# define P_STARTS	"NESW"
# define OPEN_WALL	" 1X\n"
# define CLOSED_MAP "0D"
# define MAP_MLX	"01PD"
# define PLAYER_N	'N'
# define PLAYER_E	'E'
# define PLAYER_S	'S'
# define PLAYER_W	'W'
# define PLAYER_MLX	'P'
# define DOOR		'D'

//Key hooks
# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_E		101

# define S_W		1920
# define S_H		1200

# define BLOCK_SIZE		64
# define BLOCK_SIZE_MAP	16
# define MOVE_SPEED		3
# define ROTATION_SPEED	0.10
# define NUM_RAYS		1920
# define FOV			1.3962634016

//Mouse
# define ANGLE_MAX 360.0f
# define ANGLE_MIN 0.0f
# define SMOOTHING_FACTOR 0.03f

#endif