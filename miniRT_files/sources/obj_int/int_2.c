#include "minirt.h"

t_shut	pl_cross(t_ortv *start_o, t_ortv *route, void *showing, float pred_f[2])
{
	float	ol;
	t_ortv	f_c;
	t_pl	*obj;
	t_shut	f;

	obj = showing;
	z_start(&f);
	obj->per_l_n = ortv_perp_n(obj->per_l_n);
	f_c = ortv_sub(*start_o, obj->core);
	if (ortv_depv(*route, obj->per_l_n) == 0)
		return (f);
	ol = ortv_depv(f_c, obj->per_l_n) * (-1) / ortv_depv(*route, obj->per_l_n);
	if (ol > pred_f[0] && ol < pred_f[1])
	{
		f.t = ol;
		if (INFINITY == pred_f[1])
		{
			f.tone_object = obj->tone;
			f.start_d = ortv_ml_vn(*route, ol);
			f.start_d = ortv_add(f.start_d, *start_o);
			f.per_l_n = obj->per_l_n;
			pl_cr_1_i_n(&f.per_l_n, f.start_d, start_o);
		}
	}
	return (f);
}

t_shut	sp_cross(t_ortv *start_o, t_ortv *route, void *showing, float kk[2])
{
	t_shut	f;
	t_sp	*o;

	o = showing;
	z_start(&f);
	f.per_l_n = ortv_perp_n(*route);
	o->oc = ortv_sub(*start_o, o->core);
	o->bch.x = ortv_depv(o->oc, f.per_l_n);
	o->bch.y = ortv_depv(o->oc, o->oc) - o->diometr * (1.0 / 4.0) * o->diometr;
	o->bch.z = o->bch.x * o->bch.x - o->bch.y;
	if (0 > o->bch.z)
		return (f);
	o->bch.z = sqrt(o->bch.z);
	o->t[0] = (o->bch.x + o->bch.z) * (-1);
	o->t[1] = (o->bch.x * (-1)) + o->bch.z;
	if (1 == kk[1])
	{
		o->t[0] = o->t[0] / ortv_len(*route);
		o->t[1] = o->t[1] / ortv_len(*route);
	}
	if (o->t[0] < o->t[1] && o->t[0] > 0 && o->t[0] > kk[0] && o->t[0] < kk[1])
		sp_cross_2(&f, o->t[0], o, start_o);
	else if ((o->t[1] < kk[1]) && (o->t[1] > 0) && (o->t[1] > kk[0]))
		sp_cross_2(&f, o->t[1], o, start_o);
	return (f);
}

void	sp_cross_2(t_shut *f, float ol, t_sp *obj, t_ortv *start_o)
{
	t_ortv	route;

	route = f->per_l_n;
	f->t = ol;
	f->tone_object = obj->tone;
	f->start_d = ortv_ml_vn(route, f->t);
	f->start_d = ortv_add(f->start_d, *start_o);
	f->per_l_n = ortv_sub(f->start_d, obj->core);
	f->per_l_n = ortv_perp_n(f->per_l_n);
}

t_ortv	ortv_new(float axis_x, float axis_y, float axis_z)
{
	t_ortv	guide_ret;

	guide_ret.y = axis_y;
	guide_ret.x = axis_x;
	guide_ret.z = axis_z;
	return (guide_ret);
}

void	pl_cr_1_i_n(t_ortv *perp_n, t_ortv t, t_ortv *s)
{
	float	buf;
	t_ortv	tst;

	tst = ortv_sub(*s, t);
	tst = ortv_perp_n(tst);
	buf = ortv_depv(tst, *perp_n);
	if (0 > buf)
	{
		*perp_n = ortv_ml_vn(*perp_n, -1);
	}
}
