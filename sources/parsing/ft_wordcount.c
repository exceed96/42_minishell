/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:49:05 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/25 15:58:21 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_wordcount(char *env, char *set)
{
	int		count;
	char	c;

	count = 1;
	c = '\0';
	while (*env)
	{
		if (c == '\0' && (*env == '\'' || *env == '\"'))
			c = *env;
		else if (c == *env)
			c = '\0';
		if (ft_is_set(*env, set) && c == '\0' && ft_strlen(env + 1) > 0)
			count += 1;
		env++;
	}
	return (count);
}
