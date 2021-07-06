#include "minirt.h"

void	r_l(char *str, t_locale *locale)
{
	t_tons		*vartemp;
	t_tons		*ligh_n;

	vartemp = NULL;
	ligh_n = (t_tons *)malloc(sizeof(t_tons));
	if (!ligh_n)
	{
		programm_stop_2("Oh, no, you have error :(malloc)");
	}
	ligh_n->again = NULL;
	r_l_0(vartemp, ligh_n, locale);
	r_l_1(str, ligh_n);
}

void	loc_dell(char **mas, char **m_1, char **m_2)
{
	sanitazer_mass(mas);
	sanitazer_mass(m_1);
	sanitazer_mass(m_2);
}

void	r_l_1(char *str, t_tons *ligh_n)
{
	char	**masifay;
	char	**p_cord1;

	masifay = ft_split(str + 1, ' ');
	if (str[0] != ' ')
	{
		programm_stop_2("Oh, no, you have error :(l)\n");
	}
	if (!(masifay[0] && masifay[1] && masifay[2]) || masifay[3])
		programm_stop_2("Oh, no, you have error :(l)\n");
	p_cord1 = ft_split(masifay[0], ',');
	if (!(p_cord1[0] && p_cord1[1] && p_cord1[2]) || p_cord1[3])
	{
		programm_stop_2("Oh, no, you have error :(l)\n");
	}
	ligh_n->d_l.x = ft_atof(p_cord1[0]);
	ligh_n->d_l.y = ft_atof(p_cord1[1]);
	ligh_n->d_l.z = ft_atof(p_cord1[2]);
	ligh_n->intensity_l = ft_atof(masifay[1]);
	if (ligh_n->intensity_l <= 0 || ligh_n->intensity_l > 1)
		programm_stop_2("Oh, no, you have error :(l)\n");
	r_l_tone(ligh_n, masifay);
	sanitazer_mass(masifay);
	sanitazer_mass(p_cord1);
}

void	r_l_tone(t_tons *ligh_n, char **masifay)
{
	char	**p_cord;

	p_cord = ft_split(masifay[2], ',');
	if (!(p_cord[0] && p_cord[1] && p_cord[2]) || p_cord[3])
	{
		programm_stop_2("Oh, no, you have error :(l)!\n");
	}
	ligh_n->tone.r = ft_atoi(p_cord[0]);
	ligh_n->tone.g = ft_atoi(p_cord[1]);
	ligh_n->tone.b = ft_atoi(p_cord[2]);
	if ((ligh_n->tone.r < 0 || ligh_n->tone.r > 255)
		|| (ligh_n->tone.g < 0 || ligh_n->tone.g > 255)
		|| (ligh_n->tone.b < 0 || ligh_n->tone.b > 255))
	{
		programm_stop_2("Oh, no, you have error :(l)\n");
	}
	sanitazer_mass(p_cord);
}

void	r_l_0(t_tons *vartemp, t_tons *ligh_n, t_locale *locale)
{
	vartemp = locale->tons;
	if (!vartemp)
		locale->tons = ligh_n;
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
		vartemp->again = ligh_n;
	}
}
