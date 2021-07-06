#include "minirt.h"

char	programm_stop(int code)
{
	if (code == 2)
		write(1, "Oh, no, you have error :(invalid imput)\n", 21);
	if (code == 1)
		write(1, "Oh, no, you have error :(file value)\n", 26);
	exit(-1);
	return (1);
}

int	gnl_ysl(char **j, int i, char **str, char **str_1)
{
	char	*vartemp;
	int		rd;

	rd = 0;
	rd = read(i, *j, BUFFER_SIZE);
	while (rd)
	{
		if (rd < 0)
		{
			return (-1);
		}
		vartemp = *str;
		(*j)[rd] = '\0';
		*str = gnl_join(*str, *j);
		sanitazer_gnl(vartemp, 0);
		if (1 == (perenos_ch(str, str_1)))
		{
			return (sanitazer_gnl(*j, 1));
		}
		else if (-1 == (perenos_ch(str, str_1)))
			return (sanitazer_gnl(*j, -1));
	}
	return (0);
}

float	ortv_depv(t_ortv ortv_1, t_ortv ortv_2)
{
	float	guide_ret;

	guide_ret = ((ortv_1.x * ortv_2.x) + (ortv_1.y * ortv_2.y)
			+ (ortv_1.z * ortv_2.z));
	return (guide_ret);
}

char	programm_check(int len_line, char *params[])
{
	int	vartemp;

	(void)len_line;
	vartemp = ft_strlen(params[1]);
	if (vartemp < 4)
	{
		return (programm_stop(1));
	}
	if ((ft_isascii(params[1][vartemp - 4]) == 0)
		|| (params[1][vartemp - 3] != '.' &&
		params[1][vartemp - 2] != 'r' && params[1][vartemp - 1] != 't'))
	{
		return (programm_stop(1));
	}
	return (0);
}

int	shut_program_w(t_arguments *parametr)
{
	int	i;

	i = 0;
	sanitazer_programm(parametr);
	exit(i);
	return (i);
}
