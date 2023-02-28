#include "../include/fractol.h"

void    wrong_input()
{
    printf("Unrecognized input!!! \nThis program only takes the ");
	printf("parameters: \'julia\', \'mandelbrot\' or ");
	printf("\'burning\' to display any of these fractal types!");
    exit(1);
}

//I have to ke of this and put it in the correct place
void	miniburning(int x, int y, t_fractal *burning)
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
}




int main(int argc, char **argv)
{
    //declaring struct
    t_fractal   fractal;

    //declare main struct here
    if (argc == 2)
    {
        if (!ft_strcmp(argv[1], "mandelbrot"))
        {
            printf("this works just fine");
        }
        else if(!ft_strcmp(argv[1], "julia"))
        {
            printf("work as well for julia");
        }
        else if(!ft_strcmp(argv[1], "burning"))
        {
            printf("work as well for burning");
            burning_param(&fractal, argv[1]);
        }
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