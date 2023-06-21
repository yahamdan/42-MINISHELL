/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:13:22 by yahamdan          #+#    #+#             */
/*   Updated: 2023/06/21 16:12:19 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../execution/minishell.h"

void	ft_lstadd_backp(t_tokens **lst, t_tokens *new)
{
	t_tokens	*tmp;

	tmp = ft_lstlastp(*lst);
	if (!lst || !new)
		return ;
	if (*lst == NULL )
	{
		(*lst) = new;
		new->perv = NULL;
		return ;
	}	
	else
		ft_lstlastp(*lst)->next = new;
	new->perv = tmp;
}

t_tokens	*ft_lstnewp(char *content)
{
	t_tokens	*lst;

	lst = malloc(sizeof(t_tokens));
	if (!lst)
		return (NULL);
	lst->cont = content;
	lst->qh = 0;
	lst->emg = 0;
	lst->next = NULL;
	lst->perv = NULL;
	return (lst);
}

t_tokens	*ft_lstlastp(t_tokens *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

char	*ft_chrjoin(char *dst, char c)
{
	char	*p;
	int		i;

	p = NULL;
	if (!dst && !c)
		return (NULL);
	if (!dst)
	{
		p = malloc(2);
		p[0] = c;
		p[1] = '\0';
		return (p);
	}
	p = ft_calloc((ft_strlen(dst) + 2), sizeof(char));
	if (!p)
		return (0);
	i = -1;
	while (dst[++i])
		p[i] = dst[i];
	p[i++] = c;
	p[i] = '\0';
	free(dst);
	return (p);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*p;

	i = 0;
	len = ft_strlen(s1);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
