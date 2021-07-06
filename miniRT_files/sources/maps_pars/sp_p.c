#include "minirt.h"

void	r_sp(char *str, t_locale *locale)
{
	t_sp			*sp_n;
	t_figura		*vartemp;
	t_p_prs			p;
	t_figura		*sp;

	vartemp = locale->figura;
	sp_n = malloc(sizeof(t_sp));
	sp = malloc(sizeof(t_figura));
	if (!sp_n || !sp)
		programm_stop_2("Oh, no, you have error :(malloc)");
	r_sp_1(&p, str);
	sp_n->core = coord_g(p.masif1);
	sp_n->diometr = ft_atof(p.masif[1]);
	if (sp_n->diometr < 0)
		programm_stop_2("Oh, no, you have error :(sp)\n");
	p.masif2 = ft_split(p.masif[2], ',');
	r_sp_2(sp, sp_n, p);
	r_sp_3(vartemp, sp, locale);
	sanitazer_mass(p.masif);
	sanitazer_mass(p.masif1);
	sanitazer_mass(p.masif2);
}

void	r_c_2(t_look	*vartemp, t_look *cam, t_locale *locale)
{
	vartemp = locale->camers;
	if (!vartemp)
	{
		locale->camers = cam;
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
		cam->agpost = vartemp;
		vartemp->again = cam;
	}
}

void	r_sp_1(t_p_prs *p, char *str)
{
	p->masif = ft_split(str + 1, ' ');
	if (!(p->masif[0] && p->masif[1] && p->masif[2]) || (p->masif[3])
		|| (str[0] != ' '))
	{
		programm_stop_2("Oh, no, you have error :(sp)\n");
	}
	if (!(p->masif[0] && p->masif[1] && p->masif[2]) || p->masif[3])
	{
		programm_stop_2("Oh, no, you have error :(sp)\n");
	}
	p->masif1 = ft_split(p->masif[0], ',');
	if (!(p->masif1[0] && p->masif1[1] && p->masif1[2]) || p->masif1[3])
	{
		programm_stop_2("Oh, no, you have error :(sp)\n");
	}
}

void	r_sp_2(t_figura *sp, t_sp *sp_n, t_p_prs p)
{
	char	v;

	v = 's';
	sp_n->tone = _tone_g(p.masif2);
	sp->showing = (void *)sp_n;
	sp->vid = v;
	sp->funksion_intr = &sp_cross;
	sp->again = NULL;
}

void	r_sp_3(t_figura *vartemp, t_figura *sp, t_locale *locale)
{
	if (!vartemp)
	{
		locale->figura = sp;
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
		vartemp->again = sp;
	}
}
