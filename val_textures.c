#include "cub3d.h"

/* void mlx_start_map(t_map *map)
{
    char    *line;
	int 	idx;
	int		flag;

	int *textures = malloc(sizeof(int) * 6); //HACERLE FREEEEEE
	flag = 0;
    line = get_next_line(map->fd);
    while (line)
    {
		idx = 0;
		while (line[idx] == ' ')
			idx++;
		//printf("line es %s", line + idx);

        if (ft_strncmp(&line[idx], "NO ", 3) == 0)
			textures[NO]++;
		else if (ft_strncmp(&line[idx], "SO ", 3) == 0)
			textures[SO]++;
		else if (ft_strncmp(&line[idx], "EA ", 3) == 0)
			textures[EA]++;
		else if (ft_strncmp(&line[idx], "WE ", 3) == 0)
			textures[WE]++;
		else if (ft_strncmp(&line[idx], "C ", 2) == 0)
			textures[C]++;
		else if (ft_strncmp(&line[idx], "F ", 2) == 0)
			textures[F]++;
		else if (line[idx] > 32 && line[idx] <= 126 && line[idx] != 49)
			ft_print_error("Caracter no valido identificado");
		else if ((textures[NO] != 1 || textures[SO] != 1 || textures[EA] != 1 || 
				textures[WE] != 1 || textures[C] != 1 || textures[F] != 1) && line[idx] == 49)
				{
					printf("AAAAAAAA: %s\n", line);
					ft_print_error("un uno se ha perdido");
				}
		if ((textures[NO] == 1 || textures[SO] == 1 || textures[EA] == 1 || 
		textures[WE] == 1 || textures[C ]== 1 || textures[F ]== 1) && line[idx] == 49 && flag == 0)
		{
			//printf("LAST LINE: %s\n", line);
			map->line_start_map = ft_strdup(line); //Free this at some point
			flag = 1;
		}
		free(line);
        line = get_next_line(map->fd);
		if (flag == 0)
			map->start_line++;
    }
	if (textures[NO] != 1 || textures[SO] != 1 || textures[EA] != 1 || 
		textures[WE] != 1 || textures[C] != 1 || textures[F] != 1)
		ft_print_error("falta o sobra info\n");
	printf("NO es %d\n", textures[NO]);
	printf("SO es %d\n", textures[SO]);
	printf("EA es %d\n", textures[EA]);
	printf("WE es %d\n", textures[WE]);
	printf("C es %d\n", textures[C]);
	printf("F es %d\n", textures[F]);
} */