#include "minirt.h"

int	reali_simvol(char c)
{
	int		jndex;
	char	simvol[6];

	jndex = 0;
	simvol[0] = ' ';
	simvol[1] = '\t';
	simvol[2] = '\n';
	simvol[3] = '\v';
	simvol[4] = '\r';
	simvol[5] = '\f';
	while (6 > jndex)
	{
		if (simvol[jndex] == c)
		{
			return (1);
		}
		jndex++;
	}
	return (0);
}

float	ortv_len(t_ortv ortv)
{
	float	guide_ret;

	guide_ret = sqrt((ortv.x * ortv.x) + (ortv.y * ortv.y) + (ortv.z * ortv.z));
	return (guide_ret);
}

float	ft_atof(char *f)
{
	float	p1;
	char	*k;
	float	p2;
	float	v;
	float	v_n;

	k = ft_strchr(f, '.');
	p2 = 0;
	p1 = (float)ft_atoi(f);
	if (k++)
	{
		p2 = (float)ft_atoi(k);
		while (*k <= 57 && *k++ >= 48)
			p2 = p2 / (float)10;
	}
	v_n = (p2 + (fabs(p1) * (-1.0)));
	v = p1 + p2;
	if (p1 < 0)
	{
		return (v_n);
	}
	return (v);
}

int	ft_atoi(char *c)
{
	long	chisl;
	long	in;
	long	jndex;

	in = 1;
	jndex = 0;
	chisl = 0;
	while (reali_simvol(c[jndex]))
	{
		jndex++;
	}
	if ((c[jndex] == '-') || (c[jndex] == '+'))
	{
		if (c[jndex] == '-')
			in = in * (-1);
		jndex++;
	}
	while (c[jndex] && (c[jndex] <= '9') && (c[jndex] >= '0'))
	{
		chisl = chisl * 10;
		chisl = chisl + (int)c[jndex] - '0';
		jndex++;
	}
	return (in * chisl);
}

int	ft_isascii(int sim)
{
	if (sim >= 0 && sim < 128)
	{
		return (1);
	}
	return (0);
}
