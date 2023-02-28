#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
#include <mlx.h>
# include <math.h>
# include <stdio.h>

//defines
    //window setings
# define MLX_ERROR	1
# define WINDOW_WIDTH	600
# define WINDOW_HEIGHT	300
    //button settings
# define K_EXIT 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define R 114
# define Z 122
# define PLUS 65451
# define MINUS 65453

//structs
    //imaginary numbers struct

    typedef struct imaginary
    {
	    double	x;
	    double	y;
    }			t_complex;

    //struct for passing the info of the fractals

typedef struct s_fractal {
	char		*name;
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_complex	c;
	double		zoom;
	double		x;
	double		y;
	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;
}				t_fractal;

//functions
void	miniburning(int x, int y, t_fractal *burning);

void	ft_zoom(double x, double y, t_fractal *fractal);
void	ft_dezoom(double x, double y, t_fractal *fractal);
int     key_hook(int keycode, t_fractal *fractal);
int     mouse_hook(int key_code, int x, int y, t_fractal *fractal);
int	close_game(t_fractal *fractal);

#endif