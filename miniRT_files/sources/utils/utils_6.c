#include "minirt.h"

t_tone	tone_5(float fl, t_tone *tone)
{
	t_tone	params;

	params.g = tone->g * fl;
	params.r = tone->r * fl;
	params.b = tone->b * fl;
	return (params);
}

t_tone	tone_4(t_tone *tone, t_tone *tone1)
{
	t_tone	params;

	params.g = tone->g * (tone1->g / 255.);
	params.r = tone->r * (tone1->r / 255.);
	params.b = tone->b * (tone1->b / 255.);
	return (params);
}

t_tone	tone_3(t_tone *tone, t_tone *tone1)
{
	t_tone	params;

	params.g = tone->g + tone1->g;
	params.r = tone->r + tone1->r;
	params.b = tone->b + tone1->b;
	return (params);
}

int	tone_2(t_tone *tone)
{
	int	params;
	int	i;

	i = 255;
	if (i < tone->r)
	{
		tone->r = i;
	}
	if (i < tone->g)
	{
		tone->g = i;
	}
	if (i < tone->b)
	{
		tone->b = i;
	}
	i++;
	params = tone->b + (i * tone->r * i) + (i * tone->g);
	return (params);
}

int	tone_1(t_ortv *route, t_locale *locale)
{
	float	pred_f[2];
	t_shut	shut;

	pred_f[1] = INFINITY;
	pred_f[0] = 1;
	z_start(&shut);
	shut = color_1(&locale->camers->start_o, route, locale, pred_f);
	if (INFINITY == shut.t)
	{
		return (0);
	}
	func_rt_tone_camers(&shut, route, locale);
	return (tone_2(&shut.tone_object));
}
