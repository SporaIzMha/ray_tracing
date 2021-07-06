#include "minirt.h"

void	r_sq(char *str, t_locale *locale)
{
	t_sq			*sq_n;
	t_figura		*vartemp;
	t_p_prs			p;
	t_figura		*sq;

	vartemp = locale->figura;
	sq_n = malloc(sizeof(t_sq));
	sq = malloc(sizeof(t_figura));
	if (!sq_n || !sq)
		programm_stop_2("Oh, no, you have error :(malloc)");
	p.masif = ft_split(str + 1, ' ');
	if (str[0] != ' ')
		programm_stop_2("Oh, no, you have error :(sq)\n");
	r_sq_1(&p, sq_n);
	per_l_ne_ch(p.masif2[0], p.masif2[1], p.masif2[2]);
	r_sq_2(sq, sq_n, p);
	r_sq_3(vartemp, sq, locale);
	sanitazer_mass(p.masif2);
	sanitazer_mass(p.masif);
	sanitazer_mass(p.masif1);
}

void	r_sq_3(t_figura	*vartemp, t_figura *sq, t_locale *locale)
{
	if (!vartemp)
	{
		locale->figura = sq;
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
		vartemp->again = sq;
	}
}

void	r_sq_2(t_figura *sq, t_sq *sq_n, t_p_prs p)
{
	char	v;

	v = 'q';
	sq_n->per_l_n = coord_g(p.masif2);
	sq_n->size_stor_a = ft_atoi(p.masif[2]);
	sq_n->len = sq_n->size_stor_a / sqrt(2);
	p.masif3 = ft_split(p.masif[3], ',');
	sq_n->tone = _tone_g(p.masif3);
	sq->showing = sq_n;
	sq->vid = v;
	sq->funksion_intr = &sq_intersect;
	sq->again = NULL;
	sanitazer_mass(p.masif3);
}

void	r_sq_1(t_p_prs *lg, t_sq *sq_n)
{
	if (!(lg->masif[0] && lg->masif[1] && lg->masif[2] && lg->masif[3])
		|| lg->masif[4])
	{
		programm_stop_2("Oh, no, you have error :(sq)\n");
	}
	lg->masif1 = ft_split(lg->masif[0], ',');
	if (!(lg->masif1[0] && lg->masif1[1] && lg->masif1[2]) || lg->masif1[3])
	{
		programm_stop_2("Oh, no, you have error :(sq)\n");
	}
	sq_n->core = coord_g(lg->masif1);
	lg->masif2 = ft_split(lg->masif[1], ',');
	if (!(lg->masif2[0] && lg->masif2[1] && lg->masif2[2]) || lg->masif2[3])
	{
		programm_stop_2("Oh, no, you have error :(sq)\n");
	}
}

void	r_tr_1(t_p_prs *lg, t_tr *tr_n)
{
	if (!(lg->masif[0] && lg->masif[1] && lg->masif[2]
			&& lg->masif[3]) || lg->masif[4])
	{
		programm_stop_2("Oh, no, you have error :(tr)\n");
	}
	lg->masif1 = ft_split(lg->masif[0], ',');
	if (!(lg->masif1[0] && lg->masif1[1] && lg->masif1[2]) || lg->masif1[3])
	{
		programm_stop_2("Oh, no, you have error :(tr)\n");
	}
	tr_n->c1 = coord_g(lg->masif1);
	lg->masif2 = ft_split(lg->masif[1], ',');
	if (!(lg->masif2[0] && lg->masif2[1] && lg->masif2[2]) || lg->masif2[3])
	{
		programm_stop_2("Oh, no, you have error :(tr)\n");
	}
	tr_n->c2 = coord_g(lg->masif2);
	lg->masif3 = ft_split(lg->masif[2], ',');
	if (!(lg->masif3[0] && lg->masif3[1] && lg->masif3[2]) || lg->masif3[3])
		programm_stop_2("Oh, no, you have error :(tr)\n");
	tr_n->c3 = coord_g(lg->masif3);
	lg->masif4 = ft_split(lg->masif[3], ',');
	if (!(lg->masif4[0] && lg->masif4[1] && lg->masif4[2]) || lg->masif4[3])
		programm_stop_2("Oh, no, you have error :(tr)\n");
}
