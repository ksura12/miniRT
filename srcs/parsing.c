/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 05:25:26 by kaheinz           #+#    #+#             */
/*   Updated: 2023/01/07 05:25:30 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/structs.h"
#include	"../header/minirt.h"

int	parse_line(char *line, t_data *data, char **splitted)
{
	int	stop;

	stop = 1;
	splitted = ft_split(line, ' ');
	if (!ft_strncmp(splitted[0], "A\0", 2))
		stop = init_a(data, splitted);
	else if (!ft_strncmp(splitted[0], "C\0", 2))
		stop = init_camera(data, splitted);
	else if (!ft_strncmp(splitted[0], "L\0", 2))
		stop = init_l(data, splitted);
	else if (!ft_strncmp(splitted[0], "sp\0", 3))
		stop = init_s(data, splitted);
	else if (!ft_strncmp(splitted[0], "cy\0", 3))
		stop = init_cylinder(data, splitted);
	else if (!ft_strncmp(splitted[0], "pl\0", 3))
		stop = init_plane(data, splitted);
	freeing_dpointer(splitted);
	if (!stop)
		return (0);
	return (1);
}

int	check_arguments(int argc, char **argv)
{
	int	len;

	if (argc != 2)
		return (0);
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 3], ".rt", 3) != 0)
		return (0);
	return (1);
}

int	check_counter(t_data *data, char **argv)
{
	init_counter(data);
	if (!counting_elements(argv, data))
		return (0);
	return (1);
}

void	parsing(int argc, char **argv, t_data *data)
{
	int	fd;

	fd = -1;
	if (!check_arguments(argc, argv))
	{
		printf("Check your input.\n");
		exit(0);
	}	
	if (!struct_allocation(data))
	{
		printf("Allocation error.\n");
		exit(0);
	}	
	if (!check_counter(data, argv))
	{
		free_allocation(data);
		exit (0);
	}
	object_allocation(data);
	init_elements(argv, data, fd);
}
