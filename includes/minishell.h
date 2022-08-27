/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:34:31 by sangyeki          #+#    #+#             */
/*   Updated: 2022/08/27 17:07:50 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H_
# define _MINISHELL_H_

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "readline/readline.h"
# include "readline/history.h"

typedef struct s_in_out
{
	struct s_in_out	*next;
	char			*file;
	char			*heredoc;
	int				read_prev;
	int				type;
}	t_in_out;

typedef struct s_process
{
	struct s_process	*next;
	struct s_in_out		*inout;
	char				*cmd;
	char				*cmd_arg;
	int					input_fd;
	int					output_fd;
	int					type;
}	t_process;

int		g_status_number;

char	*ft_export_env(char **env);
void	ft_change_shlvl(char **env);
int		ft_shell(char **env);

char	*ft_env(char *env, char *cmd, int i, int j);
void	ft_env_state_return(char **cmd, int *i, int j);
int		ft_len_env_ws(char *str);
int		ft_len_env_wl(char *str);
char	*ft_replace(char *cmd, char *str, int i, int j);
void	ft_env_tild(char **cmd, int *i, char *env);
void	ft_quote(char *str, int i, int *c);
char	*ft_search_env(char *env, char *target);
void	ft_env_default(char **cmd, int *i, int j, char *str);
int		ft_is_set(char env, char *set);
char	*ft_readline(void);
char	*ft_splitdup(char *env, int j);
void	ft_env_digit(char **cmd, int *i, int j);
int		ft_is_tild(char *cmd, int i);
char	*ft_remove_env(char *str, int x, int y);
int		ft_wordcount(char *env, char *set);
char	**ft_env_split(char *env, char c);
int		ft_len_env_wl(char *str);
void	ft_remove_env_search(char **env, char *str, int i, int j);
int		ft_wordlen(char *env, char *set);
int		ft_env_char(char c);

char	*ft_strndup(const char *s, size_t n);
char	*ft_strnjoin(char *s1, char *s2, int n);

void	ft_sig_c(int sig);
void	ft_sig_q(int sig);
#endif
