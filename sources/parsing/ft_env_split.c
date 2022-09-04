/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:02:30 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 17:51:03 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_env_split(char *env, char c)
{
	char	set[2];
	char	**str;
	int		i;
	int		j;
	int		size;

	set[0] = c;
	set[1] = '\0';
	i = 0;
	size = ft_wordcount(env, set);
	str = malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (0);
	while (i < size)
	{
		while (ft_is_set(*env, set))
			env++;
		j = ft_wordlen(env, set);
		str[i] = ft_splitdup(env, j);
		env += j;
		i++;
	}
	str[size] = 0;
	return (str);
}
