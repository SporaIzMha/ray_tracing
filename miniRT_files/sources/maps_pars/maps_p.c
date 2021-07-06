#include "minirt.h"

void	pars_showing(char *file, t_locale *locale)
{
	int		i;
	char	*str;

	i = open(file, O_RDONLY);
	if (-1 == i)
	{
		programm_stop(1);
	}
	while (1 == get_next_line(i, &str))
	{
		pars_str(str, locale);
	}
	free(str);
}

void	r_c(char *str, t_locale *locale)
{
	t_look	*cam;
	t_look	*vartemp;

	vartemp = NULL;
	locale->cam_flag = 1;
	cam = malloc(sizeof(t_look));
	if (!cam)
	{
		programm_stop_2("Oh, no, you have error :(malloc)\n");
	}
	cam->again = NULL;
	cam->agpost = NULL;
	r_c_1(str, cam);
	r_c_2(vartemp, cam, locale);
}

void	r_p(char *str, t_locale *locale)
{
	char	**mass;

	mass = ft_split(str + 1, ' ');
	if (str[0] != ' ' || !(mass[0]) || !(mass[1]))
	{
		programm_stop_2("Oh, no, you have error :(r)\n");
	}
	if (mass[2])
	{
		programm_stop_2("Oh, no, you have error :(r)\n");
	}
	locale->geo_wd = ft_atoi(mass[0]);
	locale->geo_h = ft_atoi(mass[1]);
	if (locale->geo_wd <= 0 || locale->geo_h <= 0)
	{
		programm_stop_2("Oh, no, you have error :(r)\n");
	}
	sanitazer_mass(mass);
}

void	pars_str(char *str, t_locale *locale)
{
	if (str[0] == 'R')
		r_p(str + 1, locale);
	else if (str[0] == 's' && str[1] == 'p')
	{
		r_sp(str + 2, locale);
	}
	else if (str[0] == 'l')
		r_l(str + 1, locale);
	else if (str[0] == 'A')
		r_a(str + 1, locale);
	else if (str[0] == 'p' && str[1] == 'l')
		r_pl(str + 2, locale);
	else if (str[0] == 's' && str[1] == 'q')
	{
		r_sq(str + 2, locale);
	}
	else if (str[1] == 'r' && str[0] == 't')
		r_tr(str + 2, locale);
	else if (str[0] == 'c' && str[1] == 'y')
		r_cy(str + 2, locale);
	else if (str[1] != 'y' && str[0] == 'c')
		r_c(str + 1, locale);
	else if (!str[0])
		programm_stop_2("Oh, no, you have error :(cy)\n");
	free(str);
}

void	r_a(char *str, t_locale *locale)
{
	int		i;
	char	**mass;
	char	**vartemp;

	locale->tons_a = 1;
	i = 255;
	mass = ft_split(str + 1, ' ');
	if (str[0] != ' ' || !(mass[0]) || !(mass[1]))
		programm_stop_2("Oh, no, you have error :(a)\n");
	locale->intensity_l = ft_atof(mass[0]);
	if (locale->intensity_l <= 0 || locale->intensity_l > 1)
		programm_stop_2("Oh, no, you have error :(a)\n");
	vartemp = mass;
	mass = ft_split(mass[1], ',');
	if (!(mass[0] && mass[1] && mass[2]) || mass[3])
		programm_stop_2("Oh, no, you have error :(a)\n");
	locale->tone.r = ft_atoi(mass[0]);
	locale->tone.g = ft_atoi(mass[1]);
	locale->tone.b = ft_atoi(mass[2]);
	if ((locale->tone.g < 0 || locale->tone.g > i) || (locale->tone.r < 0
			|| locale->tone.r > i) || (locale->tone.b < 0 || locale->tone.b
			> i))
		programm_stop_2("Oh, no, you have error :(a)\n");
	sanitazer_mass(mass);
	sanitazer_mass(vartemp);
}
