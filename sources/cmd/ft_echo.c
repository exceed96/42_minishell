/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:34:00 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/05 14:33:52 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(char **ag, int fd)
{
	int	i;
	int	j;
	int	c;
	int	temp;

	i = 1;
	j = 0;
	c = 1;
	while (ag[i] && c)
	{
		if (!ft_echo_n(ag, i, j))
			c = 0;
		else
			i++;
	}
	temp = i;
	while (ag[i])
	{
		write(fd, ag[i], ft_strlen(ag[i]));
		if (ag[++i])
			write(fd, " ", 1);
	}
	if (temp == 1)
		write(fd, "\n", 1);
	return (1);
}
