#include "minirt.h"

t_shut	cy_cross(t_ortv *start_o, t_ortv *route, void *showing,
		float pred_f[2])
{
	t_shut	cl;
	t_cy	*cy;

	cy = showing;
	z_start(&cl);
	if (pred_f[1] == 1)
	{
		cl.t = 1;
	}
	if (inf_gt(cy, start_o, route) == INFINITY)
	{
		return (cl);
	}
	cy_i_3(cy, cy->t);
	cl.t = cy_i_1(cy->t, pred_f);
	if (!cl.t)
		return (cl);
	cy_i_2(&cl, cy, start_o, route);
	return (cl);
}

void	sq_new_2(t_sq *obj, t_tr *f_obj)
{
	f_obj->c2 = ortv_ml_vn(obj->freed_r, (-1) * obj->len);
	f_obj->c2 = ortv_add(f_obj->c2, obj->core);
	f_obj->c1 = ortv_ml_vn(obj->freed_r, obj->len);
	f_obj->c1 = ortv_add(f_obj->c1, obj->core);
	obj->e = ortv_ml_vn(obj->freed_l, (-1) * obj->len);
	obj->e = ortv_add(obj->e, obj->core);
	obj->d = ortv_ml_vn(obj->freed_l, obj->len);
	obj->d = ortv_add(obj->d, obj->core);
}

float	cy_i_1(float *i, float *pred_f)
{
	if ((i[0] <= pred_f[1]) && (i[0] >= pred_f[0]))
	{
		if ((i[1] <= pred_f[1]) && (i[1] >= pred_f[0]))
		{
			if (i[1] > i[0])
			{
				return (i[0]);
			}
			else
				return (i[1]);
		}
		return (i[0]);
	}
	else if ((i[1] <= pred_f[1]) && (i[1] >= pred_f[0]))
	{
		return (i[1]);
	}
	else if (1 == pred_f[1])
		return (1);
	else
		return (INFINITY);
}

t_ortv	ortv_sub(t_ortv ortv_1, t_ortv ortv_2)
{
	t_ortv	guide_ret;

	guide_ret = ortv_new(ortv_1.x - ortv_2.x,
			ortv_1.y - ortv_2.y, ortv_1.z - ortv_2.z);
	return (guide_ret);
}

t_shut	sq_intersect(t_ortv *start_o, t_ortv *route, void *showing,
	float pred_f[2])
{
	t_shut	sht;
	t_sq	*obj;
	t_tr	f_obj;

	obj = showing;
	obj->per_l_n = ortv_perp_n(obj->per_l_n);
	if (!(obj->per_l_n.x == 0 && (obj->per_l_n.y == -1 || obj->per_l_n.y == 1)
			&& obj->per_l_n.z == 0))
		obj->up = ortv_new(0, 1, 0);
	else if (obj->per_l_n.z == 0 && obj->per_l_n.x == 0 && obj->per_l_n.y == 1)
		obj->up = ortv_new(0, 0, -1);
	else if (obj->per_l_n.x == 0 && obj->per_l_n.y == -1 && obj->per_l_n.z == 0)
		obj->up = ortv_new(0, 0, 1);
	obj->freed_r = ortv_cr_pr(obj->up, obj->per_l_n);
	obj->freed_l = ortv_cr_pr(obj->freed_r, obj->per_l_n);
	sq_new_2(obj, &f_obj);
	f_obj.c3 = obj->d;
	f_obj.tone = obj->tone;
	sht = tr_cross(start_o, route, &f_obj, pred_f);
	if (sht.t == INFINITY)
	{
		f_obj.c3 = obj->e;
		sht = tr_cross(start_o, route, &f_obj, pred_f);
	}
	return (sht);
}
