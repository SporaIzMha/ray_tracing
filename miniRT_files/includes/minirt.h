#ifndef MINIRT_H
# define MINIRT_H

# define MAX_DIST 1000000
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_ortv
{
	float		x;
	float		y;
	float		z;
}				t_ortv;

typedef struct s_look
{
	t_ortv			start_o;
	t_ortv			route;
	float			range_f;
	struct s_look	*again;
	struct s_look	*agpost;
}					t_look;

typedef struct s_tone
{
	int			r;
	int			g;
	int			b;
}				t_tone;
char			*gnl_join(char *str_, char *str);
void			ft_setworld(char **stark, char **e, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_strjoin_pr(char *str_1, char *str_2);
int				perenos_ch(char **str1, char **str2);

typedef struct s_shut
{
	float		t;
	t_ortv		start_d;
	t_tone		tone_object;
	t_ortv		per_l_n;
}				t_shut;
void			*ft_freemem(char **r, size_t i);
typedef struct s_figura
{
	t_shut		(*funksion_intr)(t_ortv *start_o, t_ortv *route,
					void *showing, float pred_f[2]);
	void		*showing;
	void		*again;
	char		vid;
}				t_figura;

typedef struct s_tons
{
	t_ortv			d_l;
	float			intensity_l;
	t_tone			tone;
	struct s_tons	*again;
	t_ortv			*l_ortv;
}					t_tons;

typedef struct s_pl
{
	t_ortv		core;
	t_ortv		per_l_n;
	t_tone		tone;
}				t_pl;

typedef struct s_cy
{
	t_ortv		core;
	t_ortv		route;
	float		diometr;
	float		geo_h;
	t_tone		tone;
	float		m[3];
	float		a;
	float		b;
	float		c;
	float		cy_dsc;
	float		t[2];
}				t_cy;

typedef struct s_tr
{
	t_ortv		c1;
	t_ortv		c2;
	t_ortv		c3;
	t_tone		tone;
}				t_tr;

typedef struct s_p_prs
{
	char		**masif;
	char		**masif1;
	char		**masif2;
	char		**masif3;
	char		**masif4;
}				t_p_prs;

typedef struct s_showing
{
	void		*okno;
	char		*supscrip;
	int			p_screen;
	int			side_r;
	int			endian;
	int			wall_x;
	int			wall_y;
}				t_showing;

typedef struct s_sp
{
	t_ortv		core;
	float		diometr;
	t_tone		tone;
	t_ortv		oc;
	t_ortv		bch;
	float		t[2];
}				t_sp;

typedef struct s_sq
{
	t_ortv		core;
	t_ortv		per_l_n;
	float		size_stor_a;
	t_tone		tone;
	t_ortv		up;
	t_ortv		freed_r;
	t_ortv		freed_l;
	t_ortv		d;
	t_ortv		e;
	float		len;
}				t_sq;

typedef struct s_locale
{
	t_look		*camers;
	t_tons		*tons;
	int			geo_wd;
	int			geo_h;
	float		intensity_l;
	t_tone		tone;
	t_figura	*figura;
	int			tons_a;
	int			cam_flag;
}				t_locale;

typedef struct s_array_map
{
	t_ortv		freed_r;
	t_ortv		ahead;
	t_ortv		start_o;
	t_ortv		up;

}				t_array_map;

typedef struct s_trpoint
{
	t_ortv		v1;
	t_ortv		v2;
	t_ortv		ortv;
	t_ortv		tortv;
	float		c;
	float		a;
	float		b;
	float		m;
	float		t;
}				t_trpoint;

typedef struct s_n
{
	t_ortv		*start_o;
	t_ortv		*route;
	void		*showing;
	float		pred_f0;
	float		pred_f1;
	float		a;
	float		b;
	float		c;
	float		m;
	t_ortv		xyz;
	t_ortv		w;
}				t_n;

typedef struct s_vplane
{
	float		geo_wd;
	float		geo_h;
	float		x_pixel;
	float		y_pixel;

}				t_vplane;

float			ortv_depv(t_ortv ortv1, t_ortv ortv2);
t_ortv			ortv_sub(t_ortv ortv1, t_ortv ortv2);
t_ortv			ortv_new(float axis_x, float axis_y,
					float axis_z);
t_ortv			ortv_ml_vn(t_ortv ortv, float i);
t_vplane		*get_vian_plane(float wedht, float geo_h, float range_f);
void			pl_cr_1_i_n(t_ortv *perp_n, t_ortv t, t_ortv *s);
void			sp_cross_2(t_shut *f, float ol, t_sp *obj, t_ortv *start_o);
void			sanitazer_locale_3(t_look *look);
void			save_5(t_showing *tch, int desc, int param);
t_shut			sp_cross(t_ortv *start_o, t_ortv *route,
					void *showing, float pred_f[2]);
t_ortv			cy_i_4(float cy_mr[], t_ortv *r, t_ortv *k, t_ortv *l);
t_ortv			multip_array_map(t_ortv *ortv, t_array_map *array_map);
void			save_4(unsigned char *massif_screen, int proportions,
					t_showing *chk, int param);
t_shut			pl_cross(t_ortv *start_o, t_ortv *route,
					void *showing, float kk[2]);
t_ortv			ortv_cr_pr(t_ortv ortv1, t_ortv ortv2);
t_ortv			ortv_add(t_ortv ortv1, t_ortv ortv2);
t_ortv			ortv_perp_n(t_ortv ortv);
float			ortv_len(t_ortv ortv);
t_shut			cy_cross(t_ortv *start_o, t_ortv *route,
					void *showing, float pred_f[2]);
t_shut			sq_intersect(t_ortv *start_o, t_ortv *route,
					void *showing, float pred_f[2]);
void			tr_cross_1(t_ortv *route, void *showing, t_trpoint *tp);
t_array_map		look_at(t_look *looking);
void			tr_cross_2(t_trpoint *tp, void *showing, t_ortv *start_o);
void			tr_cross_4(t_ortv *start_o,
					t_ortv *route, float pred_f[2], t_n *n);
void			tr_cross_3(void *showing, t_trpoint p,
					t_shut *cl, t_n *n);
void			cy_i_2(t_shut *cl, t_cy *cy, t_ortv *start_o, t_ortv *route);
t_shut			tr_cross(t_ortv *start_o, t_ortv *route,
					void *showing, float pred_f[2]);
void			func_rt_coord(void *libr, t_locale *locale, t_showing *picture);
t_ortv			func_rt_g(t_locale *locale, int axis_x, int axis_y);
void			check_valid_imput(int i);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*again;
}					t_list;

