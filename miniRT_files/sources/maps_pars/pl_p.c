#include "minirt.h"

void	r_pl(char *str, t_locale *locale)
{
	t_p_prs			p;
	t_figura		*vartemp;
	t_figura		*pl;
	t_pl			*pl_n;

	vartemp = locale->figura;
	pl_n = malloc(sizeof(t_pl));
	pl = malloc(sizeof(t_figura));
	if (!pl_n || !pl)
		programm_stop_2("Oh, no, you have error :(malloc)\n");
	r_pl_2(&p, pl_n, str);
	per_l_ne_ch(p.masif2[0], p.masif2[1], p.masif2[2]);
	r_pl_3(pl, pl_n, p);
	r_pl_1(vartemp, pl, locale);
	sanitazer_mass(p.masif);
	sanitazer_mass(p.masif1);
	sanitazer_mass(p.masif2);
}

void	r_pl_1(t_figura *vartemp, t_figura *pl, t_locale *locale)
{
	if ((!vartemp))
	{
		locale->figura = pl;
	}
	else
	{
		while (vartemp)
		{
			if (vartemp->again == NULL)
			{
				break ;
			}
			vartemp = vartemp->again;
		}
		vartemp->again = pl;
	}
}

void	r_pl_2(t_p_prs *p, t_pl *pl_n, char *str)
{
	p->masif = ft_split(str + 1, ' ');
	if (str[0] != ' ')
	{
		programm_stop_2("Oh, no, you have error :(pl)\n");
	}
	p->masif1 = ft_split(p->masif[0], ',');
	if (!(p->masif1[0] && p->masif1[1] && p->masif1[2]) || p->masif1[3])
	{
		programm_stop_2("Oh, no, you have error :(pl)\n");
	}
	pl_n->core = coord_g(p->masif1);
	p->masif2 = ft_split(p->masif[1], ',');
	if (!(p->masif2[0] && p->masif2[1] && p->masif2[2]) || p->masif2[3])
	{
		programm_stop_2("Oh, no, you have error :(pl)\n");
	}
}

void	r_c_1(char *str, t_look	*cam)
{
	char	**mass;
	char	**ch_1;
	char	**ch2;

	mass = ft_split(str + 1, ' ');
	if (str[0] != ' ' || !(mass[0] && mass[1] && mass[2])
		|| mass[3])
		programm_stop_2("Oh, no, you have error :(c)\n");
	ch_1 = ft_split(mass[0], ',');
	if (!(ch_1[0] && ch_1[1] && ch_1[2]) || ch_1[3])
		programm_stop_2("Oh, no, you have error :(c)\n");
	cam->start_o.x = ft_atof(ch_1[0]);
	cam->start_o.y = ft_atof(ch_1[1]);
	cam->start_o.z = ft_atof(ch_1[2]);
	ch2 = ft_split(mass[1], ',');
	if (!(ch2[0] && ch2[1] && ch2[2]) || ch2[3])
		programm_stop_2("Oh, no, you have error :(c)\n");
	cam->route.x = ft_atof(ch2[0]);
	cam->route.y = ft_atof(ch2[1]);
	cam->route.z = ft_atof(ch2[2]);
	cam->range_f = ft_atof(mass[2]);
	if (cam->range_f > 360 || cam->range_f < 0)
		programm_stop_2("Oh, no, you have error :(c)\n");
	loc_dell(mass, ch_1, ch2);
}

void	r_pl_3(t_figura *pl, t_pl *pl_n, t_p_prs p)
{
	char	v;

	v = 'p';
	pl_n->per_l_n = coord_g(p.masif2);
	p.masif3 = ft_split(p.masif[2], ',');
	pl_n->tone = _tone_g(p.masif3);
	pl->showing = pl_n;
	pl->vid = v;
	pl->funksion_intr = &pl_cross;
	pl->again = NULL;
	sanitazer_mass(p.masif3);
}
