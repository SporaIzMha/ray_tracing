#include "minirt.h"

void	r_cy(char *str, t_locale *locale)
{
	t_cy		*cy_n;
	t_figura	*vartemp;
	t_p_prs		p;
	t_figura	*cy;

	vartemp = locale->figura;
	cy_n = malloc(sizeof(t_cy));
	cy = malloc(sizeof(t_figura));
	if (!cy_n || !cy)
		programm_stop_2("Oh, no, you have error :(malloc)");
	p.masif = ft_split(str + 1, ' ');
	if (str[0] != ' ')
		programm_stop_2("Oh, no, you have error :(cy)\n");
	r_cy_4(&p, cy_n);
	per_l_ne_ch(p.masif2[0], p.masif2[1], p.masif2[2]);
	r_cy_3(cy_n, p);
	p.masif3 = ft_split(p.masif[4], ',');
	r_cy_2(cy, cy_n, p.masif3);
	r_cy_1(vartemp, cy, locale);
	sanitazer_mass(p.masif);
	sanitazer_mass(p.masif1);
	sanitazer_mass(p.masif2);
	sanitazer_mass(p.masif3);
}

void	r_cy_2(t_figura *cy, t_cy *cy_n, char **tone_cy)
{
	cy_n->tone = _tone_g(tone_cy);
	cy->showing = cy_n;
	cy->vid = 'c';
	cy->funksion_intr = &cy_cross;
	cy->again = NULL;
}

void	r_cy_4(t_p_prs *p, t_cy *cy_n)
{
	if (!(p->masif[0] && p->masif[1] && p->masif[2] && p->masif[3]
			&& p->masif[4]) || (p->masif[5]))
	{
		programm_stop_2("Oh, no, you have error :(cy)\n");
	}
	p->masif1 = ft_split(p->masif[0], ',');
	if (!(p->masif1[0] && p->masif1[1] && p->masif1[2]) || p->masif1[3])
	{
		programm_stop_2("Oh, no, you have error :(cy)\n");
	}
	cy_n->core = coord_g(p->masif1);
	p->masif2 = ft_split(p->masif[1], ',');
	if (!(p->masif2[0] && p->masif2[1] && p->masif2[2]) || p->masif2[3])
	{
		programm_stop_2("Oh, no, you have error :(cy)\n");
	}
}

void	r_cy_1(t_figura *vartemp, t_figura *cy, t_locale *locale)
{
	if (!vartemp)
	{
		locale->figura = cy;
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
		vartemp->again = cy;
	}
}

void	r_cy_3(t_cy *cy_n, t_p_prs p)
{
	cy_n->route = coord_g(p.masif2);
	cy_n->diometr = ft_atof(p.masif[2]);
	cy_n->geo_h = ft_atof(p.masif[3]);
}
