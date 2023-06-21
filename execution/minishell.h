/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahamdan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:50:53 by yahamdan          #+#    #+#             */
/*   Updated: 2023/06/21 21:54:52 by yahamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <sys/wait.h>
# include <unistd.h>

int		g_status;

typedef struct s_tokens
{
	int				type;
	char			*cont;
	int				qh;
	int				emg;
	struct s_tokens	*next;
	struct s_tokens	*perv;
}					t_tokens;

typedef struct s_mini
{
	char			**cmd;
	int				infile;
	int				outfile;
	struct s_mini	*next;
}					t_mini;

typedef struct s_pid
{
	int				pid;
	struct s_pid	*next;
}					t_pid;

typedef struct s_list
{
	char			**str;
}					t_list;

typedef struct s_env
{
	char			*key;
	char			*value;
	int				data;
	struct s_env	*next;
}					t_env;

typedef struct s_var
{
	t_env	*curent;
	t_env	*nxt;
	t_env	*tmp;
	t_env	*tmp1;
	char	*oldpwd;
	t_env	*cd_tmp;
	int		flag;
	char	*pwd;
	int		flag2;
	int		i;
	int		j;
}				t_var;

typedef struct s_pipe
{
	int				fd[2][2];
	int				strin_main;
	char			**env;
	int				f0;
	int				f1;
	int				*pid;
	int				index;
	int				size_list;
	int				stdin_m;
	int				flag;

}					t_pipe;

void		forking(t_mini *list, t_pipe *pipes, t_env **env, int flag);
void		check_open(t_mini *list);
void		check_arg(char **av, t_env **env);
int			cmp_env(char *str1, char *str2);
void		child_failure(t_mini *list, int flag, t_pipe *pipes, t_env **env);
void		colse_files(t_pipe *pipes);
int			is_string_inlist(t_env *env, char *arg);
int			status_checker(int exit_status);
int			export_monitor(t_env **env, t_env **tmp, char *av, int *cnst);
void		dup_key(char *str, t_env *lst);
void		dup_value(char *str, t_env *lst);
t_env		*fond_key(t_env *list, char *str);
void		free_env(t_env **env);
int			is_spas_instring(char *str);
void		our_free(char **arr);
char		**split_env(char *str);
char		**get_env(t_env *env);
void		copy_env(t_env **env, t_env **c_env);
void		create_env(t_env **list);
void		create_list(t_env **list, char **env);
void		ft_lstadd_back(t_env **lst, t_env *new);
t_env		*ft_lstnew(void);
t_env		*ft_lstlast(t_env *lst);
int			ft_strcmp(const char *s1, const char *s2);
int			pwd(void);
int			print_env(t_env *env);
int			our_echo(char **str);
int			our_cd(t_env *env, char *file);
int			our_unset(t_env **env, char **remove);
int			my_exit(char **av);
int			str_len(char **av);
int			our_export(t_env **env, char **av);
void		sort_list(t_env **env);
void		fill_list(t_env **list, char **env);
int			wcheck_arg(char **av, t_env **env);
void		first_child(t_mini *list, t_pipe *pipes, t_env **env);
void		second_child(t_mini *list, t_pipe *pipes, t_env **env);
void		last_child(t_mini *list, t_pipe *pipes, t_env **env);
char		*check_access(char **ps_path, char *av);
char		**pathfinder(t_env *env);
void		swap(int *a, int *b);
void		multiple_pipe(t_mini *list, t_env **env, t_pipe *pipes);
void		ft_fail(char av);
int			size_lim(char *str, char *av);
int			ft_checker(int ac, char *av);
void		pipes_monitor(t_mini *list, t_pipe *pipes, t_env **env);
int			*tab_pid(t_mini *list);
void		rl_replace_line(const char *text, int clear_undo);
int			g_statuse(t_tokens *to);	
t_tokens	*lexer_split_cmdline(char *line);
void		fill_last_list(t_tokens *token, t_env *lis, t_mini **list);
t_mini		*ft_lstlastl(t_mini *lst);
void		ft_lstadd_backl(t_mini **lst, t_mini *new);
char		*expenv(char *str, t_env *env);
t_tokens	*ft_lstnewp(char *content);
size_t		ft_strlen(const char *s);
t_tokens	*ft_lstlastp(t_tokens *lst);
char		*ft_strdup(const char *s1);
char		*ft_chrjoin(char *dst, char c);
void		*ft_calloc(size_t count, size_t size);
void		ft_lstadd_backp(t_tokens **lst, t_tokens *new);
int			lexer_openqts(char *line, int indx);
char		*get_next_line(int fd);
int			ft_strcmp(const char *s1, const char *s2);
void		open_herfiles(t_tokens *tokens, t_env *list);
void		do_expand_tokens(t_tokens **tokens, t_env *env);
int			have_builtins(char **cmd);
int			ft_lstsize(t_mini *lst);
void		ft_maxheropn(t_tokens *tokens);
void		*ft_realloc(void *ptr, size_t size);
t_mini		*ft_lstnewl(void);
void		free_tokens(t_tokens *t);
int			definetype_helper(t_tokens *toke);
t_tokens	*lexer_definetype(t_tokens *token);
void		free_tmp(char *name, t_tokens *tokens);
char		*ft_gethername(void);
char		*herexpand(char *line, char *str, int *i, t_env *env);
int			qoutesordlr(t_tokens *token);
void		handle_sig(int sig);
void		handle_signal(int sig);
void		unlink_hf(void);
void		free_li(t_mini **li);
void		init(t_pipe *pipes, t_mini *li);

# define INFILE 0
# define OUTFILE 1
# define PIPE 2
# define HEREDOC 3
# define LIMETER 4
# define ARG 5
# define INPUT 6
# define OUTPUT 7
# define APPEND 8

#endif