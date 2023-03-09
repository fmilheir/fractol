
#include "../fractol.h"

void    wrong_input()
{
    printf("Unrecognized input!!! \nThis program only takes the ");
	printf("parameters: \'julia\', \'mandelbrot\' or ");
	printf("\'burning\' to display any of these fractal types!");
    exit(1);
}

void	fractalsetup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	else if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	else if (!ft_strncmp(fractal->name, "burning", 7))
		printf("place new fractal");
		//burningset(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}


//I have to ke of this and put it in the correct place
/*void	miniburning(int x, int y, t_fractal *burning)
{
	int		i;
	double	z0;
	double	z1;
	double	tempz0;

	i = 0;
	burning->c.x = (x + burning->xarrow) / burning->zoom
		* (1.0 + 2.5) / (burning->width - 1) - 2.5;
	burning->c.y = (y + burning->yarrow) / burning->zoom
		* (1.0 + 1.0) / (burning->width - 1) - 1.0;
	z0 = burning->c.x;
	z1 = burning->c.y;
	while (i++ < burning->iterations)
	{
		tempz0 = z0 * z0 - z1 * z1 + burning->c.x;
		z1 = fabs(2.0 * z0 * z1) + burning->c.y;
		z0 = tempz0;
		if (z0 * z0 + z1 * z1 > 4)
		{
			my_mlx_pixel_put(burning, (int) x, (int) y, (burning->color * i));
			break ;
		}
	}
}*/

//free memory from the linked list; 
int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}


int main(int argc, char **argv)
{
    //declaring struct
    t_fractal   fractal;

    //declare main struct here
    if (argc == 2)
    {
        if (!ft_strcmp(argv[1], "mandelbrot"))
			mandelbrot_param(&fractal, argv[1]);
        else if(!ft_strcmp(argv[1], "julia"))
			julia_param(&fractal, argv[1]);
        else if(!ft_strcmp(argv[1], "burning"))
            printf("work as well for burning");
		fractal.mlx = mlx_init();
		fractal.win = mlx_new_window(fractal.mlx, fractal.width,
				fractal.height, fractal.name);
		fractal.img = mlx_new_image(fractal.mlx, fractal.width, fractal.height);
        mlx_key_hook(fractal.win, key_hook, &fractal);
		mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
		mlx_hook(fractal.win, 17, 1L << 17, close_game, &fractal);
		mlx_loop(fractal.mlx);
    }
    else
    {
        printf("it is working, just 1 arg");
    }
    return (0);
}