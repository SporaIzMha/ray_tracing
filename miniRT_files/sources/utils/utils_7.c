#include "minirt.h"

void	per_l_ne_ch(char *line, char *line_1, char *line_2)
{
	if (ft_atof(line) < -1 || ft_atof(line) > 1)
	{
		programm_stop_2("Oh, no, you have error :(normale)");
	}
	if (ft_atof(line_1) < -1 || ft_atof(line_1) > 1)
	{
		programm_stop_2("Oh, no, you have error :(normale)");
	}
	if (ft_atof(line_2) < -1 || ft_atof(line_2) > 1)
	{
		programm_stop_2("Oh, no, you have error :(normale)");
	}
}

float	color_3(t_shut shut, t_ortv *l_ortv, float tons_objct)
{
	float	len;
	float	params;

	params = ortv_depv(shut.per_l_n, *l_ortv);
	len = 0;
	if (0 < params)
	{
		len = fabs(params) * tons_objct / (ortv_len(*l_ortv));
	}
	return (len);
}

t_ortv	multip_array_map(t_ortv *ortv, t_array_map *array_map)
{
	t_ortv	param;

	param.z = ortv->x * array_map->freed_r.z + ortv->y * array_map->up.z
		+ ortv->z * array_map->ahead.z + array_map->start_o.z;
	param.x = ortv->x * array_map->freed_r.x + ortv->y * array_map->up.x
		+ ortv->z * array_map->ahead.x + array_map->start_o.x;
	param.y = ortv->x * array_map->freed_r.y + ortv->y * array_map->up.y
		+ ortv->z * array_map->ahead.y + array_map->start_o.y;
	return (param);
}

float	color_2(t_shut shut, t_ortv *ortv_d,
	t_locale *locale, t_tons *color)
{
	float	pred_f[2];
	float	len;
	t_shut	sh2;

	pred_f[0] = 0.0001;
	pred_f[1] = 1;
	len = 0;
	sh2 = color_1(&shut.start_d, color->l_ortv, locale, pred_f);
	if (1 != sh2.t)
	{
		return (len);
	}
	len = len + color_3(shut, color->l_ortv, color->intensity_l);
	len = len + color_4(shut, color->l_ortv, ortv_d, color->intensity_l);
	return (len);
}

void	sanitazer_mass(char **params)
{
	size_t	len;

	len = 0;
	while (params[len])
	{
		free(params[len]);
		len++;
	}
	free(params);
}
