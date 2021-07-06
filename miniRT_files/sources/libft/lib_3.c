#include "minirt.h"

void	*ft_freemem(char **r, size_t i)
{
	while (i > 0)
	{
		free(r[i - 1]);
		i--;
	}
	free(r);
	return (NULL);
}

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (d < s)
	{
		while (num--)
			*d++ = *s++;
	}
	else
	{
		d = d + num;
		s = s + num;
		while (num--)
			*--d = *--s;
	}
	return (dst);
}

int	get_next_line(int i, char **str_1)
{
	char		*j;
	int			rd;
	static char	*str;
	int			len;

	rd = 0;
	*str_1 = NULL;
	if (i < 0 || !str_1 || read(i, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (-1);
	rd = perenos_ch(&str, str_1);
	if (rd)
		return (rd);
	j = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!j)
		return (-1);
	len = gnl_ysl(&j, i, &str, str_1);
	if (len)
		return (len);
	if ((!str))
		*str_1 = ft_strdup("");
	else
		*str_1 = ft_strdup(str);
	sanitazer_gnl(str, 0);
	str = NULL;
	return (sanitazer_gnl(j, 0));
}

int	ft_strlen(const char *str1)
{
	int	jndex;

	jndex = 0;
	if (!str1)
	{
		return (jndex);
	}
	while (str1[jndex] != '\0')
	{
		jndex++;
	}
	return (jndex);
}

size_t	ft_count_words(char const *s, char c)
{
	size_t		r;
	int			i;

	r = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			r++;
		i++;
	}
	return (r);
}
