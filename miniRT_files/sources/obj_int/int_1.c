#include "minirt.h"

t_shut	tr_cross(t_ortv *start_o, t_ortv *route, void *showing, float pred_f[2])
{
	t_trpoint	tp;
	t_n			n;
	t_shut		shut;

	z_start(&shut);
	tr_cross_1(route, showing, &tp);
	if (fabs(tp.m) < 0.00000001)
	{
		return (shut);
	}
	tr_cross_2(&tp, showing, start_o);
	if (tp.a > 1 || tp.a < 0)
	{
		return (shut);
	}
	tp.tortv = ortv_cr_pr(tp.tortv, tp.v1);
	tp.b = ortv_depv(*route, tp.tortv) * tp.c;
	if (tp.a + tp.b > 1 || tp.b < 0)
	{
		return (shut);
	}
	tr_cross_4(start_o, route, pred_f, &n);
	tr_cross_3(showing, tp, &shut, &n);
	return (shut);
}

void	tr_cross_4(t_ortv *start_o, t_ortv *route, float pred_f[2], t_n *n)
{
	n->route = route;
	n->pred_f1 = pred_f[1];
	n->pred_f0 = pred_f[0];
	n->start_o = start_o;
}

void	tr_cross_1(t_ortv *route, void *showing, t_trpoint *tp)
{
	tp->v1 = ortv_sub(((t_tr *)showing)->c2,
			((t_tr *)showing)->c1);
	tp->v2 = ortv_sub(((t_tr *)showing)->c3,
			((t_tr *)showing)->c1);
	tp->ortv = ortv_cr_pr(*route, tp->v2);
	tp->m = ortv_depv(tp->v1, tp->ortv);
}

void	tr_cross_2(t_trpoint *tp, void *showing, t_ortv *start_o)
{
	tp->c = 1.0 / tp->m;
	tp->tortv = ortv_sub(*start_o, ((t_tr *)showing)->c1);
	tp->a = ortv_depv(tp->tortv, tp->ortv) * tp->c;
}

void	tr_cross_3(void *showing, t_trpoint tp, t_shut *shut, t_n *n)
{
	tp.t = ortv_depv(tp.v2, tp.tortv) * tp.c;
	if (tp.t < n->pred_f1 && tp.t > n->pred_f0)
	{
		shut->t = tp.t;
		if (n->pred_f1 == INFINITY)
		{
			shut->tone_object = ((t_tr *)showing)->tone;
			shut->start_d = ortv_ml_vn(*n->route, tp.t);
			shut->start_d = ortv_add(shut->start_d, *n->start_o);
			shut->per_l_n = ortv_cr_pr(tp.v1, tp.v2);
			shut->per_l_n = ortv_perp_n(shut->per_l_n);
			pl_cr_1_i_n(&shut->per_l_n, shut->start_d, n->start_o);
		}
	}
}
