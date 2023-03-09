#include "../fractol.h"

//this function is used in order to set the color of a pixel
//getting the addres of the beguining of the image(addr) go fowward in memory in order to find the pixel to modify
//divide by 8 in order to get the byte 
int	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

//add to complex numbers
t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}
//make squareroot of a complex number
t_complex	sqr(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

//l is the scaling factor
//l is the result of the multiplication of the height or width(the biggest one)
//
t_complex	mappoint(t_fractal *fractal, double x, double y)
{
	t_complex	c;
	double		l;

	if (fractal->width < fractal->height)
		l = fractal->height * fractal->zoom;
	else
		l = fractal->width * fractal->zoom;
	x += fractal->xarrow ;
	y += fractal->yarrow ;
	c.x = 2 * fractal->radius * (x - fractal->width / 2) / l;
	//imaginary
	c.y = 2 * fractal->radius * (y - fractal->height / 2) / l;
	return (c);
}