#include "../fractol.h"

void	mandelbrot_param(t_fractal *fractal, char *name)
{	
	fractal->width = 1280;
	fractal->height = 720;
	fractal->iterations = 150;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 270;
	fractal->color = 0xccf1ff;
	fractal->name = name;
}

void	julia_param(t_fractal *fractal, char *name)
{
	fractal->width = 1280;
	fractal->height = 720;
	fractal->c.x = -0.7;
	fractal->c.y = 0.27015;
	fractal->radius = 3;
	fractal->iterations = 150;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 0;
	fractal->color = 0xccf1ff;
	fractal->name = name;
}

void	tricorn_param(t_fractal *fractal, char *name)
{
	fractal->width = 1280;
	fractal->height = 720;
	fractal->iterations = 150;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->xarrow = 0;
	fractal->yarrow = 270;
	fractal->color = 0xccf1ff;
	fractal->name = name;
}
