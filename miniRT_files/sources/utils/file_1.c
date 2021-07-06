#include "minirt.h"

void	zeroing(void *ff, size_t i)
{
	unsigned char	*sim;
	size_t			jndex;

	sim = (unsigned char *)ff;
	jndex = 0;
	while (jndex < i)
		sim[jndex++] = '\0';
}

t_ortv	ortv_perp_n(t_ortv ortv)
{
	float	lingth;

	lingth = ortv_len(ortv);
	ortv.y = ortv.y / lingth;
	ortv.x = ortv.x / lingth;
	ortv.z = ortv.z / lingth;
	return (ortv);
}

int	main(int argc, char *argv[])
{
	t_showing		picture;
	t_locale		locale;
	t_arguments		arguments;

	check_valid_imput(argc);
	programm_check(argc, argv);
	zeroing(&arguments, sizeof(t_arguments));
	zeroing(&picture, sizeof(t_showing));
	zeroing(&locale, sizeof(t_locale));
	pars_showing(argv[1], &locale);
	check_screen_size(&locale, &arguments);
	arguments.libr = mlx_init();
	arguments.win = mlx_new_window(arguments.libr,
			locale.geo_wd, locale.geo_h, "Spora_Iz_Mha");
	func_rt_coord(arguments.libr, &locale, &picture);
	arguments.okno = &picture;
	if ((3 == argc) && (save_1(argv[2])))
	{
		save_2(&picture);
	}
	else if (3 == argc)
		programm_stop(2);
	if (2 == argc)
		my_mlx_i_t_w(&arguments, &picture, &locale);
	return (0);
}

t_ortv	ortv_cr_pr(t_ortv ortv1, t_ortv ortv2)
{
	t_ortv	guide_ret;

	guide_ret.y = ortv1.z * ortv2.x - ortv1.x * ortv2.z;
	guide_ret.x = ortv1.y * ortv2.z - ortv1.z * ortv2.y;
	guide_ret.z = ortv1.x * ortv2.y - ortv1.y * ortv2.x;
	return (guide_ret);
}

t_ortv	ortv_ml_vn(t_ortv ortv, float i)
{
	t_ortv	guide_ret;

	guide_ret.y = ortv.y * i;
	guide_ret.x = ortv.x * i;
	guide_ret.z = ortv.z * i;
	return (guide_ret);
}
