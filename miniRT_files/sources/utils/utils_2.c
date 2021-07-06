#include "minirt.h"

int	shut_program_w2(int	code_klava, t_arguments *parametr)
{
	if (code_klava == 53)
	{
		shut_program_w(parametr);
	}
	else if (code_klava == 123)
	{
		if (!(parametr->locale->camers->agpost))
		{
			return (0);
		}
		parametr->locale->camers = parametr->locale->camers->agpost;
		wrk_cam(parametr);
	}
	else if (code_klava == 124)
	{
		if (!(parametr->locale->camers->again))
		{
			return (0);
		}
		parametr->locale->camers = parametr->locale->camers->again;
		wrk_cam(parametr);
	}
	return (0);
}

void	sanitazer_locale_2(t_tons *tones)
{
	t_tons	*vartemp;

	while (tones)
	{
		vartemp = tones;
		tones = tones->again;
		free(vartemp);
	}
}

void	programm_stop_2(char *line)
{
	printf("%s\n", line);
	exit(1);
}

void	sanitazer_locale_1(t_figura *figura)
{
	t_figura	*vartemp;

	while (figura)
	{
		vartemp = figura;
		figura = figura->again;
		free(vartemp->showing);
		free(vartemp);
	}
}

void	sanitazer_locale(t_locale *locale)
{
	sanitazer_locale_1(locale->figura);
	sanitazer_locale_3(locale->camers);
	sanitazer_locale_2(locale->tons);
}
