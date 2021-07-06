#include "minirt.h"

t_ortv	func_rt_g(t_locale *locale, int axis_x, int axis_y)
{
	float	luch_rad;
	t_ortv	route;
	float	otnochenie;

	otnochenie = (float)locale->geo_wd / (float)locale->geo_h;
	luch_rad = M_PI * (float)locale->camers->range_f / 360;
	route.x = ((1 / 2) + axis_x) * tan(luch_rad) * 2 / (float)locale->geo_wd;
	route.y = ((1 / 2) + axis_y) * tan(luch_rad) * 2
		/ (otnochenie * (float)locale->geo_h);
	route.z = 1;
	return (route);
}

t_shut	color_1(t_ortv *start_o, t_ortv *ray, t_locale *locale, float *pred_f)
{
	t_shut		shutst;
	t_figura	*vartemp;
	t_shut		shut;

	shutst.t = pred_f[1];
	vartemp = locale->figura;
	while (vartemp)
	{
		shut = vartemp->funksion_intr(start_o, ray, vartemp->showing, pred_f);
		if (shutst.t > shut.t)
		{
			shutst = shut;
		}
		vartemp = vartemp->again;
	}
	return (shutst);
}

void	func_rt_tone_camers(t_shut *shut, t_ortv *ortv_d, t_locale *locale)
{
	t_ortv		l_ortv;
	float		i;
	t_tons		*vartemp;
	t_tone		tone;
	t_tone		tons_tone;

	i = 0;
	tone = tone_5(locale->intensity_l, &locale->tone);
	tone = tone_4(&shut->tone_object, &tone);
	vartemp = locale->tons;
	while (vartemp)
	{
		l_ortv = ortv_sub(vartemp->d_l, shut->start_d);
		i = 0;
		vartemp->l_ortv = &l_ortv;
		i = color_2(*shut, ortv_d, locale, vartemp);
		if (i)
		{
			tons_tone = tone_5(i, &vartemp->tone);
			tons_tone = tone_4(&shut->tone_object, &tons_tone);
			tone = tone_3(&tone, &tons_tone);
		}
		vartemp = vartemp->again;
	}
	shut->tone_object = tone;
}

void	func_rt_coord(void *libr, t_locale *locale, t_showing *picture)
{
	t_ortv	route;
	int		tone;
	int		axis_x;
	int		axis_y;

	picture->okno = mlx_new_image(libr, locale->geo_wd, locale->geo_h);
	picture->supscrip = mlx_get_data_addr(picture->okno,
			&picture->p_screen, &picture->side_r, &picture->endian);
	axis_x = ((-1) * (locale->geo_wd / 2));
	picture->wall_y = locale->geo_h;
	picture->wall_x = locale->geo_wd;
	while (axis_x < (locale->geo_wd / 2))
	{
		axis_y = (locale->geo_h / 2);
		while ((locale->geo_h / (-2)) < axis_y)
		{
			route = func_rt_g(locale, axis_x, axis_y);
			wrk_looking(&route, locale->camers);
			tone = tone_1(&route, locale);
			func_rt_coord_pixels(picture, (int)(locale->geo_wd / 2 + axis_x),
				(int)(locale->geo_h / 2 - axis_y), tone);
			axis_y--;
		}
		axis_x++;
	}
}

void	func_rt_coord_pixels(t_showing *showing, int axis_x,
		int axis_y, int tone)
{
	char	*params;

	params = (axis_y * showing->side_r + (showing->p_screen
				/ 8) * axis_x) + showing->supscrip;
	*(unsigned int *)params = tone;
}
