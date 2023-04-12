#include "../fractol.h"

void	wrong_input(void)
{
	printf("Unrecognized input!!! \nThis program only takes the ");
	printf("parameters: \"julia\", \"mandelbrot\" or ");
	printf("\"tricorn\" to display these fractals!\n");
	exit(1);
}

void	fractalsetup(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	fractal->img = mlx_new_image(fractal->mlx, fractal->width, fractal->height);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	if (!ft_strcmp(fractal->name, "julia"))
		juliaset(fractal);
	else if (!ft_strcmp(fractal->name, "mandelbrot"))
		mandelbrotset(fractal);
	else if (!ft_strcmp(fractal->name, "tricorn"))
		tricorn(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

//free memory from the linked list; 
int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "mandelbrot"))
			mandelbrot_param(&fractal, argv[1]);
		else if (!ft_strcmp(argv[1], "julia"))
			julia_param(&fractal, argv[1]);
		else if (!ft_strcmp(argv[1], "tricorn"))
			tricorn_param(&fractal, argv[1]);
		else
			wrong_input();
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
		wrong_input();
	return (0);
}
