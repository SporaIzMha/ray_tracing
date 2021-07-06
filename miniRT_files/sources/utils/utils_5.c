#include "minirt.h"

t_ortv	coord_g(char **line)
{
	t_ortv		vartemp;

	vartemp.x = ft_atof(line[0]);
	vartemp.y = ft_atof(line[1]);
	vartemp.z = ft_atof(line[2]);
	return (vartemp);
}

t_tone	_tone_g(char **line)
{
	int			i;
	t_tone		vartemp;

	i = 255;
	if (!(line[1] && line[0] && line[2]) || line[3])
	{
		programm_stop_2("Oh, no, you have error :(have not tone)\n");
	}
	vartemp.g = ft_atoi(line[1]);
	vartemp.r = ft_atoi(line[0]);
	vartemp.b = ft_atoi(line[2]);
	if ((vartemp.g < 0 || vartemp.g > i) || (vartemp.r < 0
			|| vartemp.r > i) || (vartemp.b < 0 || vartemp.b > i))
	{
		programm_stop_2("Oh, no, you have error :(tone)n");
	}
	return (vartemp);
}

void	sanitazer_locale_3(t_look *look)
{
	t_look	*vartemp;

	while (look)
	{
		vartemp = look;
		look = look->again;
		free(vartemp);
	}
}

void	wrk_cam(t_arguments *parametr)
{
	mlx_destroy_image(parametr->libr, parametr->okno->okno);
	func_rt_coord(parametr->libr, parametr->locale, parametr->okno);
	mlx_put_image_to_window(parametr->libr, parametr->win,
		parametr->okno->okno, 0, 0);
}

float	color_4(t_shut shut, t_ortv *l_ortv, t_ortv *ortv_d,
	float tons_objct)
{
	float	params;
	int		i;
	t_ortv	ortv_v;
	t_ortv	vartemp;
	t_ortv	ortv_r;

	i = 2;
	ortv_v = *ortv_d;
	ortv_v = ortv_ml_vn(ortv_v, -1);
	params = ortv_depv(shut.per_l_n, *l_ortv) * i;
	vartemp = shut.per_l_n;
	vartemp = ortv_ml_vn(vartemp, params);
	ortv_r = ortv_sub(vartemp, *l_ortv);
	params = ortv_depv(ortv_r, ortv_v);
	if (0 < params)
	{
		params = tons_objct * pow(params
				/ (ortv_len(ortv_r) * ortv_len(ortv_v)), 300);
		return (params);
	}
	return (0);
}
