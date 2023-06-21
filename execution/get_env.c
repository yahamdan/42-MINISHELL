/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: werrahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:05:01 by werrahma          #+#    #+#             */
/*   Updated: 2023/06/20 18:05:22 by werrahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lst_size(t_env *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

char	**get_env(t_env *env)
{
	char	**c_env;
	char	*tmp;
	int		i;

	i = 0;
	c_env = malloc(sizeof(char **) * (lst_size(env) + 1));
	while (env)
	{
		c_env[i] = ft_strjoin(env->key, "=");
		tmp = c_env[i];
		if (env->value)
		{
			c_env[i] = ft_strjoin(c_env[i], env->value);
			free(tmp);
		}
		env = env->next;
		i++;
	}
	c_env[i] = NULL;
	return (c_env);
}
