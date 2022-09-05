/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:08:05 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/25 14:11:53 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_splitdup(char *env, int j)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (0);
	while (i < j && env[i])
	{
		str[i] = env[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
