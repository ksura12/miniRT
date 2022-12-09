#include	"../header/structs.h"
#include	"../header/minirt.h"

int	parse_line(char *line, t_data *data)
{
	char	**splitted;

	splitted = ft_split(line, ' ');
	if (!ft_strncmp(splitted[0], "A\0", 2))
		init_A(data, splitted);
/*	else if (!ft_strncmp(splitted[0], "C\0", 2))
		init_C(splitted);
	else if (!ft_strncmp(splitted[0], "L\0", 2))
		init_L(splitted);
	else if (!ft_strncmp(splitted[0], "sp\0", 3))
	else if (!ft_strncmp(splitted[0], "cy\0", 3))
	else if (!ft_strncmp(splitted[0], "pl\0", 3))
	else if (splitted[0][0] == '\n')
	else
	{
		printf("ERROR, unidentified element.\n");
		freeing_dpointer(splitted);
		return (0);
	}*/
	freeing_dpointer(splitted);
	return (1);
}

void	init_A(t_data *data, char **splitted)
{
	(void)splitted;
	t_amb_light amb;

	amb = data->elements->amb_light;
	if (splitted[1])
	amb->lratio = ;
	amb->color->r = ;
	amb->color->g = ;
	amb->color->b = ;

/*
	identifier: A
∗ ambient lighting ratio in range [0.0,1.0]: 0.2
∗ R,G,B colors in range [0-255]: 255, 255, 255
*/
}

int	open_file(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0); //TODO- Error messaga for file opening
	return (fd);
}

int	init_elements(char **argv, t_data *data)
{
	char	*line;
	int		fd;

	fd = open_file(argv);
	line = get_next_line(fd);
	while (line)
	{
		if (!parse_line(line, data))
		{
			free(line);
			close(fd); 
			return (0);//TODO- Error message for parsing
		}
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

int	load_input(int argc, char **argv, t_data *data)
{
	int 	len;

	if (argc != 2)
		return (0);
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 3], ".rt", 3) != 0)
		return (0);
	if (!counting_elements(argv, data))
	{
		printf("check your input\n");
		exit(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
//	data->mlx = mlx_init();
//	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "miniRT");
//	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
//	data->addr = mlx_get_data_addr(data->img, &data->bit_per_pix, &data->line_len, &f->endian);
	init_counter(data);
//	controls(data);
//	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
//	mlx_loop(data->mlx);
	return (load_input(argc, argv, data));

	// data = load_input(argc, argv);
	// data->win_ptr =mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "miniRT");

}
