#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>

typedef struct	s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_img	img;
	int		cur_img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_mand
{
	double	pr;
	double	pi;
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	double	zoom;
	double	x;
	double	y;
	double	moveX;
	double	moveY;
	int		maxIt;
}	t_mand;


enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	init_mand(t_mand *mand)
{
	mand->pr = 0;
	mand->pi = 0;
	mand->newRe = 0;
	mand->newIm = 0;
	mand->oldRe = 0;
	mand->oldIm = 0;
	mand->zoom = 1;
	mand->x = 0;
	mand->y = 0;
	mand->moveX = 0.5;
	mand->moveY = 0;
	mand->maxIt = 300;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		exit(0);
	}
	else
		printf("Key %d was pressed!\n", keycode);
	return (0);
}

// int	exit_hook(int keycode, t_data *data)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(data->mlx, data->win);
// 		data->win = NULL;
// 		exit(0);

// 	}
// 	else
// 		printf("Key %d was pressed!\n", keycode);
// 	return (0);
// }

int	encode_rgb(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		i;

	i = img ->bpp - 8;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	// *(unsigned int*)dst = color;
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*dst++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*dst++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render_mandelbrot(t_img *img, t_mand mand)
{
	int	i;
	int	j;

	i = mand.y;
	while (i < 1080)
	{
		j = mand.x;
		while (j < 1920)
		{
			mand.pr = 1.5 * (mand.x - 1920 / 2) / (0.5 * mand.zoom * 1920) + mand.moveX;
			mand.pi = (mand.y - 1080 / 2) / (0.5 * mand.zoom * 1080) + mand.moveY;
			mand.newRe = mand.newIm = mand.oldRe = mand.oldIm = 0;
			my_mlx_pixel_put(img, j++, i, 0xFF00);
		}
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 1080)
	{
		j = 0;
		while (j < 1920)
			my_mlx_pixel_put(img, j++, i, color);
		++i;
	}
}

int	render(t_data *data)
{
	if (data->win == NULL)
		return (1);
	render_background(&data->img, 0xFFFFFF);
	// render_rect(&data->img, (t_rect){0, 0, 100, 100, 0xFF00});
	// render_rect(&data->img, (t_rect){1720, 880, 200, 200, 0xFF0000});
	// render_rect(&data->img, (t_rect){500, 500, 200, 200, 203569230});
	
	render_rect(&data->img, (t_rect){500, 500, 200, 200, 203569230});
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, 1920, 1080, "Test01");
	if (!data.win)
	{
		free(data.win);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx, 1920, 1080);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_length, &data.img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, 2, 3, key_hook, &data);
	// mlx_hook(data.win, 2, 17, exit_hook, &data);
	// mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_img, 0, 0);
	// my_mlx_pixel_put(&img, 10, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 9, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 8, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 7, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 6, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 5, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 4, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 3, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 2, 5, 0xFF00);
	// my_mlx_pixel_put(&img, 1, 5, 0xFF00);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.win);
	// mlx_destroy_display(mlx);
	printf("01\n");
	free(data.mlx);
	return (0);
}