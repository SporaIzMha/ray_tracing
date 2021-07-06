#include "minirt.h"

void	my_mlx_i_t_w(t_arguments *arguments,
		t_showing *picture, t_locale *locale)
{
	arguments->locale = locale;
	mlx_hook(arguments->win, 17, 0L, shut_program_w, arguments);
	mlx_hook(arguments->win, 2, 1L << 0, shut_program_w2, arguments);
	mlx_put_image_to_window(arguments->libr,
		arguments->win, picture->okno, 0, 0);
	mlx_loop(arguments->libr);
}

void	sanitazer_programm(t_arguments *arg)
{
	sanitazer_locale(arg->locale);
	if (arg->okno && arg->libr)
	{
		mlx_destroy_image(arg->libr, arg->okno->okno);
	}
	if (arg->win && arg->libr)
	{
		mlx_destroy_window(arg->libr, arg->win);
	}
	if (arg->libr)
	{
		free(arg->libr);
	}
}

void	check_screen_size(t_locale *locale, t_arguments *arguments)
{
	int	gw;
	int	gh;

	mlx_get_screen_size(arguments->libr, &gw, &gh);
	if (gw < locale->geo_wd)
	{
		locale->geo_wd = gw;
	}
	if (gh < locale->geo_h)
	{
		locale->geo_h = gh;
	}
	if (1 != locale->tons_a)
	{
		sanitazer_programm(arguments);
		programm_stop_2("Oh, no, you have error :(ambient)\n");
	}
	if (1 != locale->cam_flag)
	{
		sanitazer_programm(arguments);
		programm_stop_2("Oh, no, you have error :(LOOK)\n");
	}
}

void	z_start(t_shut *shut)
{
	shut->tone_object.g = 0;
	shut->tone_object.r = 0;
	shut->tone_object.b = 0;
	shut->t = INFINITY;
}

void	check_valid_imput(int i)
{
	if (i != 2 && i != 3)
	{
		programm_stop(2);
	}
}
