#include "minirt.h"

void	wrk_looking(t_ortv *param, t_look *looking)
{
	t_array_map	array_map;
	t_ortv		ray;

	array_map = look_at(looking);
	ray = multip_array_map(param, &array_map);
	ray = ortv_sub(ray, looking->start_o);
	ray = ortv_perp_n(ray);
	*param = ray;
}

void	r_tr(char *str, t_locale *locale)
{
	t_tr			*tr_n;
	t_figura		*vartemp;
	t_p_prs			p;
	t_figura		*tr;

	vartemp = locale->figura;
	tr_n = malloc(sizeof(t_tr));
	tr = malloc(sizeof(t_figura));
	if (!tr_n || !tr)
		programm_stop_2("Oh, no, you have error :(malloc)");
	p.masif = ft_split(str + 1, ' ');
	if (str[0] != ' ')
		programm_stop_2("Oh, no, you have error :(tr)\n");
	r_tr_1(&p, tr_n);
	r_tr_2(tr, tr_n, p);
	r_tr_3(vartemp, tr, locale);
	sanitazer_mass(p.masif);
	sanitazer_mass(p.masif1);
	sanitazer_mass(p.masif2);
	sanitazer_mass(p.masif3);
	sanitazer_mass(p.masif4);
}

void	save_4(unsigned char *massif_screen, int proportions,
			t_showing *chk, int param)
{
	int	znach;

	znach = 256;
	massif_screen[0] = (unsigned char) 'B';
	massif_screen[1] = (unsigned char) 'M';
	massif_screen[2] = (unsigned char)(proportions % znach);
	massif_screen[3] = (unsigned char)(proportions / znach % znach);
	massif_screen[4] = (unsigned char)(proportions / znach / znach % znach);
	massif_screen[5] = (unsigned char)(proportions / znach / znach / znach);
	massif_screen[10] = (unsigned char)54;
	massif_screen[14] = (unsigned char)40;
	massif_screen[18] = (unsigned char)(param % znach);
	massif_screen[19] = (unsigned char)(param / znach % znach);
	massif_screen[20] = (unsigned char)(param / znach / znach % znach);
	massif_screen[21] = (unsigned char)(param / znach / znach / znach);
	param = chk->wall_y;
	massif_screen[22] = (unsigned char)(param % znach);
	massif_screen[23] = (unsigned char)(param / znach % znach);
	massif_screen[24] = (unsigned char)(param / znach / znach % znach);
	massif_screen[25] = (unsigned char)(param / znach / znach / znach);
	massif_screen[26] = (unsigned char)1;
	massif_screen[28] = (unsigned char)24;
}

void	r_tr_2(t_figura *tr, t_tr *tr_n, t_p_prs p)
{
	char	v;

	v = 't';
	tr_n->tone = _tone_g(p.masif4);
	tr->showing = tr_n;
	tr->vid = v;
	tr->funksion_intr = &tr_cross;
	tr->again = NULL;
}

void	r_tr_3(t_figura	*vartemp, t_figura *tr, t_locale *locale)
{
	if (!vartemp)
	{
		locale->figura = tr;
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
		vartemp->again = tr;
	}
}
