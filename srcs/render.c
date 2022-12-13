#include	"../header/structs.h"
#include	"../header/minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bit_per_pix / 8));
	*(unsigned int*)dst = color;
}

void	render(t_data *data)
{
	int pixel_x;
	int pixel_y;

	pixel_y = 0;
	while (pixel_y < HEIGHT)
	{
		pixel_x = 0;
		while (pixel_x < WIDTH)
		{
			my_mlx_pixel_put(data, pixel_x, pixel_y, JUNGLE);
			pixel_x++;
		}
		pixel_y++;
	}
}