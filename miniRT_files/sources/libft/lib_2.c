#include "minirt.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list_n;

	list_n = NULL;
	list_n = (t_list *)malloc(sizeof(t_list));
	if (!(list_n))
	{
		return (NULL);
	}
	list_n->again = NULL;
	list_n->content = content;
	return (list_n);
}

t_list	*ft_lstlast(t_list *list_n)
{
	while (list_n && list_n->again != NULL)
	{
		list_n = list_n->again;
	}
	return (list_n);
}

int	ft_lstsize(t_list *list_n)
{
	int		i;
	t_list	*vartemp;

	i = 0;
	vartemp = list_n;
	if (!list_n)
	{
		return (i);
	}
	while (vartemp)
	{
		i++;
		vartemp = vartemp->again;
	}
	return (i);
}

int	sanitazer_gnl(char *line, int i)
{
	if (line)
	{
		free(line);
	}
	return (i);
}

int	ft_lstadd_back(t_list **dr, t_list *list_n)
{
	t_list	*posled;

	if (!list_n)
	{
		return (0);
	}
	if (!*dr)
	{
		*dr = list_n;
		list_n->again = NULL;
	}
	if (dr && *dr)
	{
		posled = ft_lstlast(*dr);
		posled->again = list_n;
		list_n->again = NULL;
	}
	return (1);
}
