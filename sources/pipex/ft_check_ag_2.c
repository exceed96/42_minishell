/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ag_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:05:02 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/03 13:07:13 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_check_ag_2(char **senv, char *tmp, int i)
{
	char	**str;
	char	*str2;

	str = ft_split(senv[i] + 5, ':');
	i = 0;
	while (str[i])
	{
		str2 = ft_strjoin(str[i], tmp);
		if (!access(str2, X_OK))
		{
			i = -1;
			while (str[++i])
				free(str[i]);
			free(str);
			return (str2);
		}
		i++;
	}
	free(str);
	return (0);
}
