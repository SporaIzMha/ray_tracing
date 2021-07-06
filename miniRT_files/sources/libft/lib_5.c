#include "minirt.h"

char	*gnl_join(char *str_, char *str)
{
	int		index;
	char	*ret;

	index = 0;
	if (!str_ && !str)
	{
		return (NULL);
	}
	ret = (char *)malloc((ft_strlen(str_) + ft_strlen(str) + 1) * sizeof(char));
	if (!(ret))
		return (NULL);
	if (str_)
	{
		while (str_[index] != '\0')
		{
			ret[index] = str_[index];
			index = index + 1;
		}
	}
	ft_strjoin_pr(str, &ret[index]);
	return (ret);
}

void	ft_setworld(char **stark, char **e, char c)
{
	while (**stark == c && **stark != 0)
		(*stark)++;
	*e = *stark;
	while (**e != c && **e != 0)
		(*e)++;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		len_s;

	if (!s)
		return (NULL);
	i = 0;
	len_s = ft_strlen(s);
	if (len_s < start)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i + start];
	}
	str[i] = '\0';
	return (str);
}

void	ft_strjoin_pr(char *str_1, char *str_2)
{
	int		jndex;
	int		index;

	jndex = 0;
	index = 0;
	while (str_1[jndex] != '\0')
		str_2[index++] = str_1[jndex++];
	str_2[index] = '\0';
}

int	perenos_ch(char **str1, char **str2)
{
	char	*chr;
	char	*vartemp;

	vartemp = *str1;
	chr = NULL;
	if (*str1)
	{
		chr = ft_strchr(*str1, '\n');
		if (chr)
		{
			chr[0] = '\0';
			*str2 = ft_strdup(*str1);
			if (!*str2)
			{
				return (-1);
			}
			chr++;
			*str1 = ft_strdup(chr);
			if (!*str1)
				return (-1);
			return (sanitazer_gnl(vartemp, 1));
		}
	}
	return (0);
}
