/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:04:02 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/25 15:59:00 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_wordlen(char *env, char *set)
{
	int		count;
	char	c;

	count = 0;
	c = '\0';
	while (env[count])
	{
		if (c == '\0' && (env[count] == '\'' || env[count] == '\"'))
			c = env[count];
		else if (c == env[count])
			c = '\0';
		if (c == '\0' && ft_is_set(env[count], set))
			return (count);
		count++;
	}
	return (count);
}
