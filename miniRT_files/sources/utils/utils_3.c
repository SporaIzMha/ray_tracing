#include "minirt.h"

int	save_3(t_showing *tch, int axis_x, int axis_y)
{
	int		bit;
	char	*fget;

	bit = 8;
	fget = (tch->side_r * axis_y + (tch->p_screen / bit)
			* axis_x) + tch->supscrip;
	return (*(unsigned int *)fget);
}

int	save_1(char *save)
{
	int		index;
	char	*s;

	index = 0;
	s = "--save";
	while ('\0' != save[index])
	{
		index++;
	}
	if (6 > index)
	{
		return (0);
	}
	index = index - 6;
	while (save[index++] == *s++)
		if (('\0' == save[index]) && ('\0' == *s))
			return (1);
	return (0);
}

void	save_5(t_showing *tch, int desc, int param)
{
	int		axis_x;
	int		axis_y;
	int		i;
	int		proportions_x;
	int		tone;

	axis_y = tch->wall_y - 1;
	proportions_x = param;
	tone = 0;
	axis_x = 0;
	i = 0;
	while (0 <= axis_y)
	{
		while (proportions_x > axis_x)
		{
			tone = save_3(tch, axis_x, axis_y);
			axis_x++;
			write(desc, &tone, 3);
		}
		axis_x = i;
		axis_y--;
	}
}

t_array_map	look_at(t_look *looking)
{
	t_ortv		vartemp;
	t_array_map	array_map;

	vartemp = ortv_new(0, 1, 0);
	array_map.ahead = looking->route;
	array_map.start_o = looking->start_o;
	array_map.ahead = ortv_perp_n(array_map.ahead);
	if (!((array_map.ahead.y == 1 || array_map.ahead.y == -1)
			&& array_map.ahead.x == 0 && array_map.ahead.z == 0))
	{
		vartemp = ortv_new(0, 1, 0);
	}
	else if (array_map.ahead.z == 0 && array_map.ahead.y
		== 1 && array_map.ahead.x == 0)
		vartemp = ortv_new(0, 0, -1);
	else if (array_map.ahead.z == 0 && array_map.ahead.y
		== -1 && array_map.ahead.x == 0)
	{
		vartemp = ortv_new(0, 0, 1);
	}
	array_map.freed_r = ortv_cr_pr(vartemp, array_map.ahead);
	array_map.freed_r = ortv_perp_n(array_map.freed_r);
	array_map.up = ortv_cr_pr(array_map.ahead, array_map.freed_r);
	array_map.up = ortv_perp_n(array_map.up);
	return (array_map);
}

void	save_2(t_showing *tch)
{
	unsigned char	massif_screen[54];
	int				desc;
	int				index_m;
	int				proportions;
	int				result;

	proportions = 4;
	index_m = 0;
	result = tch->wall_x;
	if (tch->wall_x % proportions)
		result = tch->wall_x - (tch->wall_x % proportions);
	proportions = result * tch->wall_y + 54;
	desc = open("./screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	while (index_m < 54)
		massif_screen[index_m++] = (unsigned char)0;
	save_4(massif_screen, proportions, tch, result);
	write(desc, massif_screen, 54);
	save_5(tch, desc, result);
	close(desc);
	exit(0);
}