void			*ft_memccpy(void *dest, const void *src,
					int c, size_t len);
void			*ft_memmove(void *dst, const void *src, size_t num);
void			*ft_memchr(const void *masif, int c, size_t len);
char			*gnl_join(char *str_, char *str);
void			*ft_memset(void *dest, int c, size_t len);
int				ft_toupper(int c);
void			zeroing(void *ff, size_t i);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *a);
void			ft_setworld(char **stark, char **e, char c);
int				sanitazer_gnl(char *line, int i);
int				ft_lstadd_back(t_list **dr, t_list *list_n);
int				ft_lstsize(t_list *list_n);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *list_n);
float			ft_atof(char *f);
size_t			ft_count_words(char const *s, char c);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *str, char const *set);
char			*ft_itoa(int64_t n);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				get_next_line(int i, char **str_1);
void			*ft_memcpy(void *dest, const void *src, size_t len);
int				ft_memcmp(const void *s1, const void *s2, size_t len);
int				ft_strlen(const char *str1);
int				ft_isascii(int sim);
int				gnl_ysl(char **j, int i, char **str, char **str_1);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_tolower(int c);
void			ft_strjoin_pr(char *str_1, char *str_2);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				reali_simvol(char c);
char			*ft_strchr(const char *str, int ch);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(char *str1, char *str2, size_t num);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
int				ft_atoi(char *c);
int				perenos_ch(char **str1, char **str2);
typedef struct s_arguments
{
	void			*libr;
	void			*win;
	t_showing		*okno;
	t_locale		*locale;
}				t_arguments;

void			z_start(t_shut *cl);
char			programm_stop(int code);
char			programm_check(int len_line, char *params[]);
void			func_rt_coord_pixels(t_showing
					*showing, int x, int y, int tone);
void			programm_stop_2(char *line);
int				shut_program_w(t_arguments *vars);
int				shut_program_w2(int	code_klava, t_arguments *parametr);
int				save_3(t_showing *p, int x, int y);
int				save_1(char *save);
void			save_2(t_showing *tch);
void			wrk_looking(t_ortv *dot, t_look *camers);
void			wrk_cam(t_arguments *vars);
t_tone			tone_5(float n, t_tone *c);
t_tone			tone_4(t_tone *c1, t_tone *c2);
t_tone			tone_3(t_tone *c1, t_tone *c2);
void			my_mlx_i_t_w(t_arguments *arguments,
					t_showing *picture, t_locale *locale);
int				tone_2(t_tone *col);
void			per_l_ne_ch(char *str1, char *str2, char *str3);
void			check_screen_size(t_locale *locale, t_arguments *arguments);
void			sanitazer_mass(char **r);
void			sanitazer_locale(t_locale *locale);
void			sanitazer_programm(t_arguments *p);

