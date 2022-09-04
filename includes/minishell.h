/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangyeki <sangyeki@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:34:31 by sangyeki          #+#    #+#             */
/*   Updated: 2022/09/04 15:03:11 by sangyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINISHELL_H_
# define _MINISHELL_H_

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/libft.h"
# include "readline/readline.h"
# include "readline/history.h"
# include "pipex.h"

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
	char				*type;
}	t_process;

int			g_status_number;

char		*ft_export_env(char **env);
void		ft_change_shlvl(char **env);
int			ft_shell(char **env);

int			ft_check_quote(char *str);
void		ft_check_quote_cmd(char **cmd, int i, int *j, char *c);
int			ft_check_split(char *cmd, int i, int j, int pipe);
char		*ft_env(char *env, char *cmd, int i, int j);
int			ft_env_char(char c);
void		ft_env_default(char **cmd, int *i, int j, char *env);
void		ft_env_digit(char **cmd, int *i, int j);
char		**ft_env_split(char *env, char c);
void		ft_env_state_return(char **cmd, int *i, int j);
void		ft_env_tild(char **cmd, int *i, char *env);
int			ft_is_set(char env, char *set);
int			ft_is_tild(char *cmd, int i);
int			ft_len_env_wl(char *str);
int			ft_len_env_ws(char *str);
void		ft_made(int *i, char *c, char cmd);
int			ft_n_space(char *str);
void		ft_quote(char *str, int i, int *c);
int			ft_quote_len(char *str);
char		*ft_readline(void);
char		*ft_remove_env(char *str, int x, int y);
void		ft_remove_env_search(char **env, char *str, int i, int j);
char		*ft_replace(char *cmd, char *str, int i, int j);
void		ft_resolve_cmd(char *cmd, char **env, char **s_env, char *tmp);
char		*ft_search_env(char *env, char *target);
int			ft_space(char *str);
char		*ft_splitdup(char *env, int j);
int			ft_wordcount(char *env, char *set);
int			ft_wordlen(char *env, char *set);
int			ft_wordlen2(char *str);

int			ft_check_process(t_process *process);
void		ft_clean_process(t_process *process);
void		ft_clear_process(t_process *process);
t_process	*ft_create_process(int i, int j, char **cmd);
t_in_out	*ft_create_inout(void);
void		ft_direction(t_process **process, int i, int *j, char **cmd);
void		ft_first_process(t_process **process, t_process **tmp, int i);
void		ft_free(t_process **process);
void		ft_free_exec(t_data *data, int i);
void		ft_free_inout(t_in_out **inout);
void		ft_free_split(char **cmd);
int			ft_free_split_r(char **str, int r);
void		ft_heredoc_process(t_process *process, char *str);
void		ft_heredoc_process_2(t_in_out *inout, char *tmp_r, char *r_l, char *str);
int			ft_is_cmd(char *str, char *cmd);
void		ft_malloc_process(t_process **process);
int			ft_n_cmd(t_process **process, char **cmd, int i, int j);
void		ft_organize_inout(t_in_out *inout);
void		ft_organize_process(t_process *process, int i, int next, int inout);
void		ft_push(t_in_out **inout, t_in_out *new);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strnjoin(char *s1, char *s2, int n);
int			ft_strstrlen(char **str);
int			ft_structlen(t_process *process);
void		ft_update_cd(char **env);

void		ft_create_pipes(t_data *data);
void		ft_close_pipes(t_data *data);
int			ft_malloc_pipex(t_data *data, int i);
int			ft_init_pipex(t_data *data, int i);
int			ft_find_path(char **senv);
char		*ft_strsjoin(char *s1, char *s2, int n);
void		ft_perror(char *str, int state);
void		ft_fork_error(t_data *data, int code, char *str);
char		**ft_search_quote(char **str, int i, int j);
char		*ft_search_quote_2(char *cmd, int i);
char		*ft_delete_quote(char **str, int c);
char		*ft_check_ag(char *cmd, char **senv);
char		*ft_check_ag_2(char **senv, char *tmp, int i);
int			ft_run_cmd(t_process *process, char **senv, char **env);
int			ft_run_cmd_2(t_process *tmp, t_in_out *tmp2, t_process *process);
int			ft_run_cmd_3(t_process *tmp, t_in_out *tmp2, int i);
int			ft_run_cmd_4(t_data *data, t_process *tmp, char **senv, int i);
int			ft_run_cmd_5(t_process *tmp, t_data *data, int i, char **senv);
void		ft_run_cmd_6(t_data *data, t_process *tmp, char **senv, int i);
int			ft_run_cmd_7(t_data *data, t_process **tmp, char **senv, int i);
int			ft_run_cmd_8(t_data *data, t_process **tmp, char **senv, int i);
void		ft_run_cmd_9(t_data *data, t_in_out *inout);
void		ft_run_cmd_10(t_data *data, t_process **tmp, char **senv, int i);
void		ft_run_cmd_11(t_data *data, t_process *tmp, char **senv, int i);
void		ft_one_process(t_data *data, t_process *tmp, char **senv, char **str);
void		ft_pipe_process(t_data *data, t_process *tmp, char **senv, int i);
void		ft_pipe_process_2(t_data *data, t_process *tmp, char **senv, int i);
void		ft_pipe_process_3(t_data *data, t_process *tmp, char **senv, int i);
void		ft_pipe_process_4(t_data *data, t_process *tmp, char **senv, int i);
void		ft_pipe_process_5(t_data *data, t_process *tmp, char **senv, int i);
void		ft_pipe_process_6(t_data *data, t_process *tmp, char **senv, int i);
void		ft_pipe_process_7(t_data *data, t_process *tmp, char **senv, int i);
void		ft_pipe_process_8(t_data *data, t_process *tmp, char **senv, int i);
void		ft_pipe_process_9(t_data *data, t_process *tmp, char **senv, int i);
void		ft_pipe_process_10(t_data *data, t_process *tmp, char **senv, int i);
int			ft_status(t_data *data);

int			ft_built_one(int i, t_data *data, t_process *tmp, char **str);
int			ft_built_pipe_1(int i, t_data *data, t_process *tmp);
int			ft_built_pipe_2(int i, t_data *data, t_process *tmp);
int			ft_built_pipe_3(int i, t_data *data, t_process *tmp);
int			ft_cmd(char *str, char *cmd);

int			ft_cd(t_data *data, char **path, int fd);
int			ft_echo(char **ag, int fd);
int			ft_echo_n(char **ag, int i, int j);
int			ft_cmd_env(t_data *data, int fd);
int			ft_pwd(int fd);

void		ft_sig_c(int sig);
void		ft_sig_q(int sig);

#endif
