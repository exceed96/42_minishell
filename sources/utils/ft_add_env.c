/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:03:47 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 17:12:53 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_add_env(char *ag)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (ag[i])
	{
		if (!str && ag[i] == '=')
		{
			str = ft_strndup(ag, i++);
			str = ft_strnjoin(str, "=", 1);
			str = ft_strnjoin(str, ag + i, ft_strlen(ag + i));
			i = ft_strlen(ag);
		}
		if (ag[i])
			i++;
	}
	if (!str)
	{
		str = ft_strdup(ag);
		str = ft_strnjoin(str, "=", 1);
	}
	return (str);
}
