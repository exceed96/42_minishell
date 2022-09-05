/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:02:30 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 13:41:33 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_env_split(char const *env, char c)
{
	char	set[2];
	char	**str;
	int		i;
	int		j;
	int		size;

	set[0] = c;
	set[1] = '\0';
	i = 0;
	size = ft_wordcount((char *)env, set);
	str = malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (0);
	while (i < size)
	{
		while (ft_is_set((char)*env, set))
			env++;
		j = ft_wordlen((char *)env, set);
		str[i] = ft_splitdup((char *)env, j);
		env += j;
		i++;
	}
	str[size] = 0;
	return (str);
}