float			ortv_depv(t_ortv ortv1, t_ortv ortv2);
t_ortv			ortv_sub(t_ortv ortv1, t_ortv ortv2);
t_ortv			ortv_new(float x, float y, float z);
t_ortv			ortv_ml_vn(t_ortv ortv, float i);
float			ortv_depv(t_ortv ortv1, t_ortv ortv2);
t_ortv			ortv_sub(t_ortv ortv1, t_ortv ortv2);
t_ortv			ortv_new(float x, float y, float z);
t_ortv			ortv_ml_vn(t_ortv ortv, float i);
t_ortv			ortv_cr_pr(t_ortv ortv1, t_ortv ortv2);
t_ortv			ortv_add(t_ortv ortv1, t_ortv ortv2);
t_ortv			ortv_perp_n(t_ortv ortv);
float			ortv_len(t_ortv ortv);
void			r_l_1(char *str, t_tons *ligh_n);
t_tone			tone_4(t_tone *c1, t_tone *c2);
void			r_cy_2(t_figura *cy, t_cy *cy_n, char **tone_cy);
void			r_tr(char *str, t_locale *locale);
float			inf_gt(t_cy *cy, t_ortv *start_o, t_ortv *route);
void			r_sp_1(t_p_prs *p, char *str);
t_tone			tone_5(float n, t_tone *c);
void			r_l_tone(t_tons *ligh_n, char **masifay);
void			r_cy_1(t_figura *vartemp, t_figura *cy, t_locale *locale);
t_tone			tone_3(t_tone *c1, t_tone *c2);

void			r_pl_1(t_figura *vartemp, t_figura *pl, t_locale *locale);

void			pars_str(char *str, t_locale *locale);
t_ortv			coord_g(char **str);
void			r_sq_3(t_figura	*vartemp, t_figura *sq, t_locale *locale);
void			r_sq_1(t_p_prs *lg, t_sq *sq_n);
t_tone			_tone_g(char **str);
void			pars_showing(char *file, t_locale *locale);
void			r_p(char *line, t_locale *locale);
void			r_c_1(char *str, t_look	*cam);
void			r_pl(char *str, t_locale *locale);
void			r_a(char *line, t_locale *locale);
void			sq_new_2(t_sq *obj, t_tr *f_obj);
void			r_tr_1(t_p_prs *lg, t_tr *tr_n);
void			r_sp(char *str, t_locale *locale);
void			r_sq(char *str, t_locale *locale);
float			color_2(t_shut cl, t_ortv *ortv_d,
					t_locale *locale, t_tons *lgt);
void			r_pl_3(t_figura *pl, t_pl *pl_n, t_p_prs p);
void			r_cy(char *str, t_locale *locale);

void			r_l_0(t_tons *vartemp, t_tons *ligh_n, t_locale *locale);
void			r_c(char *str, t_locale *locale);
void			r_tr_2(t_figura *tr, t_tr *tr_n, t_p_prs p);
void			r_c_2(t_look	*vartemp,
					t_look	*cam, t_locale *locale);
void			r_l(char *str, t_locale *locale);
void			loc_dell(char **mas, char **m_1, char **m_2);
void			cy_i_3(t_cy *cy, float *i);
void			r_l_tone(t_tons *new_tons, char **masifay);
float			cy_i_1(float *i, float *pred_f);
void			r_sp_2(t_figura *sp, t_sp *sp_n, t_p_prs p);
void			func_rt_tone_camers(t_shut *cl, t_ortv *ortv_d,
					t_locale *locale);
int				tone_1(t_ortv *route, t_locale *locale);
t_shut			cy_cross(t_ortv *start_o, t_ortv *route, void *showing,
					float pred_f[2]);
void			r_cy_3(t_cy *cy_n, t_p_prs p);
void			r_pl_2(t_p_prs *p, t_pl *pl_n, char *str);
void			r_sq_2(t_figura *sq, t_sq *sq_n, t_p_prs p);
void			r_cy_4(t_p_prs *p, t_cy *cy_n);
t_shut			color_1(t_ortv *start_o, t_ortv *ray,
					t_locale *locale, float *pred_f);
float			color_3(t_shut cl, t_ortv *l_ortv, float tons_i);
void			r_tr_3(t_figura	*vartemp, t_figura *tr, t_locale *locale);
void			r_sp_3(t_figura *vartemp, t_figura *sp, t_locale *locale);
float			color_4(t_shut cl, t_ortv *l_ortv,
					t_ortv *ortv_d, float tons_i);
void			z_start(t_shut *cl);
void			pl_cr_1_i_n(t_ortv *perp_n, t_ortv p, t_ortv *o);

#endif
