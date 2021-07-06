#include "minirt.h"

float	inf_gt(t_cy *cy, t_ortv *start_o, t_ortv *route)
{
	t_ortv	cy_go_c;

	cy_go_c = ortv_sub(*start_o, cy->core);
	cy->route = ortv_perp_n(cy->route);
	cy->a = ortv_depv(*route, *route) - pow(ortv_depv(*route, cy->route), 2);
	cy->b = (ortv_depv(*route, cy_go_c) - ortv_depv(*route, cy->route)
			* ortv_depv(cy_go_c, cy->route)) * 2;
	cy->c = ortv_depv(cy_go_c, cy_go_c) - pow(ortv_depv(cy_go_c, cy->route), 2)
		- (cy->diometr * cy->diometr) * (1.0 / 4.0);
	cy->cy_dsc = (cy->b * cy->b) - (2 * cy->a * cy->c * 2);
	if (cy->cy_dsc < -0.0000001)
	{
		return (INFINITY);
	}
	cy->t[0] = (-cy->b - sqrt(cy->cy_dsc)) / (cy->a * 2);
	cy->t[1] = (-cy->b + sqrt(cy->cy_dsc)) / (cy->a * 2);
	cy->m[0] = ortv_depv(*route, cy->route) * cy->t[0]
		+ ortv_depv(cy_go_c, cy->route);
	cy->m[1] = ortv_depv(*route, cy->route) * cy->t[1]
		+ ortv_depv(cy_go_c, cy->route);
	return (0);
}

t_ortv	ortv_add(t_ortv ortv1, t_ortv ortv2)
{
	t_ortv	guide_ret;

	guide_ret.y = ortv1.y + ortv2.y;
	guide_ret.x = ortv1.x + ortv2.x;
	guide_ret.z = ortv1.z + ortv2.z;
	return (guide_ret);
}

void	cy_i_2(t_shut *cl, t_cy *cy, t_ortv *start_o, t_ortv *route)
{
	cl->tone_object = cy->tone;
	cl->start_d = ortv_ml_vn(*route, cl->t);
	cl->start_d = ortv_add(cl->start_d, *start_o);
	cl->per_l_n = cy_i_4(cy->m, &cl->start_d,
			&cy->core, &cy->route);
	pl_cr_1_i_n(&cl->per_l_n, cl->start_d, start_o);
}

t_ortv	cy_i_4(float cy_mr[], t_ortv *r, t_ortv *k, t_ortv *l)
{
	t_ortv	cy_nr;
	t_ortv	cy_vr;
	float	i;

	i = cy_mr[0];
	if (1 == cy_mr[2])
	{
		i = cy_mr[1];
	}
	cy_vr = ortv_ml_vn(*l, i);
	cy_nr = ortv_sub(*r, *k);
	cy_nr = ortv_sub(cy_nr, cy_vr);
	cy_nr = ortv_perp_n(cy_nr);
	return (cy_nr);
}

void	cy_i_3(t_cy *cy, float *i)
{
	if (cy->m[0] > cy->geo_h || cy->m[0] < -0.0000001)
	{
		i[0] = INFINITY;
	}
	if ((cy->geo_h < cy->m[1]) || (-0.0000001 > cy->m[1]))
	{
		i[1] = INFINITY;
	}
}
