/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:29:28 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/31 13:30:15 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_wordlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '>' && str[i] != '<')
		i++;
	return (i);
}