#include "minirt.h"

char	*ft_strchr(const char *str, int ch)
{
	char	*s;

	s = (char *)str;
	while (*s)
	{
		if (*s == (char)ch)
			return (s);
		s++;
	}
	if (ch == 0)
		return (s);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!s1 | !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(char *str1, char *str2, size_t num)
{
	size_t	index;

	index = 0;
	while ((*str1 == *str2) && *str1 && (index < num))
	{
		str1++;
		str2++;
		index++;
	}
	if (index == num)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

char	*ft_strdup(const char *a)
{
	int		jndex;
	char	*ret;

	if (!a)
	{
		return ((char *)a);
	}
	ret = (char *)malloc(sizeof(char) * (ft_strlen(a) + 1));
	if (!ret)
	{
		return (NULL);
	}
	jndex = 0;
	while (a[jndex] != '\0')
	{
		ret[jndex] = a[jndex];
		jndex = jndex + 1;
	}
	ret[jndex] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char		**res;
	char		*stark;
	char		*e;
	size_t		k;

	if (!s)
		return (NULL);
	res = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	e = (char *)s;
	k = 0;
	while (k < ft_count_words(s, c))
	{
		stark = e;
		ft_setworld(&stark, &e, c);
		res[k] = (char *)malloc(e - stark + sizeof(char));
		if (!res)
			return (ft_freemem(res, k));
		ft_memmove(res[k], stark, (e - stark));
		res[k][(e - stark) / sizeof(char)] = 0;
		k++;
	}
	res[k] = NULL;
	return (res);
}
