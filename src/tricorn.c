#include "../fractol.h"

///this fractol is just a distorcion of the mandelbrot fractal/

void	minitricorn(int x, int y, t_fractal *tricorn)
{
	int		i;
	double	z0;
	double	z1;
	double	tempz0;

	i = 0;
	tricorn->c.x = (x + tricorn->xarrow) / tricorn->zoom
		* (0.47 + 2.0) / (tricorn->width - 1) - 2.0;
	tricorn->c.y = (y + tricorn->yarrow) / tricorn->zoom
		* (1.12 + 1.12) / (tricorn->width - 1) - 1.12;
	z0 = tricorn->c.x;
	z1 = tricorn->c.y;
	while (i++ < tricorn->iterations)
	{
		tempz0 = z0 * z0 - z1 * z1 + tricorn->c.x;
		z1 = -2.0 * z0 * z1 + tricorn->c.y;
		z0 = tempz0;
		if (z0 * z0 + z1 * z1 > 4)
		{
			my_mlx_pixel_put(tricorn, (int) x, (int) y, (tricorn->color * i));
			break ;
		}
	}
}

void	tricorn(t_fractal *tricorn)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= tricorn->width)
	{
		y = -1;
		while (++y <= tricorn->height)
		{
			minitricorn(x, y, tricorn);
		}
	}
}
